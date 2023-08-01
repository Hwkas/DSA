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

void reverse_linked_list(Node *&head)
{
    Node *curr = head;
    Node *prev = nullptr;
    Node *forward = nullptr;

    while (curr != nullptr)
    {
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
    }

    head = prev;
}

Node *add_linked_list(Node *&head1, Node *&head2)
{
    Node *ans = nullptr;
    int sum = 0;
    int carry = 0;
    while (head1 != nullptr && head2 != nullptr)
    {
        sum = head1->data + head2->data + carry;
        carry = 0;

        if (sum >= 10)
        {
            carry = sum / 10;
        }

        insert_at_head(ans, sum % 10);

        head1 = head1->next;
        head2 = head2->next;
    }

    while (head1 != nullptr)
    {
        sum = head1->data + carry;
        carry = 0;

        if (sum >= 10)
        {
            carry = sum / 10;
        }
        insert_at_head(ans, sum % 10);
        head1 = head1->next;
    }

    while (head2 != nullptr)
    {
        sum = head2->data + carry;
        carry = 0;

        if (sum >= 10)
        {
            carry = sum / 10;
        }
        insert_at_head(ans, sum % 10);
        head2 = head2->next;
    }

    if (carry)
    {
        insert_at_head(ans, carry);
    }

    return ans;
}

int main()
{
    Node *head1 = nullptr;
    Node *head2 = nullptr;

    insert_at_head(head1, 2);
    insert_at_head(head1, 3);
    insert_at_head(head1, 0);
    insert_at_head(head1, 7);
    insert_at_head(head1, 7);

    insert_at_head(head2, 0);
    insert_at_head(head2, 6);
    insert_at_head(head2, 6);
    insert_at_head(head2, 9);
    insert_at_head(head2, 2);

    print(head1);
    print(head2);

    reverse_linked_list(head1);
    reverse_linked_list(head2);

    Node *ans = add_linked_list(head1, head2);

    print(ans);

    return 0;
}