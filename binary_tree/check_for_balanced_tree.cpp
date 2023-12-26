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

int height(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int left = height(root->left);
    int right = height(root->right);
    if ((left == -1 || right == -1) || abs(left - right) > 1)
    {
        return -1;
    }
    return std::max(left, right) + 1;
}

std::pair<int, int> height_int_bool_pair(Node *root)
{
    if (root == NULL)
    {
        std::pair<int, bool> p = std::make_pair(0, true);
        return p;
    }
    std::pair<int, bool> left = height_int_bool_pair(root->left);
    std::pair<int, bool> right = height_int_bool_pair(root->right);

    std::pair<int, bool> ans;
    ans.first = std::max(left.first, right.first) + 1;
    ans.second = (left.second && right.second && abs(left.first - right.first) <= 1);
    return ans;
}

int main()
{
    Node *root = nullptr;
    root = build_tree(root); // input: 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    level_order_traversal(root);

    std::cout << "Is Binary Tree balanced: " << (height(root) != -1 ? "True" : "False") << std::endl;
    std::cout << "Is Binary Tree balanced: " << (height_int_bool_pair(root).second ? "True" : "False") << std::endl;
    return 0;
}