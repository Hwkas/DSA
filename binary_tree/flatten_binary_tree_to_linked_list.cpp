#include <iostream>
#include <queue>

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

void pre_order_traversal(Node *root) // LNR
{
    if (!root)
    {
        return;
    }
    std::cout << root->data << " ";
    pre_order_traversal(root->left);
    pre_order_traversal(root->right);
}

void flatten_binary_tree(Node *root, Node *&prev)
{
    if (!root)
    {
        return;
    }
    flatten_binary_tree(root->right, prev);
    flatten_binary_tree(root->left, prev);
    root->right = prev;
    root->left = nullptr;
    prev = root;
}

void print_flat_binary_tree(Node *root)
{
    std::cout << "Flat Binary Tree" << std::endl;
    while (root)
    {
        std::cout << root->data << " ";
        root = root->right;
    }
    std::cout << std::endl;
}

Node *find_predecessor(Node *predecessor, Node *&current)
{
    while (predecessor->right && predecessor->right != current)
    {
        predecessor = predecessor->right;
    }
    return predecessor;
}

void morris_traversal(Node *&root)
{
    if (!root)
    {
        return;
    }
    Node *current = root;
    Node *predecessor = nullptr;
    while (current)
    {
        if (current->left)
        {
            predecessor = find_predecessor(current->left, current);
            if (!predecessor->right)
            {
                predecessor->right = current->right;
                current->right = current->left;
                current->left = nullptr;
            }
            else
            {
                predecessor->right = nullptr;
            }
        }
        current = current->right;
        /*
            just extra if condition
            if (!current->left)
            {
                current = current->right;
            }
            else
            {
                predecessor = find_predecessor(current->left, current);
                if (!predecessor->right)
                {
                    predecessor->right = current->right;
                    current->right = current->left;
                    current->left = nullptr;
                    current = current->right;
                }
                else
                {
                    predecessor->right = nullptr;
                    current = current->right;
                }
            }
        */
    }
}

int main()
{
    Node *root = nullptr;
    root = build_tree(root); // input: 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1 , 3 2 -1 -1 1 -1 -1

    std::cout << std::endl
              << "Pre Order Traversal Loop" << std::endl;
    pre_order_traversal(root);
    std::cout << std::endl;

    // my solution
    // std::queue<Node *> leaf_nodes;
    Node * prev = nullptr;
    flatten_binary_tree(root, prev);

    // his & better solution
    // morris_traversal(root);
    pre_order_traversal(root);

    return 0;
}
