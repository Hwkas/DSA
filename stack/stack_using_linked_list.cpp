#include <iostream>
#include <stdexcept>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = nullptr;
    }

    ~Node()
    {
        if (this->next != nullptr)
        {
            delete next;
            this->next = nullptr;
        }
    }
};

class Stack
{
public:
    Node *top;

    Stack()
    {
        this->top = nullptr;
    }

    void push(int data)
    {
        Node *temp = new Node(data);

        if (is_empty())
        {
            top = temp;
            return;
        }

        temp->next = top;
        top = temp;
    }

    void pop()
    {
        if (is_empty())
        {
            throw out_of_range("Stack is empty");
        }

        Node *temp = top->next;

        top->next = nullptr;
        delete top;

        top = temp;
    }

    int peek()
    {
        if (is_empty())
        {
            throw out_of_range("Stack is empty");
        }

        return top->data;
    }

    bool is_empty()
    {
        return top == nullptr ? true : false;
    }
};

int main()
{
    Stack s;

    cout << s.is_empty() << endl;

    s.push(10);
    s.push(20);

    s.pop();
    s.pop();

    s.push(30);

    cout << s.peek() << endl;
    cout << s.is_empty() << endl;

    return 0;
}