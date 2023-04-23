-- PK - 24
-- Title - Details Correction Request Report


PREPARE usrrptplan (int, date, date) AS
SELECT "accounts_user"."first_name",
       "accounts_user"."last_name",
       "activity_activitymaster"."name",
       "employees_employeeprofile"."id",
       "employees_employeeprofile"."title" AS "employee_title", , 
       "company_companydepartment"."name" AS "department_name",
       "company_companyteam"."name" AS "team_name",
       "activity_employeeactivity"."session_id",
       COUNT (DISTINCT("activities_activity"."id")), to_char("activity_activitysplit"."start_datetime" AT TIME ZONE $$timezone$$, $$format_datetime$$) AS start_datetime,
                                                     to_char("activity_activitysplit"."end_datetime" AT TIME ZONE $$timezone$$, $$format_datetime$$) AS end_datetime,
                                                     to_char(("activity_activitysplit"."total_time" || ' second')::interval, 'HH24:MI') AS total_time
FROM "activity_activitysplit"
INNER JOIN "employees_employeeprofile" ON ("activity_activitysplit"."employee_id" = "employees_employeeprofile"."id")
INNER JOIN "company_companydepartment" ON ("employees_employeeprofile"."department_id" = "company_companydepartment"."id")
INNER JOIN "company_companyteam" ON ("employees_employeeprofile"."team_id" = "company_companyteam"."id")
INNER JOIN "accounts_user" ON ("employees_employeeprofile"."user_id" = "accounts_user"."id")
INNER JOIN "activity_employeeactivity" ON ("activity_activitysplit"."employee_activity_id" = "activity_employeeactivity"."id")
INNER JOIN "activity_activitymaster" ON ("activity_employeeactivity"."activity_master_id" = "activity_activitymaster"."id")
INNER JOIN "activities_activity" ON ("activities_activity"."target_object_id" = coalesce(CAST("activity_activitysplit"."session_id" AS text), 'N/A'))
WHERE ("activity_activitysplit"."employee_id" = $$employee_id$$
       AND "activity_activitysplit"."employee_id" = "employees_employeeprofile"."id"
       AND CAST(("activity_activitysplit"."start_datetime" AT TIME ZONE $$timezone$$) AS date) >= $2
       AND CAST(("activity_activitysplit"."end_datetime" AT TIME ZONE $$timezone$$) AS date) <= $3
       AND "activities_activity"."target_content_type_id" = 46
       AND "activities_activity"."data"->'new_value'->'correction_request' IS NOT NULL
       AND "activity_activitymaster"."name" = 'Shift')
GROUP BY "accounts_user"."first_name",
         "accounts_user"."last_name",
         "employees_employeeprofile"."title",
         "activity_activitymaster"."name",
         "employees_employeeprofile"."id",
         "activity_employeeactivity"."session_id",
         "activity_activitysplit"."start_datetime",
         "activity_activitysplit"."end_datetime",
         "activity_activitysplit"."total_time"
ORDER BY $$field$$ $$order$$;

EXECUTE usrrptplan($$employee_id$$, $$start_datetime$$, $$end_datetime$$);