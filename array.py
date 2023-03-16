# # Q1 Reversing an array.

# arr = [1, 2, 3, 4, 5, 6]

# swap = 0
# for i in range(len(arr) // 2):
#     swap = arr[i]
#     arr[i] = arr[len(arr) - i - 1]
#     arr[len(arr) - i - 1] = swap

# print(arr)


# # Q2 Swaping with adjacent element in an array.

# swap = 0
# for i in range(0, len(arr), 2):
#     if (i + 1) < len(arr):
#         swap = arr[i]
#         arr[i] = arr[i + 1]
#         arr[i + 1] = swap

# print(arr)


# # Q3 Find unique element in an array.

# unique_element_arr = []
# for i in range(len(arr)):
#     match_count = 0
#     for j in range(len(arr)):
#         if arr[i] == arr[j] and match_count <= 1:
#             match_count += 1
#     if match_count < 2:
#         unique_element_arr.append(arr[i])

# print(unique_element_arr)

# ########## Optimal approch
# unique = 0
# for i in arr:
#     unique = unique ^ i
# print(unique)

# # Q4 Find duplicate elements in an array.

# arr = [1, 2, 3, 4, 5, 6, 2, 6, 5]
# duplicate_element_array = []

# for i in range(len(arr)):
#     match_count = 0
#     for j in range(i, len(arr)):
#         if arr[i] == arr[j] and match_count <= 1:
#             match_count += 1
#     if match_count > 1:
#         duplicate_element_array.append(arr[i])

# print(duplicate_element_array)

# ########## Optimal approch
# dict = {}
# for i in arr:
#     if i not in dict:
#         dict[i] = 1
#     else:
#         return i

# # Q5 Find intesection of an array.

# arr1 = [1, 2, 3, 4, 5, 6, 6]
# arr2 = [5, 6, 7, 8]
# intersection_array = []
# for i in range(len(arr1)):
#     for j in range(len(arr2)):
#         if arr1[i] == arr2[j]:
#             intersection_array.append(arr1[i])
#             arr2[j] = -123345

# print(intersection_array)

# # Q6 3Sum or Triplet sum of given number
# # sol1 - Two Pair
# result = []
# for i in range(n - 1):
#     s = set()
#     for j in range(i + 1, n):
#         third_val = k - arr[i] - arr[j]
#         pair = sorted([arr[i], arr[j], third_val])
#         if third_val in s and pair not in result:
#             result.append(pair)
#         else:
#             s.add(arr[j])
# print(result)

# # sol2 - using tupe-set
# result = []
# temp = set()
# for i in range(n - 1):
#     s = set()
#     for j in range(i + 1, n):
#         third_val = k - arr[i] - arr[j]
#         pair = sorted([arr[i], arr[j], third_val])
#         tuple_pair = tuple(pair)
#         if third_val in s and tuple_pair not in temp:
#             temp.add(tuple_pair)
#             result.append(pair)
#         else:
#             s.add(arr[j])
# print(result)
