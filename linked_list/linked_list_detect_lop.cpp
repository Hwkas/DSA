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

void insert_at_head(Node *&head, Node *&tail, int data)
{
    Node *temp = new Node(data);
    if (head == nullptr)
    {
        head = temp;
        tail = temp;
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

Node *floyds_cycle_detection(Node *&head) // loop detection
{
    Node *fast = head;
    Node *slow = head;

    while (fast != nullptr && fast->next != nullptr && slow != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
        {
            return slow;
        }
    }

    return nullptr;
}

Node *cycle_starting_point(Node *&head) // loop starting point
{
    Node *intersertion = floyds_cycle_detection(head);

    if (!intersertion)
    {
        return nullptr;
    }

    Node *slow = head;

    while (slow != intersertion)
    {
        slow = slow->next;
        intersertion = intersertion->next;
    }

    return slow;
}

void remove_loop(Node *&head)
{
    if (head == nullptr)
    {
        return;
    }

    Node *starting_node = cycle_starting_point(head);

    if (!starting_node)
    {
        return;
    }

    Node *temp = starting_node;

    while (starting_node != temp->next)
    {
        temp = temp->next;
    }

    temp->next = nullptr;
}

int main()
{

    Node *head = nullptr;
    Node *tail = nullptr;

    insert_at_head(head, tail, 6);
    insert_at_head(head, tail, 5);
    insert_at_head(head, tail, 4);
    insert_at_head(head, tail, 3);
    insert_at_head(head, tail, 2);
    insert_at_head(head, tail, 1);

    // creating a loop
    Node *temp = head;
    temp = temp->next;
    tail->next = temp;

    // cout << cycle_starting_point(head)->data << endl;

    remove_loop(head);

    print(head);

    return 0;
}