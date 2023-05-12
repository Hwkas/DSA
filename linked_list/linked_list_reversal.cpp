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
        this->next = NULL;
    }

    ~Node()
    {
        if (this->next != NULL)
        {
            delete next;
            this->next = NULL;
        }
    }
};

void insert_at_head(Node *&head, int data)
{
    Node *node_to_insert = new Node(data);

    if (head == NULL)
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

    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// line time but big O space complexicity
// void reverse_node(Node *&head)
// {
//     Node *temp = NULL;

//     while (head != NULL)
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
//     if (head == NULL || head->next == NULL)
//     {
//         return;
//     }
//     Node *curr = head;
//     Node *forward = NULL;
//     Node *prev = NULL;

//     while (curr != NULL)
//     {
//         forward = curr->next;
//         curr->next = prev;
//         prev = curr;
//         curr = forward;
//     }

//     head = prev;
// }

// recusrive function for reversing a linked list
void reverse_node(Node *&head)
{
    if (head == NULL || head->next == NULL)
    {
        return;
    }

    Node *rest = head->next;
    reverse_node(rest);
    head->next->next = head;
    head->next = NULL;

    head = rest;
}

int main()
{
    Node *head = NULL;

    insert_at_head(head, 10);
    insert_at_head(head, 20);
    insert_at_head(head, 30);
    insert_at_head(head, 40);
    insert_at_head(head, 50);

    print(head);

    reverse_node(head);

    print(head);

    return 0;
}