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

void insert_at_head(Node *&head, Node *&tail, int data)
{
    Node *temp = new Node(data);
    if (head == NULL)
    {
        head = temp;
        tail = temp;
        return;
    }
    temp->next = head;
    head = temp;
}

void insert_at_tail(Node *&head, Node *&tail, int data)
{
    Node *temp = new Node(data);
    if (tail == NULL)
    {
        head = temp;
        tail = temp;
        return;
    }
    tail->next = temp;
    tail = temp;
}

void insert_at_position(Node *&head, Node *&tail, int data, int index)
{
    if (index == 0)
    {
        insert_at_head(head, tail, data);
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
        insert_at_tail(head, tail, data);
        return;
    }
    Node *node_to_insert = new Node(data);
    node_to_insert->next = temp->next;
    temp->next = node_to_insert;
}

void delete_at_position(Node *&head, Node *&tail, int index)
{
    Node *temp = head;

    if (index == 0)
    {
        head = head->next;
        temp->next = NULL;
        delete temp;
        return;
    }

    for (int i = 0; i < index - 1; i++)
    {
        temp = temp->next;
        if (temp->next == NULL)
        {
            throw out_of_range("Index out of range");
        }
    }

    Node *node_to_delete = temp->next;
    temp->next = node_to_delete->next;

    if (temp->next == NULL)
    {
        tail = temp;
    }
    node_to_delete->next = NULL;
    delete node_to_delete;
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
    // Node *node1 = new Node(123);

    // Node *head = node1;
    // Node *tail = node1;

    Node *head = NULL;
    Node *tail = NULL;

    insert_at_tail(head, tail, 345);
    // print(head);
    insert_at_tail(head, tail, 678);
    // print(head);

    // insert_at_position(head, tail, 908, 3);
    insert_at_position(head, tail, 908, 2);

    insert_at_tail(head, tail, 456);

    insert_at_head(head, tail, 0);

    print(head);

    // delete_at_position(head, tail, 5);
    delete_at_position(head, tail, 4);

    print(head);

    return 0;
}