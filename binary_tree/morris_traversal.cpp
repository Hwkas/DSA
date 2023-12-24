#include <iostream>
#include <queue>
#include <unordered_map>

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

Node *find_predecessor(Node *predecessor, Node *&current)
{
    while (predecessor->right && predecessor->right != current)
    {
        predecessor = predecessor->right;
    }
    return predecessor;
}

void morris_traversal(Node *&root)
{
    if (!root)
    {
        return;
    }
    std::cout << std::endl
              << "Morris traversal of Binary Tree" << std::endl;
    Node *current = root;
    Node *predecessor = nullptr;
    while (current)
    {
        if (!current->left)
        {
            std::cout << current->data << " ";
            current = current->right;
        }
        else
        {
            predecessor = find_predecessor(current->left, current);
            if (!predecessor->right)
            {
                predecessor->right = current;
                current = current->left;
            }
            else
            {
                predecessor->right = nullptr;
                std::cout << current->data << " ";
                current = current->right;
            }
        }
    }
    std::cout << std::endl;
}

int main()
{
    Node *root = nullptr;
    root = build_tree(root); // input: 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1 , 3 2 -1 -1 1 -1 -1

    std::cout << std::endl
              << "In Order Traversal Loop" << std::endl;
    in_order_traversal(root);

    morris_traversal(root);
    return 0;
}
