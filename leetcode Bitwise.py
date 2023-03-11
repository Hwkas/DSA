num = int(input("Enter a number:  "))

# Q7. Reverse Integer 
# Given a signed 32-bit integer X , return X with its digits reversed. 
# If reversing X causes the value to go outside the signed 32-bit integer range -2, 2 - 1, then return 0
# Assume the environment does not allow you to store 64-bit integers (signed or unsigned).

# def reverse(num):
#     ans = 0
#     negative = False
#     if num < 0:
#         negative = True
#         num *= -1

#     while(num != 0):
#         if (ans > (2**31-1)/10) or (ans < (2**31)*(-1)):
#             return 0
#         ans = (ans*10)+(num%10)
#         num = num //10

#     if negative == True:
#         ans *= -1
#     return ans
# print(reverse(num))


# Q1009. Complement of Base 10 Integer
# The complement of an integer is the integer vou get when vou flip a the o'sto 1's and al the
# 1'sto d's in its binary representation.
# • For example, The integer 5 is "101" in binarv and its complement is "010" which is the integer 2.
# Given an integer n , return its complement.
# sol1 
# def compliment(num):
#     binary = 0
#     count = 0
#     ones_compliment = 0
#     if num == 0:
#         return 1
#     while (num != 0):
#         bit = 0 if (num & 1) else 1
#         binary = ((10**count) * bit) + binary
#         num = num >> 1
#         count += 1

#     count = 0
#     while(binary != 0):
#         if (binary % 10):
#             ones_compliment += (2**count)
#         count += 1
#         binary = binary // 10

#     return ones_compliment

# sol2
# def compliment(num):
#     m = num
#     mask = 0

#     if num == 0:
#         return 1
#     while(m != 0):
#         mask = (mask << 1) | 1
#         m = m >> 1

#     return ((~ num) & mask)

# print(f"The decimal representation of One's compliment of {num} is {compliment(num)}")


# Q231. Power of Two
# Given an inteder n . return true it its a power of two. Otherwise. return false.
# An Integer n is a power of two, if there exists an integer X such that n == 2^x.

def check_power_of_two(num):
    occur = 0
    if num == 0:
        return False
        
    while (num != 0) and (occur <=1):
        occur += 1 if (num & 1) else 0
        num = num >> 1
    
    if occur <=1:
        return True
    else:
        return  False

print(check_power_of_two(num))