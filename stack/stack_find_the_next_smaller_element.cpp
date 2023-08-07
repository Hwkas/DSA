#include <iostream>
#include <stack>
using namespace std;

void solve(vector<int> &arr, int n)
{
    stack<int> s;

    s.push(-1);

    for (int i = n - 1; i > -1; i--)
    {
        int curr = arr[i];
        while (s.top() >= arr[i])
        {
            s.pop();
        }
        arr[i] = s.top();
        s.push(curr);
    }
}

int main()
{

    vector<int> arr;

    arr.push_back(5);
    arr.push_back(4);
    arr.push_back(3);
    arr.push_back(2);
    arr.push_back(1);

    int n = arr.size();

    solve(arr, n);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}