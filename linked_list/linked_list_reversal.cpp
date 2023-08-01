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

void insert_at_head(Node *&head, int data)
{
    Node *node_to_insert = new Node(data);

    if (head == nullptr)
    {
        head = node_to_insert;
        return;
    }

    node_to_insert->next = head;
    head = node_to_insert;
}

void print(Node *&head)
{
    Node *temp = head;

    while (temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// line time but big O space complexicity
// void reverse_node(Node *&head)
// {
//     Node *temp = nullptr;

//     while (head != nullptr)
//     {
//         insert_at_head(temp, head->data);
//         head = head->next;
//     }
//     delete head;
//     head = temp;
// }

// Optimal Solution - Linear Time & Constant Space
// void reverse_node(Node *&head)
// {
//     if (head == nullptr || head->next == nullptr)
//     {
//         return;
//     }
//     Node *curr = head;
//     Node *forward = nullptr;
//     Node *prev = nullptr;

//     while (curr != nullptr)
//     {
//         forward = curr->next;
//         curr->next = prev;
//         prev = curr;
//         curr = forward;
//     }

//     head = prev;
// }

// recusrive function for reversing a linked list
// void reverse_node(Node *&head)
// {
//     if (head == nullptr || head->next == nullptr)
//     {
//         return;
//     }

//     Node *rest = head->next;
//     reverse_node(rest);
//     head->next->next = head;
//     head->next = nullptr;

//     head = rest;
// }

// Optimised - recusrive function for reversing a linked list
void reverse_node(Node *&head, Node *curr, Node *prev = nullptr)
{
    if (curr == nullptr)
    {
        head = prev;
        return;
    }

    reverse_node(head, curr->next, curr);
    curr->next = prev;
}

int main()
{
    Node *head = nullptr;

    insert_at_head(head, 10);
    insert_at_head(head, 20);
    insert_at_head(head, 30);
    insert_at_head(head, 40);
    insert_at_head(head, 50);

    print(head);

    // reverse_node(head);
    reverse_node(head, head);

    print(head);

    return 0;
}