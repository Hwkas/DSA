# num = int(input("Enter a number to print its binary representation: "))


# Q1 Decimal to Binary coverter.
# ans = 0
# count = 0

# while num != 0:
#     ans = ((10**count) * (num & 1)) + ans
#     num = num >> 1
#     count += 1

# print(ans)


# Q2 Decimal to Binary converter for negative number.
# ans = 0
# count = 0
# num = num * -1
# while num != 0:
#     ans += (10**count) * (num & 1)
#     # or ans = ((10**count)*(num & 1)) + ans
#     count += 1
#     num = num >> 1
# # we are taking 10 power 64 because our system is 64 bit.
# ans = (10**64) + ans
# print(ans)


# Q3
# Binary to decimal converter.
num = input("Enter a number to print its binary representation: ")
# sol1
# ans = 0
# count = 0
# for n in num[::-1]:
#     if n == "1":
#         ans += 2**count
#     count += 1
# print(ans)
# sol2
ans = 0
for i in range(len(num) - 1, -1, -1):
    if num[i] == "1":
        ans += 2 ** (len(num) - i - 1)
print(ans)
