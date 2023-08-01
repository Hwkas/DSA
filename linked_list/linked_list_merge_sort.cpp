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

Node *find_middel_node(Node *head)
{
    Node *fast = head;
    Node *slow = head;

    while (fast->next != nullptr && fast->next->next != nullptr)
    {
        fast = fast->next->next;
        slow = slow->next;
    }

    return slow;
}

Node *merge(Node *&temp1, Node *&temp2)
{
    Node *head = new Node(-1);
    Node *tail = head;

    while (temp1 != nullptr && temp2 != nullptr)
    {
        if (temp1->data < temp2->data)
        {
            tail->next = temp1;
            tail = tail->next;
            temp1 = temp1->next;
        }
        else
        {
            tail->next = temp2;
            tail = tail->next;
            temp2 = temp2->next;
        }
    }

    if (temp1 != nullptr)
    {
        tail->next = temp1;
    }
    else if (temp2 != nullptr)
    {
        tail->next = temp2;
    }

    return head->next;
}

Node *merge_sort(Node *head)
{
    if (head->next == nullptr)
    {
        return head;
    }

    Node *mid = find_middel_node(head);
    Node *left = head;
    Node *right = mid->next;
    mid->next = nullptr;

    left = merge_sort(left);
    right = merge_sort(right);

    Node *merged_linked_list = merge(left, right);
    return merged_linked_list;
}

int main()
{

    Node *head = nullptr;

    insert_at_head(head, 3);
    insert_at_head(head, 2);
    insert_at_head(head, 1);
    insert_at_head(head, 4);

    print(head);

    head = merge_sort(head);

    print(head);

    return 0;
}