#include <iostream>
#include <queue>

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

void level_order_traversal(Node *&root)
{
    std::queue<Node *> q;
    q.push(root);
    q.push(nullptr);

    std::cout << std::endl
              << "Level order traversal of Binary Tree" << std::endl;
    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();

        if (temp == nullptr)
        {
            std::cout << std::endl;
            if (!q.empty())
            {
                q.push(nullptr);
            }
        }
        else
        {
            std::cout << temp->data << " ";
            if (temp && temp->left)
            {
                q.push(temp->left);
            }
            if (temp && temp->right)
            {
                q.push(temp->right);
            }
        }
    }
}

bool isIdentical(Node *r1, Node *r2) // using Post Order Travesal
{
    if (!r1 && !r2)
    {
        return true;
    }
    else if ((!r1 && r2) || (r1 && !r2))
    {
        return false;
    }
    bool left = isIdentical(r1->left, r2->left);
    bool right = isIdentical(r1->right, r2->right);
    int value = r1->data == r2->data;
    return (left && right && value) ? true : false;
}

int main()
{
    Node *root1 = nullptr;
    root1 = build_tree(root1); // input: 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    level_order_traversal(root1);

    Node *root2 = nullptr;
    root2 = build_tree(root2); // input: 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    level_order_traversal(root2);

    std::cout << "Is Binary Trees Identical: " << (isIdentical(root1, root2) ? "True" : "False") << std::endl;
    return 0;
}
