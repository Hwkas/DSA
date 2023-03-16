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

/*************************************** InLine Functions *******************************/

inline int factorial(int n)
{
    return n == 0 ? 1 : n * factorial(n - 1);
}

inline int fibonacci(int n)
{
    return (n == 0 || n == 1) ? n : fibonacci(n - 1) + fibonacci(n - 2);
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

    print_array(arr, n);

    delete[] arr;
}
