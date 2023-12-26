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

std::pair<int, int> post_order_traversal(Node *root)
{
    if (!root)
    {
        return std::make_pair(0, 0);
    }
    std::pair<int, int> left = post_order_traversal(root->left);
    std::pair<int, int> right = post_order_traversal(root->right);
    int include_curr_node = root->data + left.second + right.second;
    int exlude_curr_node = std::max(left.first, left.second) + std::max(right.first, right.second);
    return std::make_pair(include_curr_node, exlude_curr_node);
}

int getMaxSum(Node *root)
{
    std::pair<int, int> temp = post_order_traversal(root);
    return std::max(temp.first, temp.second);
}

int main()
{
    Node *root = nullptr;
    root = build_tree(root); // input: 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1 , 3 2 -1 -1 1 -1 -1
    level_order_traversal(root);
    std::cout << "The Maximum sum of Non-adjacent nodes : " << getMaxSum(root) << std::endl;
    return 0;
}