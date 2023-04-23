#include <iostream>
using namespace std;

void dynamic_1d_array()
{
    cout << "Enter the number of elements you want to your Dynamic 1D Array: ";
    int n;
    cin >> n;

    // Creating Dynamic 1D Array
    int *arr = new int[n];

    cout << "Enter the elements of the Array" << endl;
    // Initializing Array
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    // Printing Array
    for (int j = 0; j < n; j++)
    {
        cout << arr[j] << " ";
    }

    // Freeing Up the Memory
    delete[] arr;
}

void dynamic_2d_array()
{
    cout << "Enter the number of rows & columns you want in your Dynamic 2D Array: ";
    int n, m;
    cin >> n >> m;

    // Creating Dynamic 2D Array
    int **arr = new int *[n];

    for (int i = 0; i < n; i++)
    {
        arr[i] = new int[m];
    }

    cout << "Enter the elements of the Array" << endl;
    // Initializing Array
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }

    cout << endl;

    // Printing Array
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    // Freeing Up the Memory
    for (int i = 0; i < n; i++)
    {
        delete[] arr[i];
    }

    delete[] arr;
}

void jagged_array()
{
    cout << "Enter the number of row you want in your Jagged Array: ";
    int n;
    cin >> n;

    // Creating Dynamic 1D Array for no. of columns in each row
    int *rows = new int[n];
    for (int i = 0; i < n; i++)
    {
        cout << "Enter the no. of columns you want in your " << i << " row: ";
        cin >> rows[i];
    }

    // Creating Dynamic 2D Array
    int **arr = new int *[n];

    for (int i = 0; i < n; i++)
    {
        arr[i] = new int[rows[i]];
    }

    // Initializing Array
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < rows[i]; j++)
        {
            cin >> arr[i][j];
        }
    }

    cout << endl;

    // Priting Array
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < rows[i]; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    // Freeing Up the Memory
    for (int i = 0; i < n; i++)
    {
        delete[] arr[i];
    }

    delete[] arr;
}

int main()
{
    // dynamic_1d_array();

    // dynamic_2d_array();

    jagged_array();

    return 0;
}