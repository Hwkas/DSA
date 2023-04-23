#include <iostream>
using namespace std;

inline void get_array_values(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cin >> arr[i];
}

inline void print_array(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
}

bool binary_search(int arr[], int start, int end, int key)
{
    if (start > end)
    {
        return false;
    }

    int mid = start + (end - start) / 2;

    if (arr[mid] == key)
    {
        return true;
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
    cout << "Enter the number of elements you want in your array: ";
    int n;
    cin >> n;

    cout << "Enter " << n << " elements for you array: " << endl;

    int *arr = new int[n];

    get_array_values(arr, n);

    print_array(arr, n);

    cout << endl
         << "Enter the element you want you search in the array: ";
    int key;
    cin >> key;

    binary_search(arr, 0, n - 1, key) ? cout << key << " is present in the array" << endl : cout << key << " is not present in the array" << endl;

    return 0;
}