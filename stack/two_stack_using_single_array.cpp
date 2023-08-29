#include <iostream>
using namespace std;

class TwoStack
{
public:
    int *arr;
    int top1;
    int top2;
    int size;

    // Initialize TwoStack.
    TwoStack(int s)
    {
        // Write your code here.
        size = s;
        arr = new int[size];
        top1 = -1;
        top2 = s;
    }

    // Push in stack 1.
    void push1(int num)
    {
        // Write your code here.
        if (top2 - top1 > 1)
        {
            arr[++top1] = num;
        }
        else
            top1;
    }

    // Push in stack 2.
    void push2(int num)
    {
        // Write your code here.
        if (top2 - top1 > 1)
        {
            arr[--top2] = num;
        }
        else
            top2;
    }

    // Pop from stack 1 and return popped element.
    int pop1()
    {
        // Write your code here.
        if (top1 == -1)
            return -1;

        return arr[top1--];
    }

    // Pop from stack 2 and return popped element.
    int pop2()
    {
        // Write your code here.
        if (top2 == size)
            return -1;

        return arr[top2++];
    }
};

int main()
{

    TwoStack ts(3);

    ts.push1(2);
    ts.push1(4);
    ts.push1(3);

    ts.push2(5);

    cout << ts.pop2() << endl;

    return 0;
}
