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
        this->next = NULL;
    }

    ~Node()
    {
        if (this->next != NULL)
        {
            delete next;
            this->next = NULL;
        }
    }
};

void insert_at_head(Node *&head, int data)
{
    Node *node_to_insert = new Node(data);

    if (head == NULL)
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

    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

Node *reverser_blocks(Node *head, int n, int arr[])
{
    Node *curr = head;
    Node *prev = nullptr;
    Node *forward = nullptr;

    Node *initial_curr = curr;
    Node *initial_prev = prev;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] > 1)
        {
            for (int j = 0; j < arr[i]; j++)
            {
                if (curr == nullptr)
                {
                    break;
                }
                forward = curr->next;
                curr->next = prev;
                prev = curr;
                curr = forward;
            }

            if (initial_curr == head)
            {
                initial_curr->next = curr;
                head = prev;
            }
            else
            {
                initial_prev->next = prev;
                initial_curr->next = curr;
            }

            if (curr == nullptr)
            {
                return head;
            }
        }
        else if (arr[i] == 1)
        {
            if (curr == nullptr)
            {
                return head;
            }
            curr = curr->next;
        }
        else
        {
            continue;
        }
        initial_prev = initial_curr;
        initial_curr = curr;
        prev = nullptr;
    }

    return head;
}

int main()
{
    Node *head = NULL;

    insert_at_head(head, 10);
    insert_at_head(head, 20);
    insert_at_head(head, 30);
    insert_at_head(head, 40);
    insert_at_head(head, 50);

    print(head);

    int arr[] = {2, 1, 0, 6};

    head = reverser_blocks(head, 4, arr);

    print(head);

    return 0;
}