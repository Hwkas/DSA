n = int(input("Enter a number to print the patter:  "))


# Q1
# for i in range(n):
#     for j in range(n):
#         print(n - j, end="")
#     print()


# Q2
# count = 0
# for i in range(n):
#     for j in range(n):
#         count += 1
#         print(count, end="")
#     print()


# Q3
# for i in range(n):
#     for j in range(i + 1):
#         print("*", end="")
#     print()


# Q4
# for i in range(n):
#     for j in range(i + 1):
#         print(i + 1, end="")
#     print()


# Q5
# count = 0
# for i in range(n):
#     for j in range(i + 1):
#         count += 1
#         print(count, end="")
#     print()

# Q6
# count = 1
# Sol1
# reset_value = 0
# for i in range(n):
#     for j in range(i + 1):
#         if j == 1:
#             reset_value = count
#         print(count, end="")
#         count += 1
#     if i != 0:
#         count = reset_value
#     print()
# Sol2
# for i in range(n):
#     for j in range(i + 1):
#         count = i + j + 1
#         print(count, end="")
#     print()


# Q7
# count = 0
# for i in range(n):
#     for j in range(i + 1):
#         count = i - j + 1
#         print(count, end="")
#     print()


# Q8
# letter = "A"
# for i in range(n):
#     for j in range(n):
#         print(letter, end="")
#     letter = chr(ord(letter) + 1)
#     print()


# Q9
# for i in range(n):
#     letter = "A"
#     for j in range(n):
#         print(letter, end="")
#         letter = chr(ord(letter) + 1)
#     print()


# Q10
# letter = "A"
# for i in range(n):
#     for j in range(n):
#         print(letter, end="")
#         letter = chr(ord(letter) + 1)
#     print()


# Q11
# letter = "A"
# for i in range(n):
#     for j in range(n):
#         print(chr(ord(letter) + i + j), end="")
#     print()


# Q12
# letter = "A"
# for i in range(n):
#     for j in range(i + 1):
#         print(chr(ord(letter) + i), end="")
#     print()


# Q13
# letter = "A"
# count = 0
# for i in range(n):
#     for j in range(i + 1):
#         print(chr(ord(letter) + count), end="")
#         count += 1
#     print()


# Q14
# letter = "A"
# for i in range(n):
#     for j in range(i + 1):
#         print(chr(ord(letter) + n - i + j - 1), end="")
#     print()


# Q15
# letter = "A"
# for i in range(n):
#     for j in range(n):
#         print(chr(ord(letter) + i + j), end="")
#     print()


# Q16
# for i in range(n):
#     for j in range(n):
#         if j >= n - i - 1:
#             print("*", end="")
#         else:
#             print(" ", end="")
#     print()


# Q17
# for i in range(n):
#     for j in range(n - i):
#         print("*", end="")
#     print()


# Q18
# for i in range(n):
#     for j in range(n):
#         if j >= i:
#             print("*", end="")
#         else:
#             print(" ", end="")
#     print()


# Q19
# for i in range(n):
#     for j in range(n):
#         if j >= i:
#             print(i + 1, end="")
#         else:
#             print(" ", end="")
#     print()


# Q20
# for i in range(n):
#     for j in range(n):
#         if j >= n - i - 1:
#             print(i + 1, end="")
#         else:
#             print(" ", end="")
#     print()


# Q21
# for i in range(n):
#     for j in range(n):
#         if j < i:
#             print(" ", end="")
#         else:
#             print(j + 1, end="")
#     print()


# Q22
# count = 0
# for i in range(n):
#     for j in range(n):
#         if j >= n - i - 1:
#             count += 1
#             print(count, end="")
#         else:
#             print(" ", end="")
#     print()


# Q23
# for i in range(n):
#     count = 0
#     for j in range(n + i):
#         if j >= n - i - 1 and j < n:
#             count += 1
#             print(count, end="")
#         elif j >= n - i - 1 and j >= n:
#             count -= 1
#             print(count, end="")
#         else:
#             print(" ", end="")
#     print()


# Q24
for i in range(n):
    for j in range(n * 2):
        if j < n - i:
            print(j + 1, end="")
        elif j >= n + i:
            print((n * 2) - j, end="")
        else:
            print("*", end="")
    print()
