#include <iostream>
using namespace std;

// void print_row_sum(int arr[][4], int row, int col)
// {
//     int sum;
//     for (int i = 0; i < row; i++)
//     {
//         sum = 0;
//         for (int j = 0; j < col; j++)
//         {
//             sum += arr[i][j];
//         }
//         cout << sum << endl;
//     }
// }

// void print_col_sum(int arr[][4], int row, int col)
// {
//     int sum;
//     for (int i = 0; i < col; i++)
//     {
//         sum = 0;
//         for (int j = 0; j < row; j++)
//         {
//             sum += arr[j][i];
//         }
//         cout << sum << endl;
//     }
// }

// void print_largest_row_sum(int arr[][4], int row, int col)
// {
//     int max_sum_row, max_sum, curr_sum;
//     max_sum = 0;
//     for (int i = 0; i < row; i++)
//     {
//         curr_sum = 0;
//         for (int j = 0; j < col; j++)
//         {
//             curr_sum += arr[i][j];
//         }
//         if (curr_sum > max_sum)
//         {
//             max_sum = curr_sum;
//             max_sum_row = i;
//         }
//     }
//     cout << max_sum_row;
// }

// int main()
// {
//     int arr[3][4];

//     cout << "Enter the elements for a 3x3 Array." << endl;

//     for (int row = 0; row < 3; row++)
//     {
//         for (int col = 0; col < 4; col++)
//         {
//             cin >> arr[row][col];
//         }
//     }

//     cout << "The elements of Array are: " << endl;

//     for (int row = 0; row < 3; row++)
//     {
//         for (int col = 0; col < 4; col++)
//         {
//             cout << arr[row][col] << " ";
//         }
//         cout << endl;
//     }

//     cout << "Sum of rows" << endl;
//     print_row_sum(arr, 3, 4);

//     cout << "Sum of cols" << endl;
//     print_col_sum(arr, 3, 4);

//     cout << "Row with largest sum is: " << endl;
//     print_largest_row_sum(arr, 3, 4);

//     return 0;
// }

// Q LeetCode
// 48. Rotate Image
// You are given an n x n 2D matrix representing an image, rotate the image by 90 degrees (clockwise).

// You have to rotate the image in-place, which means you have to modify the input 2D matrix directly. DO NOT allocate another 2D matrix and do the rotation.

void print(int arr[][3], int n)
{
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    int matrix[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

    int n = 3;
    int temp;
    for (int i = 0; i < (n + 1) / 2; i++)
    {
        for (int j = 0; j < n / 2; j++)
        {
            temp = matrix[n - j - 1][i];
            matrix[n - j - 1][i] = matrix[n - i - 1][n - j - 1];
            matrix[n - i - 1][n - j - 1] = matrix[j][n - i - 1];
            matrix[j][n - i - 1] = matrix[i][j];
            matrix[i][j] = temp;
        }
    }

    print(matrix, 3);

    return 0;
}