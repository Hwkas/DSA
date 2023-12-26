#include <iostream>
#include <queue>
#include <stack>

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int data)
    {
        this->data = data;
        left = right = nullptr;
    }

    ~Node()
    {
        if (this->left != nullptr && this->right != nullptr)
        {
            delete left;
            delete right;
            this->right = this->left = nullptr;
        }
    }
};

Node *build_tree(Node *root)
{
    int data;
    std::cout << "Enter your desired data: ";
    std::cin >> data;
    root = new Node(data);
    if (data == -1)
    {
        return nullptr;
    }
    std::cout << "Enter data for left of " << data << std::endl;
    root->left = build_tree(root->left);
    std::cout << "Enter data for right of " << data << std::endl;
    root->right = build_tree(root->right);
    return root;
}

void level_order_traversal(Node *root)
{
    std::cout << std::endl
              << "Level Order Traversal:" << std::endl;
    std::queue<Node *> q;
    q.push(root);
    q.push(nullptr);

    Node *temp;
    while (!q.empty())
    {
        temp = q.front();
        q.pop();
        if (temp == nullptr)
        {
            std::cout << std::endl;
            if (q.empty())
            {
                return;
            }
            q.push(nullptr);
            continue;
        }
        std::cout << temp->data << " ";
        if (temp->left)
        {
            q.push(temp->left);
        }
        if (temp->right)
        {
            q.push(temp->right);
        }
    }
}

void reverse_level_order_traversal(Node *root)
{
    std::cout << std::endl
              << "Reverse Level Order Traversal:";
    std::queue<Node *> q;
    std::stack<Node *> s;
    q.push(root);
    q.push(nullptr);
    s.push(root);
    s.push(nullptr);

    Node *temp;
    while (!q.empty())
    {
        temp = q.front();
        q.pop();
        if (temp == nullptr)
        {
            if (q.empty())
            {
                break;
            }
            q.push(nullptr);
            s.push(nullptr);
            continue;
        }
        if (temp->right)
        {
            q.push(temp->right);
            s.push(temp->right);
        }
        if (temp->left)
        {
            q.push(temp->left);
            s.push(temp->left);
        }
    }

    int n = s.size();
    for (int i = 0; i < n; i++)
    {
        temp = s.top();
        s.pop();
        (temp) ? std::cout << temp->data << " " : std::cout << std::endl;
    }
}

int main()
{
    Node *root = nullptr;
    root = build_tree(root); // input: 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    level_order_traversal(root);
    reverse_level_order_traversal(root);
}