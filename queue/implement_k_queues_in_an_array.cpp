#include <iostream>
#include <stdexcept>

// template <typename T>
class NQueue
{
    int *arr;
    int *next;
    int *first;
    int *last;
    int free_spot;

public:
    NQueue(int n, int s) // n = no. of queues, s = size of array
    {
        arr = new int[s];
        next = new int[s];
        first = new int[n];
        last = new int[n];
        free_spot = 0;

        for (int i = 0; i < s; i++)
        {
            if (i < n)
            {
                first[i] = last[i] = -1;
            }
            next[i] = i + 1;
        }
        next[s - 1] = -1;
    }

    ~NQueue()
    {
        delete[] arr;
        delete[] next;
        delete[] first;
    }

    void push(int data, int qn)
    {
        if (free_spot == -1)
        {
            throw std::overflow_error("Queue - " + std::to_string(qn) + " overflow!");
        }

        int index = free_spot;
        free_spot = next[index]; // updating free_spot
        arr[index] = data;       // update arr with index of value of free_spot
        next[index] = -1;        // updating index to -1, to mark it as the last element of the q.
        /*
            if it is the first element of a queue update the first & last array with value of index
            else updating the next's previous to hold the next's current index
        */
        (first[qn - 1] == -1) ? first[qn - 1] = index : next[last[qn - 1]] = index;
        last[qn - 1] = index; // updating last to hold the index of last element of q
    }

    void pop(int qn)
    {
        int index = first[qn - 1];
        if (index == -1)
        {
            throw std::underflow_error("Queue - " + std::to_string(qn) + " underflow!");
        }
        else if (index == last[qn - 1]) // this is not need
        {
            last[qn - 1] = -1;
        }
        first[qn - 1] = next[index];
        next[index] = free_spot;
        free_spot = index;
    }

    int front(int qn)
    {
        int index = first[qn - 1];
        if (index == -1)
        {
            throw std::underflow_error("Queue - " + std::to_string(qn) + " underflow!");
        }
        return arr[index];
    }
};

int main()
{
    NQueue q(3, 6);

    q.push(10, 1);
    q.push(22, 1);
    q.push(30, 2);
    q.push(40, 2);

    // std::cout << q.front(1) << std::endl;
    // std::cout << q.front(2) << std::endl;

    // q.pop(1);
    q.pop(2);
    // q.pop(1);
    q.pop(2);

    q.push(11, 1);
    q.push(55, 2);
    // q.push(33, 2);
    q.pop(1);
    q.pop(2);
    // q.pop(2);
    q.push(99, 2);

    std::cout << q.front(1) << std::endl;
    std::cout << q.front(2) << std::endl;
    return 0;
}
