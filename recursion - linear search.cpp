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

bool liner_search(int arr[], int size, int key)
{
    if (size == 0)
    {
        return false;
    }
    else if (arr[0] == key)
    {
        return true;
    }
    else
    {
        return liner_search(arr + 1, size - 1, key);
    }
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

    liner_search(arr, n, key) ? cout << key << " is present in the array" << endl : cout << key << " is not present in the array" << endl;

    return 0;
}