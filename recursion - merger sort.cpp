#include <iostream>
using namespace std;

// normal solution
// void merge(int arr[], int start, int mid, int end)
// {
//     int len1 = mid - start + 1;
//     int len2 = end - mid;

//     int *left_arr = new int[len1];
//     int *right_arr = new int[len2];

//     // creating a copy array into two parts
//     int main_arr_index = start;
//     for (int i = 0; i < len1; i++)
//     {
//         left_arr[i] = arr[main_arr_index++];
//     }

//     for (int i = 0; i < len2; i++)
//     {
//         right_arr[i] = arr[main_arr_index++];
//     }

//     // merging them
//     main_arr_index = start;
//     int index1 = 0, index2 = 0;

//     while (index1 < len1 && index2 < len2)
//     {
//         if (left_arr[index1] < right_arr[index2])
//         {
//             arr[main_arr_index++] = left_arr[index1++];
//         }
//         else
//         {
//             arr[main_arr_index++] = right_arr[index2++];
//         }
//     }

//     while (index1 < len1)
//     {
//         arr[main_arr_index++] = left_arr[index1++];
//     }

//     while (index2 < len2)
//     {
//         arr[main_arr_index++] = right_arr[index2++];
//     }

//     delete[] left_arr;
//     delete[] right_arr;
// }

// In place solution
void merge(int arr[], int start, int mid, int end)
{
    int left_pointer = start;
    int right_pointer = mid + 1;

    if (arr[mid] <= arr[right_pointer])
    {
        return;
    }

    while (left_pointer <= mid && right_pointer <= end)
    {
        if (arr[left_pointer] > arr[right_pointer])
        {
            int temp_element = arr[right_pointer];

            for (int i = right_pointer; i > left_pointer; i--)
            {
                arr[i] = arr[i - 1];
            }
            arr[left_pointer] = temp_element;
            mid++; // increasing mid, to adjust it with the elements position with the rigth shift
            right_pointer++;
        }
        left_pointer++;
    }
}

void merge_sort(int arr[], int start, int end)
{
    if (start == end)
    {
        return;
    }

    int mid = start + (end - start) / 2;

    // left half
    merge_sort(arr, start, mid);

    // right half
    merge_sort(arr, mid + 1, end);

    merge(arr, start, mid, end);
}

inline void print_array(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main()
{
    int arr[] = {3, 4, 1, 6, 2, 5, 7};
    int n = 7;
    merge_sort(arr, 0, n - 1);
    print_array(arr, n);
    return 0;
}