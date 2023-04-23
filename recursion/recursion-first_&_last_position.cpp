#include <iostream>
using namespace std;

// Code Studio
// Q.First and Last Position of an Element In Sorted Array
// https://www.codingninjas.com/codestudio/problems/first-and-last-position-of-an-element-in-sorted-array_1082549?source=youtube&campaign=love_babbar_codestudio2&utm_source=youtube&utm_medium=affiliate&utm_campaign=love_babbar_codestudio2&leftPanelTab=0

int first_occur(int arr[], int start, int end, int key, int ans = -1)
{
    if (start >= end)
    {
        return ans;
    }

    int mid = start + (end - start) / 2;

    if (arr[mid] == key)
    {
        ans = mid;
        end = mid - 1;
        return first_occur(arr, start, end, key, ans);
    }
    else if (arr[mid] < key)
    {
        start = mid + 1;
    }
    else
    {
        end = mid - 1;
    }
    return first_occur(arr, start, end, key, ans);
}

int last_occur(int arr[], int start, int end, int key, int ans = -1)
{
    if (start > end)
    {
        return ans;
    }

    int mid = start + (end - start) / 2;

    if (arr[mid] == key)
    {
        ans = mid;
        start = mid + 1;
        return last_occur(arr, start, end, key, ans);
    }
    else if (arr[mid] < key)
    {
        start = mid + 1;
    }
    else
    {
        end = mid - 1;
    }
    return last_occur(arr, start, end, key, ans);
}

int main()
{
    int arr[] = {0, 0, 1, 1, 2, 2, 2, 2};
    int n = 8;
    int key = 2;

    cout << first_occur(arr, 0, n - 1, key) << endl;
    cout << last_occur(arr, 0, n - 1, key) << endl;
}