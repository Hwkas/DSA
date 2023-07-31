#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *random;

    Node(int data)
    {
        this->data = data;
        this->next = nullptr;
        this->random = nullptr;
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

void insert_at_tail(Node *&head, Node *&tail, int data)
{
    Node *temp = new Node(data);
    if (head == nullptr)
    {
        head = temp;
        tail = temp;
        return;
    }
    tail->next = temp;
    tail = temp;
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

void print_random_data(Node *&head)
{
    Node *temp = head;

    while (temp != nullptr)
    {
        cout << temp->random->data << " ";
        temp = temp->next;
    }

    cout << endl;
}

// Normal Solution
// void copy_linked_list(Node *&head, Node *&ans, Node *&ans_tail)
// {
//     Node *temp1 = head;
//     Node *temp2 = ans;

//     // creating a new linked list
//     while (temp1 != nullptr)
//     {
//         insert_at_tail(ans, ans_tail, temp1->data);
//         temp1 = temp1->next;
//     }

//     temp1 = head;
//     temp2 = ans;

//     unordered_map<Node *, Node *> map;

//     // creating a map of both the linked lists
//     while (temp1 != nullptr)
//     {
//         map[temp1] = temp2;
//         temp1 = temp1->next;
//         temp2 = temp2->next;
//     }

//     temp1 = head;
//     temp2 = ans;

//     // setting random pointer of copied linked list
//     while (temp1 != nullptr)
//     {
//         if (temp1->random != nullptr)
//         {
//             temp2->random = map[temp1->random];
//         }

//         temp1 = temp1->next;
//         temp2 = temp2->next;
//     }
// }

// Optimised Solution
void copy_linked_list(Node *&head, Node *&ans, Node *&ans_tail)
{
    Node *temp1 = head;
    Node *temp2 = ans;

    // creating a new linked list
    while (temp1 != nullptr)
    {
        insert_at_tail(ans, ans_tail, temp1->data);
        temp1 = temp1->next;
    }

    temp1 = head;
    temp2 = ans;

    Node *forward1 = temp1;
    Node *forward2 = temp2;

    // connecting both linked lists
    while (forward1 != nullptr)
    {
        forward1 = temp1->next;
        forward2 = temp2->next;
        temp1->next = temp2;
        temp2->next = forward1;

        temp1 = forward1;
        temp2 = forward2;
    }

    temp1 = head;

    // setting random pointer for copied linked list
    while (temp1 != nullptr)
    {
        if (temp1->random != nullptr)
        {
            temp1->next->random = temp1->random->next;
        }

        temp1 = temp1->next->next;
    }

    temp1 = head;
    temp2 = ans;

    // separating the two linked lists
    while (temp2 != nullptr)
    {
        temp1->next = temp2->next;
        if (temp2->next == nullptr)
        {
            return;
        }

        temp2->next = temp2->next->next;

        temp1 = temp1->next;
        temp2 = temp2->next;
    }
}

int main()
{
    Node *head = nullptr;
    Node *tail = nullptr;

    insert_at_tail(head, tail, 1);
    insert_at_tail(head, tail, 2);
    insert_at_tail(head, tail, 3);
    insert_at_tail(head, tail, 4);
    insert_at_tail(head, tail, 5);

    // creating random pointers
    head->random = head->next->next;                         // 1 -> 3
    head->next->random = head;                               // 2 -> 1
    head->next->next->next->random = head->next->next;       // 4 -> 3
    head->next->next->random = head->next->next->next->next; // 3 -> 5
    head->next->next->next->next->random = head->next;       // 5 -> 2

    print(head);

    Node *ans = nullptr;
    Node *ans_tail = nullptr;

    copy_linked_list(head, ans, ans_tail);

    print(ans);

    print_random_data(head);
    print_random_data(ans);

    return 0;
}