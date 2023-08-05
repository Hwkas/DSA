#include <iostream>
#include <stdexcept>
using namespace std;

class Stack
{
public:
    int *arr;
    int top;
    int size;

    Stack(int size)
    {
        this->size = size;
        arr = new int[size];
        top = -1;
    }

    void push(int data)
    {
        if (++top == size)
        {
            top--;
            throw out_of_range("Stack over flow");
        }

        arr[top] = data;
    }

    void pop()
    {
        if (is_empty())
        {
            throw out_of_range("Stack is empty");
        }

        top--;
    }

    int peek()
    {
        if (is_empty())
        {
            throw out_of_range("Stack is empty");
        }

        return arr[top];
    }

    bool is_empty()
    {
        return top == -1 ? true : false;
    }
};

int main()
{
    Stack st(5);

    cout << st.is_empty() << endl;

    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);

    cout << st.peek() << endl;

    st.push(20);

    cout << st.peek() << endl;

    st.pop();

    cout << st.peek() << endl;

    cout << st.is_empty() << endl;

    return 0;
}