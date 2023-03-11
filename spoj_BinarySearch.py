# Q1 EKO problem, Same as Book allocation, Painter partition & aggressive cows.
# topics covered - array, binary search & search space

# def binary_search(n, m, arr):
#     start = 0
#     end = max(arr)
#     mid = start + (end-start)//2
#     while(start <= end):
#         if isPossible(n, m, arr, mid):
#             print(mid)
#             ans = mid 
#             start = mid + 1
#         else:
#             end = mid - 1
#         mid = start + (end-start)//2
#     return ans
	
# def isPossible(n, m, arr, mid):
#     total_wood = 0
#     for i in arr:
#         if i > mid:
#             total_wood += (i - mid)
#             if total_wood >= m:
#                 return True
#     return False
	
# n, m = map(int, input("Enter the values of n & m, separated by space:   ").split(" "))
# arr = list(map(int, input("Enter the elements of array separated by space:  ").split(" ")))
# # print(n, m, arr)
	
# print(f"Ans: {binary_search(n, m, arr)}")

# Q2
# # PRATA SPOJ
# def binary_search(arr, p):
#     a = min(arr)
#     ans = 0
#     start = 0
#     end = ((p*((2*(a))+((p-1)*a)))//2)+ 1
#     mid = start + (end - start)//2
#     while(start <= end):
#         if isPossible(arr, p, mid):
#             ans = mid
#             end = mid - 1
#         else:
#             start = mid + 1
#         mid = start + (end - start)//2
#     return ans


# def isPossible(arr, p, mid):
#     paratas = 0
#     for cook in arr:
#         counter = 1
#         total_time = 0
#         while((total_time + (cook * counter)) <= mid):
#             total_time += (cook * counter)
#             paratas += 1
#             counter += 1
#             if (paratas == p):
#                 return True
#     return False


# t = int(input("No. of test cases:   "))
# for _ in range(t):
#     p = int(input("No. of Parats:   "))
#     arr = list(map(int, input("Elements of array:       ").split(" ")))


# Q3
# Cooking Ninjas, same as above
# Code Studio
def binary_search(rank, m):
    n = len(rank)
    a = rank[0]
    ans = -1
    start = 0
    end = ((m*((2*(a))+((m-1)*a)))//2)+ 1
    mid = start + (end - start)//2
    while(start <= end):
        if isPossible(rank, n, m, mid):
            ans = mid
            end = mid - 1
        else:
            start = mid + 1
        mid = start + (end - start)//2
    return ans
    
def isPossible(rank, n, m, mid):
    dish_count = 0
    for item in rank:
        time = 0
        counter = 1
        while(time+((item * counter)) <= mid):
            time += (item * counter)
            dish_count += 1
            counter += 1
            if(dish_count == m):
                return True
    return False
    
m = 11
rank = [1, 2, 3, 4]
print(binary_search(rank, m))







