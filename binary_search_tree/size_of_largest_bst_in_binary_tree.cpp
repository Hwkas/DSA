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
            this->left = this->right = nullptr;
        }
    }
};

// his solution
Node *insertIntoNode(Node *&root, int data)
{
    if (!root)
    {
        return new Node(data);
    }
    if (data < root->data)
    {
        root->left = insertIntoNode(root->left, data);
    }
    else
    {
        root->right = insertIntoNode(root->right, data);
    }
    return root;
}

void takeInput(Node *&root)
{
    int data;
    std::cin >> data;

    while (data != -1)
    {
        root = insertIntoNode(root, data);
        std::cin >> data;
    }
}

void printNode(Node *root)
{
    if (!root)
    {
        return;
    }
    std::cout << root->data << " ";
    printNode(root->left);
    printNode(root->right);
}

struct info
{
    int max;
    int min;
    bool is_bst;
    int size;
};

info largestBST(Node *root, int &max_size)
{
    if (!root)
    {
        return {INT_MIN, INT_MAX, true, 0};
    }
    info left = largestBST(root->left, max_size);
    info right = largestBST(root->right, max_size);

    info current_node;
    current_node.size = left.size + right.size + 1;
    current_node.max = std::max(root->data, right.max);
    current_node.min = std::min(root->data, left.min);
    current_node.is_bst = left.is_bst && right.is_bst && root->data > left.max && root->data < right.min;
    if (current_node.is_bst)
    {
        max_size = std::max(max_size, current_node.size);
    }
    return current_node;
}

int main()
{
    // 10 8 21 7 27 5 4 3 -1
    std::cout << "Enter the data to create first Binary Search Tree: " << std::endl;
    Node *root = nullptr;
    takeInput(root);

    int max_size = 0;
    largestBST(root, max_size);
    std::cout << max_size << std::endl;

    return 0;
}
