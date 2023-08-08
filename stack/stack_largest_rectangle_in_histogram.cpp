#include <iostream>
#include <stack>
using namespace std;

// normal solution
// int largestRectangleArea(vector<int> &heights)
// {
//     stack<int> s;

//     int sum = 0;

//     int curr;
//     int temp;

//     int n = heights.size();

//     for (int i = 0; i < n; i++)
//     {
//         curr = temp = heights[i];

//         for (int j = i + 1; j < n; j++)
//         {
//             if (heights[j] < curr)
//             {
//                 break;
//             }
//             temp += curr;
//         }

//         for (int j = i - 1; j > -1; j--)
//         {
//             if (heights[j] < curr)
//             {
//                 break;
//             }
//             temp += curr;
//         }

//         if (sum < temp)
//         {
//             sum = temp;
//         }
//     }

//     return sum;
// }

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

// Optimized Solution
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

int main()
{
    vector<int> v;

    v.push_back(1);
    v.push_back(1);
    // v.push_back(5);
    // v.push_back(6);
    // v.push_back(2);
    // v.push_back(3);

    cout << largestRectangleArea(v) << endl;

    return 0;
}