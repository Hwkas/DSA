#include <iostream>
#include <stack>
using namespace std;

// Normal Solution
void deleteMiddle(stack<int> &inputStack, int N)
{
    if (inputStack.empty())
    {
        return;
    }

    stack<int> temp;

    for (int i = 0; i <= N / 2; i++)
    {
        temp.push(inputStack.top());
        inputStack.pop();
    }

    temp.pop();

    while (!temp.empty())
    {
        inputStack.push(temp.top());
        temp.pop();
    }
}

// Recursive Solution
void deleteMiddle(stack<int> &inputStack, int N, int count)
{
    count++;

    if (count == N / 2)
    {
        inputStack.pop();
        return;
    }

    int temp_data = inputStack.top();
    inputStack.pop();

    deleteMiddle(inputStack, N, count);

    inputStack.push(temp_data);
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

    // deleteMiddle(s, size);

    deleteMiddle(s, size, 0);

    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }

    cout << endl;

    return 0;
}