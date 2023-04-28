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
        /*
            Here we need to write the below code because
            - the default destructor will not delete the pointer inside a pointer as
            the all the nodes a dynamically create and each node has pointer inside a pointer.
            - we  need to set the next to null other-wise the delete will recursively delete all the nodes.
        */
        if (this->next != NULL)
        {
            this->next = NULL;
            delete next;
        }
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

void delete_at_position(Node *&head, Node *&tail, int index)
{
    Node *temp = head;

    if (index == 0)
    {
        head = head->next;
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
    Node *node1 = new Node(123);

    Node *head = node1;
    Node *tail = node1;

    insert_at_tail(tail, 345);
    insert_at_tail(tail, 678);

    insert_at_position(head, tail, 908, 3);

    insert_at_tail(tail, 456);

    insert_at_head(head, 0);

    print(head);

    delete_at_position(head, tail, 5);

    print(head);

    while (head != NULL)
    {
        delete_at_position(head, tail, 0);
    }

    return 0;
}