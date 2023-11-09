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

std::pair<int, bool> post_order_traversal(Node *root)
{
    if (root == nullptr)
    {
        std::pair<int, bool> p = std::make_pair(0, true);
        return p;
    }
    if (root->left == nullptr && root->right == nullptr)
    {
        std::pair<int, bool> p = std::make_pair(root->data, true);
        return p;
    }
    std::pair<int, bool> left = post_order_traversal(root->left);
    std::pair<int, bool> right = post_order_traversal(root->right);
    bool equals = (left.first + right.first) == root->data;
    std::pair<int, bool> ans;
    if (left.second && right.second && equals)
    {
        ans.first = 2 * root->data;
        ans.second = true;
    }
    else
    {
        ans.second = false;
    }
    return ans;
}

int main()
{
    Node *root = nullptr;
    root = build_tree(root); // input: 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1 , 3 2 -1 -1 1 -1 -1
    level_order_traversal(root);

    std::cout << "Is Sum Tree: " << (post_order_traversal(root).second ? "True" : "False") << std::endl;
    return 0;
}