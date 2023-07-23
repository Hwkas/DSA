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

void get_count(Node *&head, int count_arr[])
{
    Node *temp = head;
    while (temp != nullptr)
    {
        count_arr[temp->data]++;
        temp = temp->next;
    }
}

// Normal solution
// void sort_linked_list(Node *&head, int count_arr[])
// {
//     Node *temp = head;
//     for (int i = 0; i < 3; i++)
//     {
//         for (int j = 0; j < count_arr[i]; j++)
//         {
//             temp->data = i;
//             temp = temp->next;
//         }
//     }
// }

// Optimal Time but extra space
// void sort_linked_list(Node *&head, int count_arr[])
// {
//     Node *temp = head;
//     while (temp != nullptr)
//     {
//         if (count_arr[0])
//         {
//             temp->data = 0;
//             count_arr[0]--;
//         }
//         else if (count_arr[1])
//         {
//             temp->data = 1;
//             count_arr[1]--;
//         }
//         else if (count_arr[2])
//         {
//             temp->data = 2;
//             count_arr[2]--;
//         }
//         temp = temp->next;
//     }
// }

void inser_at_tail(Node *&tail, Node *&curr)
{
    tail->next = curr;
    tail = curr;
}

void sort_linked_list(Node *&head)
{

    Node *zero_head = new Node(-1);
    Node *zero_tail = zero_head;

    Node *one_head = new Node(-1);
    Node *one_tail = one_head;

    Node *two_head = new Node(-1);
    Node *two_tail = two_head;

    Node *temp = head;
    while (temp != nullptr)
    {
        if (temp->data == 0)
        {
            inser_at_tail(zero_tail, temp);
        }
        else if (temp->data == 1)
        {
            inser_at_tail(one_tail, temp);
        }
        else if (temp->data == 2)
        {
            inser_at_tail(two_tail, temp);
        }

        temp = temp->next;
    }

    if (one_head->next != nullptr)
    {
        zero_tail->next = one_head->next;
        one_tail->next = two_head->next;
    }
    else
    {
        zero_tail->next = two_head->next;
    }

    two_tail->next = nullptr;

    head = zero_head->next;
}

int main()
{
    Node *head = nullptr;

    insert_at_head(head, 0);
    insert_at_head(head, 1);
    insert_at_head(head, 0);
    insert_at_head(head, 2);
    insert_at_head(head, 2);
    insert_at_head(head, 1);

    print(head);

    int count_arr[3] = {0};

    get_count(head, count_arr);

    // sort_linked_list(head, count_arr);
    sort_linked_list(head);

    print(head);

    return 0;
}
