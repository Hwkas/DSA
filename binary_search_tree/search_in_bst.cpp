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

Node *insertIntoNode(Node *root, int data)
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

// recursive
// bool searchInBST(Node *root, int x)
// {
//     if (!root)
//     {
//         return false;
//     }
//     if (root->data == x)
//     {
//         return true;
//     }
//     if (root->data > x)
//     {
//         return searchInBST(root->left, x);
//     }
//     else
//     {
//         return searchInBST(root->right, x);
//     }
// }

// itetrative
bool searchInBST(Node *root, int x)
{
    while (root)
    {
        if (root->data == x)
        {
            return true;
        }
        if (root->data > x)
        {
            root = root->left;
        }
        else
        {
            root = root->right;
        }
    }
    return false;
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

int main()
{
    // 10 8 21 7 27 5 4 3 -1
    std::cout << "Enter the data to create Binary Search Tree: " << std::endl;

    Node *root = nullptr;
    takeInput(root);
    printNode(root);
    int x = 4;
    std::cout << std::endl
              << x << " is present in the BST: " << (searchInBST(root, x) ? "True" : "False") << std::endl;
    return 0;
}