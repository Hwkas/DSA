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

void inOrderTraversal(Node *root, std::vector<Node *> &v)
{
    if (!root)
    {
        return;
    }
    inOrderTraversal(root->left, v);
    v.push_back(root);
    inOrderTraversal(root->right, v);
}

Node *createBalancedBst(std::vector<Node *> &v, int start, int end)
{
    if (start > end)
    {
        return nullptr;
    }
    int mid = start + (end - start) / 2;
    v[mid]->left = createBalancedBst(v, start, mid - 1);
    v[mid]->right = createBalancedBst(v, mid + 1, end);
    return v[mid];
}

Node *normalBstToBalancedBst(Node *root)
{
    std::vector<Node *> v;
    inOrderTraversal(root, v);
    return createBalancedBst(v, 0, v.size() - 1);
}

int main()
{
    // 10 8 21 7 27 5 4 3 -1
    std::cout << "Enter the data to create Binary Search Tree: " << std::endl;
    Node *root = nullptr;
    takeInput(root);

    root = normalBstToBalancedBst(root);
    return 0;
}