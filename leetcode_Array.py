# 88. Merge Sorted Array
def insertion_sort(nums1, m, nums2, n):
    for i in range(n):
        j = m + i - 1
        while (j > -1) and (nums1[j] > nums2[i]):
            nums1[j], nums1[j + 1] = nums1[j + 1], nums1[j]
            j -= 1
        nums1[j + 1] = nums2[i]


nums1 = [1, 2, 3, 0, 0, 0]
m = 3
nums2 = [2, 5, 6]
n = 3
insertion_sort(nums1, m, nums2, n)
print(nums1)

# Two Pointer Approch
i = m - 1
j = n - 1
k = m + n - 1
while i >= 0 and j >= 0:
    if nums1[i] > nums2[j]:
        nums1[k] = nums1[i]
        k -= 1
        i -= 1
    else:
        nums1[k] = nums2[j]
        k -= 1
        j -= 1

while j >= 0:
    nums1[k] = nums2[j]
    k -= 1
    j -= 1


# C++ Solution
# void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {

#             for(int i=0; i<n; i++){
#                 int j = m + i - 1;
#                 int temp = 0;
#                 for(; j >= 0; j--){
#                     if(nums1[j] > nums2[i]){
#                         temp = nums1[j];
#                         nums1[j] = nums1[j+1];
#                         nums1[j+1] = temp;
#                     }
#                     else break;
#                 }
#                 nums1[j+1] = nums2[i];
#             }
#         }
# };

#########################################################################################################################################

# 283. Move Zeroes

nums = [
    0,
    0,
    -32191,
    -21331,
    0,
    0,
    0,
    0,
    52565,
    -52662,
    0,
    0,
    64446,
    -23832,
    -19466,
    56104,
    0,
    0,
    0,
    -69599,
    48457,
    55010,
    0,
    0,
    -5312,
    0,
    0,
    0,
    51095,
    230,
    0,
    0,
    -3544,
    0,
    0,
    73761,
    0,
    0,
    0,
    -54284,
    0,
    14160,
    0,
    0,
    47462,
    0,
    -89975,
    0,
    1648,
    0,
    0,
    0,
    -64532,
    0,
    0,
    -10764,
    -18879,
    0,
    0,
    81421,
    0,
    0,
    0,
    58794,
    -50705,
    0,
    0,
    96772,
    55683,
    -1988,
    0,
    0,
    0,
    -72518,
    0,
    30889,
    13049,
    26432,
    -4915,
    -14889,
    55290,
    0,
    0,
    0,
    0,
    0,
    0,
    69786,
    -95792,
    -41941,
    43392,
    21116,
    0,
    0,
    0,
    -18931,
    0,
    49528,
    -39964,
    0,
    0,
    0,
    0,
    0,
    0,
    -17019,
    0,
    0,
    -45541,
    0,
    85498,
    16193,
    0,
    0,
    -51918,
    -5963,
    0,
    0,
    82707,
    0,
    74840,
    0,
    0,
    0,
    0,
    -61736,
    0,
    0,
    0,
    66307,
    -85110,
    0,
    0,
    -44183,
    88173,
    -80635,
    0,
    60344,
    0,
    -7750,
    0,
    0,
    78894,
    0,
    -17616,
    0,
    0,
    0,
    91569,
    0,
    0,
    27221,
    -35474,
    0,
    74890,
    0,
    51866,
    0,
    0,
    0,
    -18029,
    -77827,
    0,
]

# n = len(nums)
# for i in range(n):
#     if nums[i] == 0:
#         # Sol using for loop
#         for j in range(i + 1, n):
#             if nums[j] != 0:
#                 nums[i], nums[j] = nums[j], nums[i]
#                 break
#         # sol using while loop
#         j = i + 1
#         while j < n:
#             if nums[j] != 0:
#                 nums[i], nums[j] = nums[j], nums[i]
#                 break
#             j += 1


n = len(nums)
i = 0
j = 0
while i < n:
    if nums[i] != 0:
        nums[j] = nums[i]
        j += 1
        i += 1
    else:
        i += 1
for i in range(j, n):
    nums[i] = 0

print(nums)


# C++ Solution
# void moveZeroes(vector<int>& nums) {

#     int n = nums.size();
#     int i = 0;
#     int j = 0;

#     while(i < n){
#         if(nums[i] != 0){
#             nums[j++] = nums[i++];
#         }
#         else i++;
#     }

#     for(i = j; i < n; i++) nums[i] = 0;

# }


#########################################################################################################################################


# 189. Rotate Array


def reverse_array(array, start, end):
    while start <= end:
        array[start], array[end] = array[end], array[start]
        start += 1
        end -= 1


nums = [1, 2, 3, 4, 5, 6, 7]
k = 3
k = k % n
n = len(nums)
reverse_array(nums, 0, (n - k - 1))
reverse_array(nums, (n - k), (n - 1))
reverse_array(nums, 0, (n - 1))


# C++ solution

# void reverse(vector<int> &ary, int start, int end){
#             while(start < end){
#                 swap(ary[start++], ary[end--]);
#             }
#         }

#     void rotate(vector<int>& nums, int k) {


#         int n = nums.size();
#         // sol1
#         // vector<int> temp(n);
#         // for(int i=0; i<n; i++) temp[((k+i)%n)] = nums[i];
#         // nums = temp;

#         // sol2
#         k = k % n;
#         reverse(nums, 0, (n-k-1));
#         reverse(nums, (n-k), (n-1));
#         reverse(nums, 0, (n-1));
#     }
