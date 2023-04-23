-- Pk - 8
-- Title - Meal Violation Detail


PREPARE usrrptplan (int, date, date) AS
SELECT DISTINCT "activity_activitysplit"."session_id",
                  "accounts_user"."first_name",
                   "accounts_user"."last_name",
                   "employees_employeeprofile"."title" AS "employee_title", 
                   "company_companydepartment"."name" AS "department_name",
                   "company_companyteam"."name" AS "team_name",
                   othersplits."session_id",
                   "activity_activitysplit"."start_datetime",
                   "activity_activitysplit"."end_datetime",
                   "employees_employeeprofile"."employee_id",
                   "employees_employeeprofile"."id",
                   to_char("activity_activitysplit"."start_datetime" AT TIME ZONE $$timezone$$, $$format_datetime$$) AS start_datetime,
                   CASE
                       WHEN "activity_activitysplit"."meal_delayed" = TRUE THEN to_char(othersplits."meal_start_datetime" AT TIME ZONE $$timezone$$, $$format_datetime$$)
                       ELSE ''
                   END AS meal_start_datetime,
                   CASE
                       WHEN "activity_activitysplit"."meal_delayed" = TRUE THEN to_char(othersplits."meal_end_datetime" AT TIME ZONE $$timezone$$, $$format_datetime$$)
                       ELSE ''
                   END AS meal_end_datetime,
                   to_char("activity_activitysplit"."end_datetime" AT TIME ZONE $$timezone$$, $$format_datetime$$) AS end_datetime,
                   CASE
                       WHEN "activity_activitysplit"."meal_delayed" = TRUE THEN 'Delayed Meal'
                       ELSE 'Missing Meal'
                   END AS violation_type,
                   "activity_activitysplit"."resolved_as",
                   "activity_activitysplit"."message",
                   "activity_activitysplit"."daily_timecard_id"
FROM "activity_activitysplit"
INNER JOIN "employees_employeeprofile" ON ("activity_activitysplit"."employee_id" = "employees_employeeprofile"."id")
INNER JOIN "accounts_user" ON ("employees_employeeprofile"."user_id" = "accounts_user"."id")
INNER JOIN "company_companydepartment" ON ("employees_employeeprofile"."department_id" = "company_companydepartment"."id")
INNER JOIN "company_companyteam" ON ("employees_employeeprofile"."team_id" = "company_companyteam"."id")
INNER JOIN "activity_employeeactivity" ON ("activity_activitysplit"."employee_activity_id" = "activity_employeeactivity"."id")
INNER JOIN "activity_activitymaster" ON ("activity_employeeactivity"."activity_master_id" = "activity_activitymaster"."id")
LEFT OUTER JOIN
      (
        SELECT a."session_id", s."start_datetime" as meal_start_datetime, s."end_datetime" as meal_end_datetime
        from activity_activitysplit as s
        join activity_employeeactivity as a on a."id" = s."employee_activity_id"
        join activity_activitymaster as m on m."id"=a."activity_master_id" and m.code='MEAL-PERIOD'
      ) AS othersplits ON ("activity_activitysplit"."session_id" = othersplits."session_id")
      AND ("activity_activitysplit"."start_datetime" <= othersplits."meal_start_datetime")
      AND ("activity_activitysplit"."end_datetime" >= othersplits."meal_end_datetime")
WHERE ("activity_activitysplit"."date" >= $2
       AND "activity_activitysplit"."employee_id" = $1
       AND ("activity_activitysplit"."meal_violation_count" > 0
            OR "activity_activitysplit"."meal_delayed" = TRUE)
       AND "activity_activitysplit"."date" <= $3
       AND "activity_activitymaster"."code" = 'PUNCH-IN'
       AND NOT ("activity_activitysplit"."status" = '2')
       AND "employees_employeeprofile"."company_id" = $$company_id$$
       AND (CASE
                WHEN '$$department_id$$' <> 0 THEN "employees_employeeprofile"."department_id" = $$department_id$$
                ELSE 1=1
            END)
       AND (CASE
                WHEN '$$team_id$$' <> 0 THEN "employees_employeeprofile"."team_id" = $$team_id$$
                ELSE 1=1
            END))

ORDER BY "accounts_user"."last_name" ASC, "accounts_user"."first_name" ASC, $$field$$ $$order$$;



EXECUTE usrrptplan($$employee_id$$, $$start_date$$, $$end_date$$);