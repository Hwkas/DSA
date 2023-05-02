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
        this->previous = NULL;
        this->data = data;
        this->next = NULL;
    }
};

void print_from_head(Node *&head)
{
    cout << "Printing from head:  ";
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void print_from_tail(Node *&tail)
{
    cout << "Printing from tail:  ";
    Node *temp = tail;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->previous;
    }
    cout << endl;
}

int get_lenght(Node *&head)
{
    Node *temp = head;
    int length = 0;
    while (temp != NULL)
    {
        length++;
        temp = temp->next;
    }
    return length;
}

void insert_at_head(Node *&head, int data)
{
    Node *node_to_insert = new Node(data);
    node_to_insert->next = head;
    head->previous = node_to_insert;
    head = node_to_insert;
}

void insert_at_tail(Node *&tail, int data)
{
    Node *node_to_insert = new Node(data);
    node_to_insert->previous = tail;
    tail->next = node_to_insert;
    tail = node_to_insert;
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
    node_to_insert->previous = temp;
    temp->next = node_to_insert;
    node_to_insert->next->previous = node_to_insert;
}

int main()
{
    // we can simply just name the node1 as head & the programm will still work as same.
    Node *node1 = new Node(10);

    Node *head = node1;
    Node *tail = node1;

    insert_at_head(head, 20);
    insert_at_head(head, 30);
    insert_at_head(head, 40);
    insert_at_head(head, 50);

    insert_at_position(head, tail, 0, 0);
    insert_at_position(head, tail, 1, 3);
    insert_at_position(head, tail, 2, 5);

    insert_at_tail(tail, 60);
    insert_at_tail(tail, 70);
    insert_at_tail(tail, 80);
    insert_at_tail(tail, 90);
    insert_at_tail(tail, 100);

    insert_at_position(head, tail, 3, 9);
    insert_at_position(head, tail, 4, 14);

    print_from_head(head);
    print_from_tail(tail);
    cout << get_lenght(head) << endl;

    return 0;
}