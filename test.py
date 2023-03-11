# s = "testsample"
# letter = ""
# letter_count = -1
# n = len(s)
# for i in range(n-1):
#     count = 1
#     for j in range(i+1, n):
#         if(s[i] == s[j]):
#             count += 1
#     if((count > letter_count) or ((count == letter_count) and (letter > s[i]))):
#         letter = s[i]
#         letter_count = count
# print(letter)



# matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]

# row = 3
# col = 4

# starting_row = 0
# starting_col = 0
# ending_row = row-1
# ending_col = col-1

# total_elements = row*col

# count = 0

# while(count < total_elements):
#     # starting row
#     for index in range(starting_col, ending_col+1):
#         print(matrix[starting_row][index], end=" ")
#         count += 1
#     starting_row += 1

#     # ending col
#     for index in range(starting_row, ending_row+1):
#         print(matrix[index][ending_col], end=" ")
#         count += 1
#     ending_col -= 1

#     # ending row
#     for index in range(ending_col, starting_col-1, -1):
#         print(matrix[ending_row][index], end=" ")
#         count += 1
#     ending_row -= 1

#     # starting col
#     for index in range(ending_row, starting_row-1, -1):
#         print(matrix[index][starting_col], end=" ")
#         count += 1
#     starting_col += 1


# matrix = [[1,2,3],[4,5,6],[7,8,9]]

# n = len(matrix)
# temp = 0
# for i in range((n+1)//2):
#     for j in range((n)//2):
#         temp = matrix[n - 1 - j][i]
#         matrix[n - 1 - j][i] = matrix[n - 1 - i][n - j - 1]
#         matrix[n - 1 - i][n - j - 1] = matrix[j][n - 1 -i]
#         matrix[j][n - 1 - i] = matrix[i][j]
#         matrix[i][j] = temp

#     print()
#     print(matrix)
