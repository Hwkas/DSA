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

void print_circlular_list_linked(Node *&head)
{

    Node *temp = head;
    do
    {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);

    cout << endl;
}

// Solution with linear time
// Node *find_midddle_node(Node *&head)
// {
//     if (head == nullptr || head->next == head)
//     {
//         throw invalid_argument("Not enought nodes to split");
//     }

//     Node *fast = head;
//     Node *slow = head;

//     int counter = 0;

//     /*
//     The only difference between the two different while loops is:
//     - The first one divides the odd number of nodes like 5 nodes into a pair of 2 & 3.
//     - The second one divides the odd number of nodes like 5 nodes into a pair of 3 & 2.
//     */

//     while (fast->next != head && fast->next->next != head)
//     // while (fast->next != head)
//     {
//         fast = fast->next;
//         counter++;

//         if (counter == 2)
//         {
//             slow = slow->next;
//             counter = 0;
//         }
//     }

//     return slow;
// }

// Optimized Solution
Node *find_midddle_node(Node *&head)
{
    if (head == nullptr || head->next == head)
    {
        throw invalid_argument("Not enought nodes to split");
    }

    Node *fast = head;
    Node *slow = head;

    while (fast->next != head && fast->next->next != head)
    {
        fast = fast->next->next;
        slow = slow->next;
    }

    return slow;
}

int main()
{
    Node *head = nullptr;
    Node *tail = nullptr;

    insert_at_head(head, tail, 10);
    insert_at_head(head, tail, 20);
    insert_at_head(head, tail, 30);
    insert_at_head(head, tail, 40);
    insert_at_head(head, tail, 50);
    insert_at_head(head, tail, 60);

    print(head);

    tail->next = head;

    Node *mid = find_midddle_node(head);
    cout << mid->data << endl;
    Node *second_head = mid->next;

    // Creating two circular linked lists
    tail->next = second_head;
    mid->next = head;

    print_circlular_list_linked(head);
    print_circlular_list_linked(second_head);

    return 0;
}