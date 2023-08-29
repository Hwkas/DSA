#include <iostream>
#include <stack>
using namespace std;

vector<int> next_smaller(vector<int> &v, int n)
{
    stack<int> s;
    s.push(-1);

    vector<int> ans(n);

    int curr;

    for (int i = n - 1; i > -1; i--)
    {
        curr = v[i];

        while (s.top() != -1 && v[s.top()] >= curr)
        {
            s.pop();
        }

        ans[i] = s.top();
        s.push(i);
    }

    return ans;
}

vector<int> prev_smaller(vector<int> &v, int n)
{
    stack<int> s;
    s.push(-1);

    vector<int> ans(n);

    int curr;

    for (int i = 0; i < n; i++)
    {
        curr = v[i];

        while (s.top() != -1 && v[s.top()] >= curr)
        {
            s.pop();
        }

        ans[i] = s.top();
        s.push(i);
    }

    return ans;
}

int largestRectangleArea(vector<int> &heights)
{
    int n = heights.size();

    vector<int> next = next_smaller(heights, n);
    vector<int> prev = prev_smaller(heights, n);

    int area = INT_MIN;
    int temp = 0;

    for (int i = 0; i < n; i++)
    {
        if (next[i] == -1)
        {
            next[i] = n;
        }

        temp = heights[i] * (next[i] - prev[i] - 1);

        area = max(area, temp);
    }

    return area;
}

void print(vector<int> arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int maxArea(int M[4][4], int n, int m)
{
    // Your code here
    vector<int> arr(m);

    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            arr[j] += M[i][j];

            if (!M[i][j])
            {
                arr[j] = 0;
            }
        }

        print(arr, n);

        ans = max(ans, largestRectangleArea(arr));
    }

    return ans;
}

int main()
{
    int arr[4][4] = {
        {0, 1, 1, 0},
        {1, 1, 1, 1},
        {1, 1, 1, 1},
        {1, 1, 0, 0},
    };

    cout << maxArea(arr, 4, 4) << endl;

    return 0;
}
