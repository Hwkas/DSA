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
    Node *temp = new Node(data);

    if (head == nullptr)
    {
        head = temp;
        return;
    }

    temp->next = head;
    head = temp;
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

// Solution 1
// Node *merge_linked_list(Node *&temp1, Node *&temp2)
// {
//     Node *head = new Node(-1);
//     Node *tail = head;

//     while (temp1 != nullptr && temp2 != nullptr)
//     {
//         if (temp1->data < temp2->data)
//         {
//             tail->next = temp1;
//             tail = tail->next;
//             temp1 = temp1->next;
//         }
//         else
//         {
//             tail->next = temp2;
//             tail = tail->next;
//             temp2 = temp2->next;
//         }
//     }

//     if (temp1 != nullptr)
//     {
//         tail->next = temp1;
//     }
//     else if (temp2 != nullptr)
//     {
//         tail->next = temp2;
//     }

//     return head->next;
// }

// Solution 2
Node *merge_linked_list(Node *temp1, Node *temp2)
{

    // if only one element present in temp1 List
    if (temp1->next == NULL)
    {
        temp1->next = temp2;
        return temp1;
    }

    Node *curr1 = temp1;
    Node *next1 = curr1->next;
    Node *curr2 = temp2;
    Node *next2 = curr2->next;

    while (next1 != NULL && curr2 != NULL)
    {

        // if say data is range me liye  kar ta hai
        if ((curr2->data >= curr1->data) && (curr2->data <= next1->data))
        {
            // add nodes in between the temp1 list
            curr1->next = curr2;
            next2 = curr2->next;
            curr2->next = next1;

            // pointers ko age badaya
            curr1 = curr2;
            curr2 = next2;
        }
        // else say data is range me liye nhi karta hai
        else
        {
            // pointers ko age badaya
            curr1 = next1;
            next1 = next1->next;
            // next 1 ko next bhej rahe hai pr check karna hai ki ye null nhi ho jaye uske liya ye condition hai..

            if (next1 == NULL)
            {
                curr1->next = curr2;
                return temp1;
            }
        }
    }
    return temp1;
}

int main()
{
    Node *head1 = nullptr;
    Node *head2 = nullptr;

    insert_at_head(head1, 5);
    insert_at_head(head1, 4);
    insert_at_head(head1, 1);

    insert_at_head(head2, 7);
    insert_at_head(head2, 5);
    insert_at_head(head2, 3);
    insert_at_head(head2, 2);

    print(head1);
    print(head2);

    // Node *head = merge_linked_list(head1, head2);
    // print(head);

    if (head1->data < head2->data)
    {
        Node *head = merge_linked_list(head1, head2);
        print(head);
    }
    else
    {
        Node *head = merge_linked_list(head2, head1);
        print(head);
    }

    return 0;
}