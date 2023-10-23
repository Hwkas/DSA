#include <iostream>
#include <stdexcept>
#include <queue>

class Queue
{
    int *arr;
    int size;
    int index;

public:
    Queue(int size)
    {
        this->size = size;
        arr = new int[size];
        index = -1;
    }

    ~Queue()
    {
        if (size > 0)
        {
            delete[] arr;
        }
    }

    bool empty()
    {
        return (index == -1) ? true : false;
    }

    bool full()
    {
        return (index == size - 1) ? true : false;
    }

    void push(int data)
    {
        if (full())
        {
            throw std::overflow_error("Queue overflow.");
        }
        arr[++index] = data;
    }

    void pop()
    {
        if (empty())
        {
            throw std::underflow_error("Queue underflow.");
        }
        arr++;
        index--;
        size--;
    }

    int front()
    {
        if (empty())
        {
            throw std::underflow_error("Queue underflow.");
        }
        return arr[0];
    }
};

void reverse(Queue &old_queue, Queue &new_queue)
{
    if (old_queue.empty())
    {
        return;
    }
    int data = old_queue.front();
    old_queue.pop();
    reverse(old_queue, new_queue);
    new_queue.push(data);
}

// my queue
// int main()
// {
//     Queue q1(5);
//     Queue q2(5);

//     q1.push(1);
//     q1.push(2);
//     q1.push(3);
//     q1.push(4);
//     q1.push(5);

//     reverse(q1, q2);

//     std::cout << q2.front() << std::endl;
//     q2.pop();
//     std::cout << q2.front() << std::endl;
//     q2.pop();
//     std::cout << q2.front() << std::endl;
//     q2.pop();
//     std::cout << q2.front() << std::endl;
//     q2.pop();
//     std::cout << q2.front() << std::endl;
//     return 0;
// }

// Using STL

// void reverse(std::queue<int> &old_queue, std::queue<int> &new_queue)
// {
//     if (old_queue.empty())
//     {
//         return;
//     }
//     int data = old_queue.front();
//     old_queue.pop();
//     reverse(old_queue, new_queue);
//     new_queue.push(data);
// }

void reverse(std::queue<int> &queue)
{
    if (queue.empty())
    {
        return;
    }
    int data = queue.front();
    queue.pop();
    reverse(queue);
    queue.push(data);
}

int main()
{
    std::queue<int> q1;

    q1.push(1);
    q1.push(2);
    q1.push(3);
    q1.push(4);
    q1.push(5);

    std::cout << q1.front() << std::endl;
    q1.pop();
    std::cout << q1.front() << std::endl;
    q1.pop();
    std::cout << q1.front() << std::endl;
    q1.pop();
    std::cout << q1.front() << std::endl;
    q1.pop();
    std::cout << q1.front() << std::endl;
    q1.pop();

    std::cout << "---------------- after reverse ----------------" << std::endl;

    q1.push(1);
    q1.push(2);
    q1.push(3);
    q1.push(4);
    q1.push(5);

    reverse(q1);

    std::cout << q1.front() << std::endl;
    q1.pop();
    std::cout << q1.front() << std::endl;
    q1.pop();
    std::cout << q1.front() << std::endl;
    q1.pop();
    std::cout << q1.front() << std::endl;
    q1.pop();
    std::cout << q1.front() << std::endl;

    return 0;
}