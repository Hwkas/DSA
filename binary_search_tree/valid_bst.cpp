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

bool validateBst(Node *root, int min, int max)
{
    if (!root)
    {
        return true;
    }
    // his solution
    if (root->data > min && root->data < max)
    {
        bool left = validateBst(root->left, min, root->data);
        bool right = validateBst(root->right, root->data, max);
        return left && right;
    }
    return false;
    // my solution
    // bool left = validateBst(root->left, min, root->data);
    // bool right = validateBst(root->right, root->data, max);
    // return (left && right && root->data > min && root->data < max) ? true : false;
}

int main()
{
    // 10 8 21 7 27 5 4 3 -1
    std::cout << "Enter the data to create Binary Search Tree: " << std::endl;

    Node *root = nullptr;
    takeInput(root);
    printNode(root);

    std::cout << std::endl
              << (validateBst(root, INT_MIN, INT_MAX) ? "Valid BST" : "Invalid BST") << std::endl;
    return 0;
}
