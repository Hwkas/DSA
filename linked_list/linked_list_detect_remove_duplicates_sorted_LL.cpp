#include <iostream>
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

void detect_n_remove_duplicates(Node *&head)
{
    Node *curr = head;
    Node *forward = head;
    Node *node_to_delete = nullptr;

    while (curr != nullptr)
    {
        forward = curr->next;
        while (forward != nullptr && curr->data == forward->data)
        {
            node_to_delete = forward;
            forward = forward->next;
            node_to_delete->next = nullptr;
            delete node_to_delete;
        }
        curr->next = forward;
        curr = curr->next;
    }
}

int main()
{
    Node *head = nullptr;

    insert_at_head(head, 10);
    insert_at_head(head, 10);
    insert_at_head(head, 10);
    insert_at_head(head, 20);
    insert_at_head(head, 20);
    insert_at_head(head, 30);
    insert_at_head(head, 40);
    insert_at_head(head, 40);
    insert_at_head(head, 40);
    insert_at_head(head, 50);
    insert_at_head(head, 50);
    insert_at_head(head, 50);

    print(head);

    detect_n_remove_duplicates(head);

    print(head);
}