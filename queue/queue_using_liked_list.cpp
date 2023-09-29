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
        next = nullptr;
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

class Queue
{
    Node *start;
    Node *end;

public:
    Queue()
    {
        this->start = nullptr;
        this->end = nullptr;
    }

    ~Queue()
    {
        delete start;
    }

    bool empty()
    {
        return (this->start == nullptr) ? true : false;
    }

    void push(int data)
    {
        Node *temp = new Node(data);

        if (empty())
        {
            start = temp;
            end = temp;
        }
        end->next = temp;
        end = temp;
    }

    void pop()
    {
        if (empty())
        {
            throw out_of_range("Queue is empty.");
        }

        Node *temp = start;
        start = start->next;
        if (start == nullptr)
        {
            end = start;
        }
        temp->next = nullptr;
        delete temp;
    }

    int front()
    {
        if (empty())
        {
            throw out_of_range("Queue is empty.");
        }
        return start->data;
    }
};

// int main()
// {
//     Queue q;

//     cout << (q.empty() ? "empty" : "not empty") << endl;

//     q.push(5);
//     q.push(4);
//     q.push(3);
//     q.push(2);
//     q.push(1);

//     cout << (q.empty() ? "empty" : "not empty") << endl;

//     cout << q.front() << endl;
//     q.pop();
//     cout << q.front() << endl;
//     q.pop();
//     cout << q.front() << endl;
//     q.pop();
//     cout << q.front() << endl;
//     q.pop();
//     cout << q.front() << endl;
//     q.pop();
//     cout << (q.empty() ? "empty" : "not empty") << endl;

//     return 0;
// }

int main()
{
    Queue myQueue;

    // Test 1: Check if the queue is initially empty
    cout << "Test 1: Is the queue empty? " << (myQueue.empty() ? "Yes" : "No") << endl;

    // Test 2: Add elements to the queue and check front
    myQueue.push(1);
    myQueue.push(2);
    myQueue.push(3);
    cout << "Test 2: Front of the queue: " << myQueue.front() << endl; // Expected output: 1

    // Test 3: Pop elements and check front
    myQueue.pop();
    cout << "Test 3: Front after one pop: " << myQueue.front() << endl; // Expected output: 2
    myQueue.pop();
    myQueue.pop();
    cout << "Test 3: Is the queue empty after popping all elements? " << (myQueue.empty() ? "Yes" : "No") << endl; // Expected output: Yes

    // Test 4: Attempt to pop from an empty queue and handle the exception
    try
    {
        myQueue.pop(); // Attempt to pop from an empty queue
    }
    catch (const out_of_range &e)
    {
        cout << "Test 4: Exception when popping from an empty queue: " << e.what() << endl;
    }

    // Test 5: Push additional elements and check front
    myQueue.push(4);
    myQueue.push(5);
    cout << "Test 5: Front of the queue after pushing more elements: " << myQueue.front() << endl; // Expected output: 4

    // Test 6: Check if the queue is empty after pushing more elements
    cout << "Test 6: Is the queue empty after pushing more elements? " << (myQueue.empty() ? "Yes" : "No") << endl; // Expected output: No

    return 0;
}