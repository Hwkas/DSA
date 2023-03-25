#include <iostream>
using namespace std;

int pivot_index(int arr[], int start, int end)
{
    int mid = start + (end - start) / 2;
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
    return pivot_index(arr, start, end);
}

// int pivot_index(int arr[], int start, int end)
// {
//     int mid = start + (end - start) / 2;

//     while (start < end)
//     {
//         if (arr[mid] >= arr[0])
//         {
//             start = mid + 1;
//         }
//         else
//         {
//             end = mid;
//         }
//         mid = start + (end - start) / 2;
//     }
//     return mid;
// }

int main()
{

    // int arr[] = {10, 11, 12, 6, 7, 8, 9};
    int arr[] = {6, 7, 8, 9, 1, 2, 3, 4, 5};
    int n = 7;

    cout << pivot_index(arr, 0, n - 1) << endl;

    return 0;
}