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

// Node *reverse_in_k_groups(Node *head, int k)
// {
//     Node *curr = head;
//     Node *prev = nullptr;
//     Node *forward = nullptr;

//     Node *initial_curr = curr;
//     Node *initail_prev = prev;

//     int count = 0;

//     while (curr != nullptr)
//     {
//         forward = curr->next;
//         curr->next = prev;
//         prev = curr;
//         curr = forward;

//         count++;

//         if (count == k)
//         {
//             if (initial_curr == head)
//             {
//                 initial_curr->next = curr;
//                 head = prev;
//             }
//             else
//             {
//                 initail_prev->next = prev;
//                 initial_curr->next = curr;
//             }
//             initail_prev = initial_curr;
//             initial_curr = curr;
//             prev = nullptr;
//             count = 0;
//         }

//         // for premature exit
//         if (curr == nullptr)
//         {
//             initail_prev->next = prev;
//         }
//     }

//     return head;
// }

// recusive function
Node *reverse_in_k_groups(Node *head, int k)
{
    if (head == nullptr || head->next == nullptr)
    {
        return head;
    }

    Node *curr = head;
    Node *prev = nullptr;
    Node *forward = nullptr;

    // int count = 0;

    // while (curr != nullptr && count < k)
    // {
    //     forward = curr->next;
    //     curr->next = prev;
    //     prev = curr;
    //     curr = forward;
    //     count++;
    // }

    for (int i = 0; i < k; i++)
    {
        if (curr == nullptr)
        {
            break;
        }
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
    }

    head->next = reverse_in_k_groups(curr, k);

    return prev;
}

int main()
{
    Node *head = nullptr;

    insert_at_head(head, -1);
    insert_at_head(head, 6);
    insert_at_head(head, 5);
    insert_at_head(head, 4);
    insert_at_head(head, 3);
    insert_at_head(head, 2);
    insert_at_head(head, 1);

    print(head);

    head = reverse_in_k_groups(head, 2);

    print(head);
}