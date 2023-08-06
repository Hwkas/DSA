#include <iostream>
#include <stack>
using namespace std;

// using recursion
void sorted_insert(stack<int> &s, int data)
{
    if (s.empty() || s.top() < data)
    {
        s.push(data);
        return;
    }

    int temp = s.top();
    s.pop();

    sorted_insert(s, data);

    s.push(temp);
}

// using recursion
void sort_stack(stack<int> &s)
{
    if (s.empty())
    {
        return;
    }

    int temp = s.top();
    s.pop();

    sort_stack(s);

    if (s.empty() || s.top() <= temp)
    {
        s.push(temp);
    }
    else
    {
        sorted_insert(s, temp);
    }
}

int main()
{
    stack<int> s;

    int arr[] = {83, 74, 67, 49, 94, 8, 11, 1};

    int size = sizeof(arr) / sizeof(arr[0]);

    for (int i = size - 1; i > -1; i--)
    {
        s.push(arr[i]);
    }

    sort_stack(s);

    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }

    cout << endl;

    return 0;
}