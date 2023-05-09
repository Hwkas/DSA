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
    Node *node_to_insert = new Node(data);

    if (tail == NULL)
    {
        tail = node_to_insert;
        node_to_insert->next = node_to_insert;
        return;
    }

    Node *temp = tail;

    while (temp->data != element)
    {
        temp = temp->next;
    }

    node_to_insert->next = temp->next;
    temp->next = node_to_insert;
}

void print(Node *&tail)
{
    if (tail == NULL)
    {
        throw out_of_range("linked list is empty");
    }

    Node *temp = tail;

    do
    {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != tail);
    cout << endl;
}

void delete_by_element(Node *&tail, int element)
{
    if (tail == NULL)
    {
        throw runtime_error("the linked list empty, no node to delete");
    }

    Node *temp = tail;
    while (temp->next->data != element)
    {
        temp = temp->next;
    }

    Node *node_to_delete = temp->next;
    temp->next = node_to_delete->next;

    if (temp == node_to_delete)
    {
        tail = NULL;
    }
    else if (node_to_delete == tail)
    {
        tail = temp;
    }

    node_to_delete->next = NULL;
    delete node_to_delete;
}

int main()
{
    // Node *node1 = new Node(10);
    // node1->next = node1;

    // Node *tail = node1;
    Node *tail = NULL;

    insert_node(tail, 10, 20);
    // insert_node(tail, 20, 40);
    // insert_node(tail, 20, 60);
    // insert_node(tail, 20, 30);
    // insert_node(tail, 40, 50);

    print(tail);

    delete_by_element(tail, 20);

    print(tail);

    return 0;
}