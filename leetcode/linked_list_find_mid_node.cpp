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

// Node *get_mid(Node *head)
// {
//     int length = 0;
//     Node *temp = head;

//     while (temp != nullptr)
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
    if (head == nullptr || head->next == nullptr)
    {
        return head;
    }

    if (head->next->next == nullptr)
    {
        return head->next;
    }

    Node *slow = head;
    Node *fast = head->next;

    while (fast != nullptr)
    {
        fast = fast->next;
        if (fast != nullptr)
        {
            fast = fast->next;
        }
        slow = slow->next;
    }
    return slow;
}

int main()
{
    Node *head = nullptr;

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