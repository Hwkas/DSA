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

// Solution 1
void create_vector(Node *&head, vector<int> &v)
{
    Node *temp = head;

    while (temp != nullptr)
    {
        v.push_back(temp->data);
        temp = temp->next;
    }
}

bool check_palindrome(Node *&head)
{
    vector<int> v;
    create_vector(head, v);
    int n = v.size();

    for (int i = 0; i < n / 2; i++)
    {
        if (v[i] != v[n - i - 1])
        {
            return false;
        }
    }
    return true;
}

// Solution 2
void create_string(Node *&head, string &s)
{
    Node *temp = head;

    while (temp != nullptr)
    {
        s.push_back('0' + temp->data);
        temp = temp->next;
    }
}

// bool check_palindrome(Node *&head)
// {
//     string s;
//     create_string(head, s);
//     int n = s.size();

//     for (int i = 0; i < n / 2; i++)
//     {
//         if (s[i] != s[n - i - 1])
//         {
//             return false;
//         }
//     }
//     return true;
// }

// Solution 3

Node *find_middle_node(Node *&head)
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

void reverse_linked_list(Node *&mid)
{
    Node *curr = mid->next;
    Node *forward = nullptr;
    Node *prev = nullptr;

    while (curr != nullptr)
    {
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
    }

    mid->next = prev;
}

bool check_palindrome(Node *&head, Node *&mid)
{
    Node *temp1 = head;
    Node *temp2 = mid->next;

    while (temp2 != nullptr)
    {
        if (temp1->data != temp2->data)
        {
            return false;
        }

        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    return true;
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

int main()
{
    Node *head = nullptr;

    insert_at_head(head, 1);
    insert_at_head(head, 2);
    insert_at_head(head, 1);

    print(head);

    Node *mid = find_middle_node(head);

    reverse_linked_list(mid);

    bool ans = check_palindrome(head, mid);

    // bool ans = check_palindrome(head);

    cout << (ans ? "The given linkedlist is a Palindrome."
                 : "The given linked list is not a Palindrome.")
         << endl;

    return 0;
}