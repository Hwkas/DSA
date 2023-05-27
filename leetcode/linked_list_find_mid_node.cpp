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

// Node *get_mid(Node *head)
// {
//     int length = 0;
//     Node *temp = head;

//     while (temp != NULL)
//     {
//         temp = temp->next;
//         length++;
//     }

//     length = length / 2 + 1;

//     for (int i = 1; i < length; i++)
//     {
//         head = head->next;
//     }
//     return head;
// }

// Optimized solution
Node *get_mid(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    if (head->next->next == NULL)
    {
        return head->next;
    }

    Node *slow = head;
    Node *fast = head->next;

    while (fast != NULL)
    {
        fast = fast->next;
        if (fast != NULL)
        {
            fast = fast->next;
        }
        slow = slow->next;
    }
    return slow;
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

    Node *mid = get_mid(head);

    print(mid);

    return 0;
}