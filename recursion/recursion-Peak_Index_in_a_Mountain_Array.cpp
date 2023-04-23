#include <iostream>
using namespace std;

// Leetcode
// Q 852. Peak Index in a Mountain Array
// https://leetcode.com/problems/peak-index-in-a-mountain-array/


int get_peak_index(int arr[], int start, int end, int ans = -1)
{
    if (start >= end)
    {
        return ans;
    }

    int mid = start + (end - start) / 2;

    if (arr[mid] < arr[mid + 1])
    {
        ans = start = mid + 1;
    }
    else
    {
        ans = end = mid;
    }
    return get_peak_index(arr, start, end, ans);
}

int main()
{
    int arr[] = {0, 10, 5, 2};
    int n = 4;

    cout << get_peak_index(arr, 0, n - 1) << endl;
    return 0;
}