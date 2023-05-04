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

void insert_node(Node *&tail, int element, int data)
{
    Node *temp = tail;

    while (temp->data != element)
    {
        temp = temp->next;
    }

    Node *node_to_insert = new Node(data);
    node_to_insert->next = temp->next;
    temp->next = node_to_insert;
}

void print(Node *&tail)
{
    Node *temp = tail->next;
    while (temp != tail)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << temp->data << " ";
    cout << endl;
}

int main()
{
    Node *node1 = new Node(10);
    node1->next = node1;

    Node *tail = node1;

    insert_node(tail, 10, 20);

    insert_node(tail, 10, 40);

    print(tail);

    return 0;
}