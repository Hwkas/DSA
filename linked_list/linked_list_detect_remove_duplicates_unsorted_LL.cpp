#include <iostream>
#include <unordered_map>
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

// Brute Force Solution
// void detect_n_remove_duplicates(Node *&head)
// {
//     Node *curr = head;
//     Node *temp = nullptr;
//     Node *prev = nullptr;

//     while (curr != nullptr)
//     {
//         prev = curr;
//         temp = curr->next;
//         while (temp != nullptr)
//         {
//             if (curr->data == temp->data)
//             {
//                 prev->next = temp->next;
//                 temp->next = nullptr;
//                 delete temp;
//                 temp = prev->next;
//             }
//             else
//             {
//                 prev = prev->next;
//                 temp = temp->next;
//             }
//         }
//         curr = curr->next;
//     }
// }

// Optimal solution
void detect_n_remove_duplicates(Node *&head)
{
    unordered_map<int, bool> value_record;
    Node *curr = head->next;
    Node *prev = head;
    value_record[prev->data] = true;
    while (curr != nullptr)
    {
        if (value_record[curr->data])
        {
            prev->next = curr->next;
            curr->next = nullptr;
            delete curr;
            curr = prev->next;
        }
        else
        {
            value_record[curr->data] = true;
            prev = curr;
            curr = curr->next;
        }
    }
}

int main()
{
    Node *head = nullptr;

    insert_at_head(head, 10);
    insert_at_head(head, 40);
    insert_at_head(head, 50);
    insert_at_head(head, 50);
    insert_at_head(head, 20);
    insert_at_head(head, 30);
    insert_at_head(head, 40);
    insert_at_head(head, 10);
    insert_at_head(head, 20);
    insert_at_head(head, 40);
    insert_at_head(head, 50);
    insert_at_head(head, 10);

    print(head);

    detect_n_remove_duplicates(head);

    print(head);
}