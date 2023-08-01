/*
Code Studio
Flatten A Linked List
https://www.codingninjas.com/studio/problems/flatten-a-linked-list_1112655?source=youtube&campaign=YouTube_CodestudioLovebabbar5thfeb&utm_source=youtube&utm_medium=affiliate&utm_campaign=YouTube_CodestudioLovebabbar5thfeb&leftPanelTab=0
*/

class Node
{
public:
    int data;
    Node *next;
    Node *child;
    Node() : data(0), next(nullptr), child(nullptr){};
    Node(int x) : data(x), next(nullptr), child(nullptr) {}
    Node(int x, Node *next, Node *child) : data(x), next(next), child(child) {}
};

Node *merge(Node *&temp1, Node *&temp2)
{
    Node *head = new Node(-1);
    Node *tail = head;

    while (temp1 != nullptr && temp2 != nullptr)
    {
        if (temp1->data < temp2->data)
        {
            tail->child = temp1;
            tail = tail->child;
            temp1 = temp1->child;
        }
        else
        {
            tail->child = temp2;
            tail = tail->child;
            temp2 = temp2->child;
        }
    }

    if (temp1 != nullptr)
    {
        tail->child = temp1;
    }
    else if (temp2 != nullptr)
    {
        tail->child = temp2;
    }

    return head->child;
}

Node *flattenLinkedList(Node *head)
{

    if (head == nullptr || head->next == nullptr)
    {
        return head;
    }

    Node *second = flattenLinkedList(head->next);
    head->next = nullptr;
    head = merge(head, second);
    return head;
}