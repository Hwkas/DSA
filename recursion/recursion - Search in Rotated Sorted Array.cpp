#include <iostream>
using namespace std;

// code studio
// Q. Search In Rotated Sorted Array
// https://www.codingninjas.com/codestudio/problems/search-in-rotated-sorted-array_1082554?source=youtube&campaign=love_babbar_codestudio2&utm_source=youtube&utm_medium=affiliate&utm_campaign=love_babbar_codestudio2

int find_pivot_index(int arr[], int start, int end)
{
    int mid = start + (end - start) / 2;
    cout << start << " " << end << " " << mid << endl;
    if (start == end)
    {
        return mid;
    }

    if (arr[mid] >= arr[0])
    {
        start = mid + 1;
    }
    else
    {
        end = mid;
    }
    return find_pivot_index(arr, start, end);
}

int binary_search(int arr[], int start, int end, int key)
{
    if (start > end)
    {
        return -1;
    }

    int mid = start + (end - start) / 2;

    if (arr[mid] == key)
    {
        return mid;
    }
    else if (arr[mid] < key)
    {
        start = mid + 1;
    }
    else
    {
        end = mid - 1;
    }
    return binary_search(arr, start, end, key);
}

int main()
{
    int arr[] = {1, 3};
    int n = 2;
    int key = 1;
    int start = 0, end = n - 1;
    int pivot_index = find_pivot_index(arr, start, end);

    cout << "The pivot index is: " << pivot_index << endl;

    if (arr[n - 1] >= key)
    {
        start = pivot_index;
    }
    else
    {
        end = pivot_index;
    }
    cout << "The element is at index: " << binary_search(arr, start, end, key) << endl;

    return 0;
}