#include <iostream>
using namespace std;

/*************************************** Normal Functions *******************************/

// int factorial(int n)
// {
//     if (n == 0)
//     {
//         return 1;
//     }
//     return n * factorial(n - 1);
// }

// int fibonacci(int n)
// {
//     if (n == 0 || n == 1)
//     {
//         return n;
//     }
//     return fibonacci(n - 1) + fibonacci(n - 2);
// }

// void get_array_values(int arr[], int n)
// {
//     for (int i = 0; i < n; i++)
//     {
//         cin >> arr[i];
//     }
// }

// void print_array(int arr[], int n)
// {
//     for (int i = 0; i < n; i++)
//     {
//         cout << arr[i] << " ";
//     }
// }

// bool is_array_sorted(int arr[], int index, int size)
// {
//     if (index == size - 1)
//     {
//         return true;
//     }
//     return (arr[index] <= arr[index + 1]) & is_array_sorted(arr, index + 1, size);
// }

// int array_sum(int arr[], int size)
// {
//     if (size == 0)
//     {
//         return arr[0];
//     }
//     return arr[0] + array_sum(arr + 1, size - 1);
// }

/*************************************** InLine Functions *******************************/

inline int factorial(int n)
{
    return n == 0 ? 1 : (n * factorial(n - 1));
}

inline int fibonacci(int n)
{
    return (n == 0 || n == 1) ? n : (fibonacci(n - 1) + fibonacci(n - 2));
}

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

inline bool is_array_sorted(int arr[], int index, int size)
{
    return (index == size - 1) ? true : ((arr[index] <= arr[index + 1]) & is_array_sorted(arr, index + 1, size));
}

inline int array_sum(int arr[], int size)
{
    cout << "Array element: " << arr[0] << " Size: " << size << endl;
    return (size == 1) ? arr[0] : (arr[0] + array_sum(arr + 1, size - 1));
}

int main()
{

    // cout<<"Enter the number to find it's factorial & fibonacci: ";
    // int n;
    // cin>>n;

    // cout<<"The factorial of "<<n<<" is: "<<factorial(n)<<endl;

    // cout<<"The fibonacci of "<<n<<" is: "<<fibonacci(n)<<endl;

    cout << "Enter the number of elements in array: ";
    int n;
    cin >> n;

    int *arr = new int[n];

    get_array_values(arr, n);

    cout << "The Sum of Array is: " << array_sum(arr, n) << endl;

    // is_array_sorted(arr, 0, n) ? cout << "True" << endl : cout << "False" << endl;

    print_array(arr, n);

    delete[] arr;
}
