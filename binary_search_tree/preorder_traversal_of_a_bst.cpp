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

Node *preorderToBST(std::vector<int> &preorder, size_t &index, int min, int max)
{
    if (index >= preorder.size() || !(preorder[index] >= min && preorder[index] <= max))
    {
        return nullptr;
    }
    Node *root = new Node(preorder[index++]);
    root->left = preorderToBST(preorder, index, min, root->data);
    root->right = preorderToBST(preorder, index, root->data, max);
    return root;
}

int main()
{
    // 15 10 7 13 21 20 25 -1
    std::cout << "Enter the preorder to create Binary Search Tree: " << std::endl;
    std::vector<int> preorder;
    int data;
    std::cin >> data;
    while (data != -1)
    {
        preorder.push_back(data);
        std::cin >> data;
    }
    size_t index = 0;
    Node *root = preorderToBST(preorder, index, INT_MIN, INT_MAX);
    printNode(root);
    return 0;
}