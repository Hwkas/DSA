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

// my solution
void flattenBstToASoartedList(Node *root, Node *&prev, Node *&newHEAD)
{
    if (!root)
    {
        return;
    }
    flattenBstToASoartedList(root->left, prev, newHEAD);
    if (!newHEAD)
    {
        newHEAD = root;
    }
    if (prev)
    {
        prev->right = root;
        prev->left = nullptr;
    }
    prev = root;
    flattenBstToASoartedList(root->right, prev, newHEAD);
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

// his solution
Node *flattenBstToASoartedList(Node *root)
{
    std::vector<Node *> v;
    inOrderTraversal(root, v);

    int i = 0;
    for (size_t j = 1; j < v.size(); j++)
    {
        v[i]->left = nullptr;
        v[i]->right = v[j];
        i++;
    }
    v[i]->left = nullptr;
    v[i]->right = nullptr;
    return v[0];
}

int main()
{
    // 10 8 21 7 27 5 4 3 -1
    std::cout << "Enter the data to create Binary Search Tree: " << std::endl;
    Node *root = nullptr;
    takeInput(root);

    // Node *newHEAD = nullptr;
    // Node *prev = nullptr;
    // flattenBstToASoartedList(root, prev, newHEAD);
    // print_flat_binary_tree(newHEAD);

    root = flattenBstToASoartedList(root);
    print_flat_binary_tree(root);
    return 0;
}