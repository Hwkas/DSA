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

// my code
Node *build_tree()
{
    int data;
    std::cout << "Enter your desired data: ";
    std::cin >> data;
    Node *root = new Node(data);
    if (data == -1)
    {
        return nullptr;
    }
    std::cout << "Enter data for left of " << data << std::endl;
    root->left = build_tree();
    std::cout << "Enter data for right of " << data << std::endl;
    root->right = build_tree();
    return root;
}

void build_tree_by_level_order(Node *&root)
{
    std::queue<Node *> q;
    int data;
    std::cout << "Enter the data for root: ";
    std::cin >> data;
    root = new Node(data);
    q.push(root);
    Node *temp;

    while (!q.empty())
    {
        temp = q.front();
        q.pop();
        std::cout << "Enter data for left of " << temp->data << std::endl;
        std::cin >> data;
        std::cout << std::endl;
        if (data != -1)
        {
            temp->left = new Node(data);
            q.push(temp->left);
        }
        std::cout << "Enter data for right of " << temp->data << std::endl;
        std::cin >> data;
        std::cout << std::endl;
        if (data != -1)
        {
            temp->right = new Node(data);
            q.push(temp->right);
        }
    }
}

void level_order_traversal(Node *&root)
{
    std::queue<Node *> q;
    q.push(root);
    q.push(nullptr);

    std::cout << std::endl
              << "Level order traversal of Binary Tree" << std::endl;
    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();

        if (temp == nullptr)
        {
            std::cout << std::endl;
            if (!q.empty())
            {
                q.push(nullptr);
            }
        }
        else
        {
            std::cout << temp->data << " ";
            if (temp && temp->left)
            {
                q.push(temp->left);
            }
            if (temp && temp->right)
            {
                q.push(temp->right);
            }
        }
    }
}

// --------------------------------------------------------- Recursion --------------------------------------------------------

void in_order_traversal(Node *root) // LNR
{
    if (root == nullptr)
    {
        return;
    }

    in_order_traversal(root->left);
    std::cout << root->data << " ";
    in_order_traversal(root->right);
}

void pre_order_traversal(Node *root) // NLR
{
    if (root == nullptr)
    {
        return;
    }
    std::cout << root->data << " ";
    pre_order_traversal(root->left);
    pre_order_traversal(root->right);
}

void post_order_traversal(Node *root) // LRN
{
    if (root == nullptr)
    {
        return;
    }

    post_order_traversal(root->left);
    post_order_traversal(root->right);
    std::cout << root->data << " ";
}

// --------------------------------------------------------- Loop -------------------------------------------------------------

void in_order_traversal(Node *&root, int i) // LNR
{
    if (!root)
    {
        return;
    }

    std::stack<Node *> s;
    s.push(root);
    Node *temp;

    while (!s.empty())
    {
        temp = s.top();
        while (temp->left)
        {
            s.push(temp->left);
            temp = temp->left;
        }
        while (!temp->right)
        {
            std::cout << temp->data << " ";
            s.pop();
            if (s.empty())
            {
                return;
            }
            temp = s.top();
        }
        std::cout << temp->data << " ";
        s.pop();
        s.push(temp->right);
    }
}

void pre_order_traversal(Node *&root, int i) // NLR
{
    if (!root)
    {
        return;
    }
    std::stack<Node *> s;
    s.push(root);
    Node *temp;

    while (!s.empty())
    {
        temp = s.top();
        while (temp->left)
        {
            std::cout << temp->data << " ";
            s.push(temp->left);
            temp = temp->left;
        }
        std::cout << temp->data << " ";
        while (!temp->right)
        {
            s.pop();
            if (s.empty())
            {
                return;
            }
            temp = s.top();
        }
        s.pop();
        s.push(temp->right);
    }
}

void post_order_traversal(Node *&root, int i) // LRN
{
    if (!root)
    {
        return;
    }
    std::stack<Node *> s;
    std::stack<Node *> prev;
    s.push(root);
    Node *temp;

    while (!s.empty())
    {
        temp = s.top();
        while (temp->left)
        {
            s.push(temp->left);
            temp = temp->left;
        }
        /*
            by this condition we are checking,
            if we had perviously took right from this node (!prev.empty() && temp == prev.top())
        */
        while ((!prev.empty() && temp == prev.top()) || !temp->right)
        {
            if (!prev.empty() && temp == prev.top())
            {
                prev.pop();
            }
            std::cout << temp->data << " ";
            s.pop();
            if (s.empty())
            {
                return;
            }
            temp = s.top();
        }
        prev.push(temp);
        s.push(temp->right);
    }
}

int main()
{
    Node *root = nullptr;
    // root = build_tree(root); // input: 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    // root = build_tree();
    build_tree_by_level_order(root); // input: 1 3 5 7 11 17 -1 -1 -1 -1 -1 -1 -1

    level_order_traversal(root);

    std::cout << std::endl
              << "In Order Traversal Recursion" << std::endl;
    in_order_traversal(root);

    std::cout << std::endl
              << "Pre Order Traversal Recursion" << std::endl;
    pre_order_traversal(root);

    std::cout << std::endl
              << "Post Order Traversal Recursion" << std::endl;
    post_order_traversal(root);

    std::cout << std::endl
              << "In Order Traversal Loop" << std::endl;
    in_order_traversal(root, 1);

    std::cout << std::endl
              << "Pre Order Traversal Loop" << std::endl;
    pre_order_traversal(root, 1);

    std::cout << std::endl
              << "Post Order Traversal Loop" << std::endl;
    post_order_traversal(root, 1);
    std::cout << std::endl;
    return 0;
}