#include <iostream>
#include <stack>
using namespace std;

// using recursion
void inset_at_bottom(stack<int> &s, int data)
{
    if (s.empty())
    {
        s.push(data);
        return;
    }

    int temp = s.top();
    s.pop();

    inset_at_bottom(s, data);

    s.push(temp);
}

// using recursion
void reverse_stack(stack<int> &s)
{
    if (s.empty())
    {
        return;
    }

    int temp = s.top();
    s.pop();

    reverse_stack(s);

    inset_at_bottom(s, temp);
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

    reverse_stack(s);

    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }

    cout << endl;

    return 0;
}