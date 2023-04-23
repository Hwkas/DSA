#include <iostream>
using namespace std;

// code studio
// Allocate Books
// https://www.codingninjas.com/codestudio/problems/ayush-and-ninja-test_1097574?source=youtube&campaign=love_babbar_codestudio2&utm_source=youtube&utm_medium=affiliate&utm_campaign=love_babbar_codestudio2

bool is_possible(int arr[], int n, int m, int sum, int temp = 0)
{
    // int i;
    // if (m == 0)
    // {
    //     return true;
    // }
    // if ((temp + arr[0]) <= sum)
    // {
    //     temp += arr[0];
    //     m--;
    //     i = 1;
    // }
    // else
    // {
    //     temp = 0;
    //     n--;
    //     i = 0;
    //     if (n == 0)
    //     {
    //         return false;
    //     }
    // }
    // return is_possible(arr + i, n, m, sum, temp);

    if (m == 0)
    {
        return true;
    }
    if ((temp + arr[m - 1]) <= sum)
    {
        temp += arr[m - 1];
        m--;
    }
    else
    {
        temp = 0;
        if ((temp + arr[m - 1]) <= sum)
        {
            temp += arr[m - 1];
            m--;
        }
        n--;
        if (n == 0)
        {
            return false;
        }
    }
    return is_possible(arr, n, m, sum, temp);
}

int binary_search(int arr[], int start, int end, int n, int m, int ans = 0)
{
    if (start > end)
    {
        return ans;
    }
    int mid = start + (end - start) / 2;

    if (is_possible(arr, n, m, mid))
    {
        ans = mid;
        end = mid - 1;
    }
    else
    {
        start = mid + 1;
    }
    return binary_search(arr, start, end, n, m, ans);
}

// int main()
// {
//     int arr[] = {1, 2, 2, 3, 1}; // time taken by each chapter
//     int n = 3;                   // no. of days
//     int m = 5;                   // no. of chapters
//     int sum = 0;
//     for (int i = 0; i < m; i++)
//     {
//         sum += arr[i];
//     }
//     cout << "The Maximun no. of books that can be allocated are: " << binary_search(arr, 0, sum, n, m) << endl;
// }

// the below code it to use code studio test cases as it is
int main()
{
    int t = 0;
    cin >> t;
    int *ans = new int[t];
    for (int i = 0; i < t; i++)
    {
        int n, m;
        cin >> n >> m;
        int *arr = new int[m];
        int sum = 0;
        for (int j = 0; j < m; j++)
        {
            cin >> arr[j];
            sum += arr[j];
        }
        ans[i] = binary_search(arr, 0, sum, n, m);
        delete[] arr;
    }

    for (int k = 0; k < t; k++)
    {
        cout << "The Maximun no. of chapters that can be allocated for a day are: " << ans[k] << endl;
    }
}