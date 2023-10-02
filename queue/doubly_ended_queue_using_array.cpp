#include <stdio.h>
#include <stdexcept>

class Deque
{
    int *arr;
    int front;
    int rear;
    int size;

public:
    Deque(int n)
    {
        arr = new int[n];
        size = n;
        front = rear = -1;
    }

    ~Deque()
    {
        delete[] arr;
    }

    bool pushFront(int x)
    {

        if (isFull())
        {
            return false;
        }
        if (isEmpty())
        {
            front = rear = 0;
        }
        else if (front == 0 && rear != size - 1)
        {
            front = size - 1;
        }
        else
        {
            front--;
        }
        arr[front] = x;
        return true;
    }

    bool pushRear(int x)
    {
        if (isFull())
        {
            return false;
        }
        if (isEmpty())
        {
            front = rear = 0;
        }
        else if (rear == size - 1 && front != 0)
        {
            rear = 0;
        }
        else
        {
            rear++;
        }
        arr[rear] = x;
        return true;
    }

    int popFront()
    {
        if (isEmpty())
        {
            return -1;
        }
        int ans = arr[front];
        if (front == rear)
        {
            front = rear = -1;
        }
        else if (front == size - 1)
        {
            front = 0;
        }
        else
        {
            front++;
        }
        return ans;
    }

    int popRear()
    {
        if (isEmpty())
        {
            return -1;
        }
        int ans = arr[rear];
        if (front == rear)
        {
            front = rear = -1;
        }
        else if (rear == 0)
        {
            rear = size - 1;
        }
        else
        {
            rear--;
        }
        return ans;
    }

    int getFront()
    {
        return (isEmpty()) ? -1 : arr[front];
    }

    int getRear()
    {
        return (isEmpty()) ? -1 : arr[rear];
    }

    bool isEmpty()
    {
        return (front == -1 && rear == -1) ? true : false;
    }

    bool isFull()
    {
        return ((front == 0 && rear == size - 1) || (front != 0 && rear == (front - 1) % (size - 1))) ? true : false;
    }
};