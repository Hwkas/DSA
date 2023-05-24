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

void reverse_blocks(int start, int itter_count, Node *&head, Node *curr, Node *prev = NULL, Node *forward = NULL)
{

    for (int i = 0; i < start; i++)
    {
        prev = curr;
        curr = curr->next;
    }

    Node *initial_curr = curr;
    Node *initial_prev = prev;

    for (int i = 0; i < itter_count; i++)
    {
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
    }

    if (initial_curr == head)
    {
        head->next = curr;
        head = prev;
    }
    else
    {
        initial_prev->next = prev;
        initial_curr->next = curr;
    }
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

    int arr[] = {2, 3};
    int start = 0;
    for (int i = 0; i < 2; i++)
    {
        reverse_blocks(start, arr[i], head, head);
        start += arr[i];
    }

    print(head);

    return 0;
}