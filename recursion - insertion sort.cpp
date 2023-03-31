#include <iostream>
using namespace std;

void insertion_sort(int arr[], int n, int i = 0)
{
    if (i == (n - 1))
    {
        return;
    }
    int temp_val = arr[i + 1];
    int temp_index = i + 1;
    if (arr[i] < temp_val)
    {
        i++;
    }
    else
    {
        while (arr[i] > temp_val && i >= 0)
        {
            arr[i + 1] = arr[i];
            i--;
        }
        arr[i + 1] = temp_val;
        i = temp_index;
    }
    insertion_sort(arr, n, i);
}

inline void print_array(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main()
{
    int arr[] = {3, 2, 1};
    int n = 3;
    insertion_sort(arr, n);
    cout << "Sorted Array ";
    print_array(arr, n);

    return 0;
}

// for code studio test cases
// int main()
// {
//     int t = 0;
//     cin >> t;
//     for (int i = 0; i < t; i++)
//     {

//         int n;
//         cin >> n;
//         int *arr = new int[n];
//         for (int j = 0; j < n; j++)
//         {
//             cin >> arr[j];
//         }
//         insertion_sort(arr, n);
//         cout << "Sorted Array: ";
//         print_array(arr, n);
//         cout << endl
//              << endl
//              << endl;
//     }
// }