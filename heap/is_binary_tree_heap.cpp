#include <iostream>

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

int count_nodes(Node *root)
{
    if (!root)
    {
        return 0;
    }
    int left = count_nodes(root->left);
    int right = count_nodes(root->right);
    return (left + right + 1);
}

bool is_complete_binary_tree(Node *root, int index, int total_node_count)
{
    if (!root)
    {
        return true;
    }
    if (index >= total_node_count)
    {
        return false;
    }
    else
    {
        bool left = is_complete_binary_tree(root->left, 2 * index + 1, total_node_count);
        bool right = is_complete_binary_tree(root->right, 2 * index + 2, total_node_count);
        return (left && right);
    }
}

bool is_max_heap(Node *root)
{
    if (!root->left && !root->right)
    {
        return true;
    }
    if (!root->right)
    {
        return (root->data > root->left->data);
    }
    else
    {
        bool left = is_max_heap(root->left);
        bool right = is_max_heap(root->right);
        return (
            left &&
            right &&
            (root->data > root->left->data) &&
            (root->data > root->right->data));
    }
}

int main()
{
    Node *root = nullptr;
    root = build_tree(root); // input: 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    in_order_traversal(root);

    int total_node_count = count_nodes(root);
    bool ans = (is_complete_binary_tree(root, 0, total_node_count) &&
                is_max_heap(root));

    std::cout << std::endl
              << "Is Binary Tree Heap: " << (ans ? "True" : "False") << std::endl;
    return 0;
}