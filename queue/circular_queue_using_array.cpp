#include <iostream>
#include <stdexcept>
using namespace std;

class CricularQueue
{
    int *arr;
    int start;
    int end;
    int size;

public:
    CricularQueue(int size)
    {
        this->size = size;
        arr = new int[size];
        start = end = -1;
    }

    ~CricularQueue()
    {
        delete[] arr;
    }

    bool empty()
    {
        return (start == -1) ? true : false;
    }

    bool full()
    {
        return ((start == 0 && end == size - 1) || (end == (start - 1) % (size - 1))) ? true : false;
    }

    void push(int data)
    {
        if (full())
        {
            throw overflow_error("Queue overflow.");
        }
        if (empty()) // if enter first element
        {
            start++;
        }
        else if ((end == size - 1) && (start != 0)) // if starting blocks are empty.
        {
            end = -1;
        }
        arr[++end] = data;
    }

    void pop()
    {
        if (empty())
        {
            throw underflow_error("Queue underflow.");
        }
        if (start == end) // if only one element to pop.
        {
            start = end - 1;
        }
        else if (start == size - 1) // if start is at end.
        {
            start = 0;
        }
        else
        {
            start++;
        }
    }

    int front()
    {
        if (empty())
        {
            throw underflow_error("Queue underflow.");
        }
        return arr[start];
    }
};

int main()
{
    CricularQueue q(5);

    cout << (q.empty() ? "empty" : "not empty") << endl;
    cout << (q.full() ? "full" : "not full") << endl;

    q.push(5);
    q.push(4);
    q.push(3);
    q.push(2);
    q.push(1);

    cout << (q.full() ? "full" : "not full") << endl;
    cout << (q.empty() ? "empty" : "not empty") << endl;

    // cout << q.front() << endl;
    q.pop();
    q.push(6);
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