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
};

void insert_at_head(Node *&head, int data)
{
    Node *temp = new Node(data);
    temp->next = head;
    head = temp;
}

void insert_at_tail(Node *&tail, int data)
{
    Node *temp = new Node(data);
    tail->next = temp;
    tail = temp;
}

void insert_at_position(Node *&head, Node *&tail, int data, int index)
{
    if (index == 0)
    {
        insert_at_head(head, data);
        return;
    }

    Node *temp = head;

    for (int i = 0; i < index - 1; i++)
    {
        temp = temp->next;
        if (temp == NULL)
        {
            throw out_of_range("Index out of range");
        }
    }

    if (temp->next == NULL)
    {
        insert_at_tail(tail, data);
        return;
    }
    Node *node_to_insert = new Node(data);
    node_to_insert->next = temp->next;
    temp->next = node_to_insert;
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

int main()
{
    Node *node1 = new Node(123);

    Node *head = node1;
    Node *tail = node1;

    insert_at_tail(tail, 345);
    insert_at_tail(tail, 678);

    insert_at_position(head, tail, 908, 3);

    insert_at_tail(tail, 456);

    insert_at_head(head, 0);

    print(head);

    return 0;
}