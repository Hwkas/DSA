#include <iostream>
#include <stdexcept>
using namespace std;

class Queue
{
    int *arr;
    int size;
    int index;

public:
    Queue(int size)
    {
        arr = new int[size];
        this->size = size;
        index = -1;
    }

    ~Queue()
    {
        if (size > 0)
        {
            delete[] arr;
        }
    }

    int empty()
    {
        return (index == -1) ? true : false;
    }

    int full()
    {
        return (index == size - 1) ? true : false;
    }

    void push(int data)
    {
        if (full())
        {
            throw out_of_range("Queue overflow!");
        }

        arr[++index] = data;
    }

    void pop()
    {
        if (empty())
        {
            throw out_of_range("Queue underflow!");
        }

        arr++;
        index--;
        size--;
    }

    int front()
    {
        if (empty())
        {
            throw out_of_range("Queue underflow!");
        }
        return arr[0];
    }
};

int main()
{
    Queue q(5);

    cout << (q.empty() ? "empty" : "not empty") << endl;
    cout << (q.full() ? "full" : "not full") << endl;

    q.push(5);
    q.push(4);
    q.push(3);
    q.push(2);
    q.push(1);

    cout << (q.full() ? "full" : "not full") << endl;
    cout << (q.empty() ? "empty" : "not empty") << endl;

    cout << q.front() << endl;
    q.pop();
    cout << q.front() << endl;
    q.pop();
    cout << q.front() << endl;
    q.pop();
    cout << q.front() << endl;
    q.pop();
    cout << q.front() << endl;
    q.pop();
    cout << (q.empty() ? "empty" : "not empty") << endl;

    return 0;
}