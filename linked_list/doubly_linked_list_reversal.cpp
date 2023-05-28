#include <iostream>
#include <stdexcept>
using namespace std;

class Node
{
public:
    Node *previous;
    int data;
    Node *next;

    Node(int data)
    {
        this->previous = nullptr;
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

void print_from_head(Node *&head)
{
    cout << "Printing from head:  ";
    Node *temp = head;
    while (temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void insert_at_head(Node *&head, Node *&tail, int data)
{
    Node *node_to_insert = new Node(data);
    if (head == nullptr)
    {
        head = node_to_insert;
        tail = node_to_insert;
        return;
    }
    node_to_insert->next = head;
    head->previous = node_to_insert;
    head = node_to_insert;
}

// Node *reverse_nodes(Node *head)
// {
//     Node *forward = nullptr;
//     Node *prev = nullptr;

//     while (head->next != nullptr)
//     {
//         forward = head->next;
//         prev = head->previous;

//         head->next = prev;
//         head->previous = forward;
//         head = head->previous;
//     }

//     head->next = head->previous;
//     head->previous = nullptr;

//     return head;
// }

// recursive sol
Node *reverse_nodes(Node *head)
{
    if (head == nullptr || head->next == nullptr)
    {
        head->next = head->previous;
        head->previous = nullptr;
        return head;
    }

    Node *forward = nullptr;

    forward = head->next;
    head->next = head->previous;
    head->previous = reverse_nodes(forward);

    return head->previous;
}

int main()
{
    Node *head = nullptr;
    Node *tail = nullptr;

    insert_at_head(head, tail, 20);
    insert_at_head(head, tail, 30);
    insert_at_head(head, tail, 40);
    insert_at_head(head, tail, 50);

    print_from_head(head);

    head = reverse_nodes(head);

    print_from_head(head);

    return 0;
}