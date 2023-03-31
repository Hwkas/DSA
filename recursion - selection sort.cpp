#include <iostream>
using namespace std;

void selection_sort(int arr[], int n)
{
    if (n == 0)
    {
        return;
    }
    int min = arr[0];
    int min_index = 0;
    for (int i = 1; i < n; i++)
    {
        if (min > arr[i])
        {
            min = arr[i];
            min_index = i;
        }
    }
    swap(arr[0], arr[min_index]);
    selection_sort(++arr, --n);
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
    selection_sort(arr, n);
    cout << "Sorted Array ";
    print_array(arr, n);

    return 0;
}