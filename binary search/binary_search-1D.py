# def binary_search(array, key):
#     start = 0
#     end = len(array) - 1

#     while start <= end:
#         mid = start + (end - start) // 2
#         if array[mid] == key:
#             return mid
#         elif array[mid] < key:
#             start = mid + 1
#         else:
#             end = mid - 1
#     return -1


# array = [5, 10, 11, 24, 60, 69]

# print(binary_search(array, 49))

#############################################################################################################################

# Q1 Find Pivot in an array


def pivot_search(array):
    start = 0
    end = len(array) - 1
    mid = start + (end - start) // 2
    while start < end:
        if array[mid] >= array[0]:
            start = mid + 1
        else:
            end = mid
        mid = start + (end - start) // 2
    return mid


array = [18, 22, 25, 1, 3, 5, 6, 7, 10, 14]

print(pivot_search(array))
