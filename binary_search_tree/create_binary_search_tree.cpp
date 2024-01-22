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
// Node *insertIntoNode(Node *&root, int data)
// {
//     if (!root)
//     {
//         return new Node(data);
//     }
//     if (data < root->data)
//     {
//         root->left = insertIntoNode(root->left, data);
//     }
//     else
//     {
//         root->right = insertIntoNode(root->right, data);
//     }
//     return root;
// }

// my solution
void insertIntoNode(Node *&root, int data)
{
    if (!root)
    {
        root = new Node(data);
        return;
    }
    if (data < root->data)
    {
        insertIntoNode(root->left, data);
    }
    else
    {
        insertIntoNode(root->right, data);
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

void takeInput(Node *&root)
{
    int data;
    std::cin >> data;

    while (data != -1)
    {
        // root = insertIntoNode(root, data);
        insertIntoNode(root, data);
        std::cin >> data;
    }
}

int main()
{
    // 10 8 21 7 27 5 4 3 -1
    std::cout << "Enter the data to create Binary Search Tree: " << std::endl;

    Node *root = nullptr;
    takeInput(root);
    printNode(root);
    return 0;
}