#include <iostream>
using namespace std;

void bubble_sort(int arr[], int n)
{
    if (n <= 1)
    {
        return;
    }

    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i] > arr[i + 1])
        {
            swap(arr[i], arr[i + 1]);
        }
    }
    bubble_sort(arr, --n);
}

inline void print_array(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main()
{
    int arr[] = {2, 5, 1, 6, 9};
    int n = 5;

    bubble_sort(arr, n);
    print_array(arr, n);

    return 0;
}