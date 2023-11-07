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

// His Solution
int height_of_binary_tree(Node *root)
{
    if (root == nullptr)
    {
        return 0;
    }
    int left = height_of_binary_tree(root->left);
    int right = height_of_binary_tree(root->right);
    int ans = std::max(left, right) + 1;
    return ans;
}

int diameter(Node *root)
{
    if (!root)
    {
        return 0;
    }
    int op1 = diameter(root->left);
    int op2 = diameter(root->right);
    int op3 = height_of_binary_tree(root->left) + height_of_binary_tree(root->right) + 1;
    return std::max(op1, std::max(op2, op3));
}

std::pair<int, int> diameter_fast(Node *root)
{
    if (!root)
    {
        std::pair<int, int> p = std::make_pair(0, 0);
        return p;
    }
    std::pair<int, int> left = diameter_fast(root->left);
    std::pair<int, int> right = diameter_fast(root->right);

    int op1 = left.first;
    int op2 = right.first;
    int op3 = left.second + right.second + 1;

    std::pair<int, int> ans;
    ans.first = std::max(op1, std::max(op2, op3));
    ans.second = std::max(left.second, right.second) + 1;
    return ans;
}

int main()
{
    Node *root = nullptr;
    root = build_tree(root); // input: 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    level_order_traversal(root);

    std::cout << "Height of Binary Tree are: " << diameter(root) << std::endl;
    std::cout << "Height of Binary Tree are: " << diameter_fast(root).first << std::endl;
    return 0;
}