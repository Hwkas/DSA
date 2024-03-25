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

int min_in_bst(Node *root)
{
    while (root->left)
    {
        root = root->left;
    }
    return root->data;
}

int max_in_bst(Node *root)
{
    while (root->right)
    {
        root = root->right;
    }
    return root->data;
}

// Using Recursion
void min_max_in_bst(Node *root, std::pair<int, int> &min_max)
{
    if (!root)
    {
        return;
    }
    min_max.second = root->data;
    min_max_in_bst(root->left, min_max);
    if (min_max.first == -1)
    {
        min_max.first = root->data;
    }
    min_max_in_bst(root->right, min_max);
}

int main()
{
    // 10 8 21 7 27 5 4 3 -1
    std::cout << "Enter the data to create Binary Search Tree: " << std::endl;

    Node *root = nullptr;
    takeInput(root);
    printNode(root);
    std::cout << std::endl
              << "Min & Max in BST are: " << min_in_bst(root) << " & " << max_in_bst(root) << std::endl;

    std::pair<int, int> min_max = std::make_pair(-1, -1);
    min_max_in_bst(root, min_max);
    std::cout << std::endl
              << "Min & Max in BST are: " << min_max.first << " & " << min_max.second << std::endl;
    return 0;
}