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

void insert_node(Node *&tail, int element, int data)
{
    Node *node_to_insert = new Node(data);

    if (tail == nullptr)
    {
        tail = node_to_insert;
        node_to_insert->next = node_to_insert;
        return;
    }

    Node *temp = tail;

    while (temp->data != element)
    {
        temp = temp->next;

        if (temp == tail)
        {
            throw runtime_error("element does not exists - can't insert");
        }
    }

    node_to_insert->next = temp->next;
    temp->next = node_to_insert;
}

void print(Node *&tail)
{
    if (tail == nullptr)
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

void delete_node(Node *&tail, int element)
{
    if (tail == nullptr)
    {
        throw runtime_error("the linked list empty, no node to delete");
    }

    Node *temp = tail;
    while (temp->next->data != element)
    {
        temp = temp->next;

        if (temp == tail)
        {
            throw runtime_error("element does not exists - can't delete");
        }
    }

    Node *node_to_delete = temp->next;
    temp->next = node_to_delete->next;

    if (temp == node_to_delete)
    {
        tail = nullptr;
    }
    else if (node_to_delete == tail)
    {
        tail = temp;
    }

    node_to_delete->next = nullptr;
    delete node_to_delete;
}

int main()
{
    // Node *node1 = new Node(10);
    // node1->next = node1;

    // Node *tail = node1;
    Node *tail = nullptr;

    insert_node(tail, 10, 20);
    insert_node(tail, 20, 40);
    insert_node(tail, 20, 60);
    insert_node(tail, 20, 30);
    insert_node(tail, 40, 50);

    print(tail);

    delete_node(tail, 20);

    print(tail);

    insert_node(tail, 11, 21);

    delete_node(tail, 51);

    return 0;
}