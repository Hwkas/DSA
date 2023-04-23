#include <iostream>
using namespace std;

int partition(int arr[], int start, int end)
{

    int pivot = arr[start];

    int cnt = 0;
    for (int i = start + 1; i <= end; i++)
    {
        if (arr[i] <= pivot)
        {
            cnt++;
        }
    }

    int pivot_index = start + cnt;
    swap(arr[pivot_index], arr[start]);

    int i = start, j = end;

    while (i < pivot_index && j > pivot_index)
    {

        while (arr[i] <= pivot)
        {
            i++;
        }

        while (arr[j] > pivot)
        {
            j--;
        }

        if (i < pivot_index && j > pivot_index)
        {
            swap(arr[i++], arr[j--]);
        }
    }

    return pivot_index;
}

void quick_sort(int arr[], int start, int end)
{

    if (start >= end)
    {
        return;
    }

    int partition_index = partition(arr, start, end);

    quick_sort(arr, start, partition_index - 1);

    quick_sort(arr, partition_index + 1, end);
}

inline void print_array(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main()
{
    int arr[] = {5, 1, 1, 2, 0, 0};
    int n = 6;
    quick_sort(arr, 0, n - 1);
    print_array(arr, n);
    return 0;
}