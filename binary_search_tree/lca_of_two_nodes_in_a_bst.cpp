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

Node *LcaInBST(Node *root, int n1, int n2)
{
    // recursive solution
    if (!root)
    {
        return nullptr;
    }
    if (root->data > n1 && root->data > n2)
    {
        return LcaInBST(root->left, n1, n2);
    }
    if (root->data < n1 && root->data < n2)
    {
        return LcaInBST(root->right, n1, n2);
    }
    return root;

    // Iterative solution
    Node *temp = root;
    while (temp)
    {
        if (temp->data > n1 && temp->data > n2)
        {
            temp = temp->left;
        }
        else if (temp->data < n1 && temp->data < n2)
        {
            temp = temp->right;
        }
        else
        {
            return temp;
        }
    }
}

int main()
{
    // 10 8 21 7 27 5 4 3 -1
    std::cout << "Enter the data to create Binary Search Tree: " << std::endl;
    Node *root = nullptr;
    takeInput(root);

    int n1 = 7;
    int n2 = 21;
    std::cout << "LCA of " << n1 << " & " << n2 << " is: " << LcaInBST(root, n1, n2)->data << std::endl;
    return 0;
}