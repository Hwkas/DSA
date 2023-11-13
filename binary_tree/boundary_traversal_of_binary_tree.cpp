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

void left_boundry_traversal(Node *root, std::vector<int> &ans)
{
    if (!root || (!root->left && !root->right))
    {
        return;
    }
    ans.push_back(root->data);
    (root->left) ? left_boundry_traversal(root->left, ans) : left_boundry_traversal(root->right, ans);
}

void leaf_node_tarversal(Node *root, std::vector<int> &ans)
{
    if (!root)
    {
        return;
    }
    if (!root->left && !root->right)
    {
        ans.push_back(root->data);
        return;
    }
    leaf_node_tarversal(root->left, ans);
    leaf_node_tarversal(root->right, ans);
}

void right_boundry_traversal(Node *root, std::vector<int> &ans)
{
    if (!root || (!root->left && !root->right))
    {
        return;
    }
    (root->right) ? right_boundry_traversal(root->right, ans) : right_boundry_traversal(root->left, ans);
    ans.push_back(root->data);
}

std::vector<int> boundry_traversal(Node *root)
{
    std::vector<int> ans;
    std::cout << "Boundary Traversal of Binary Tree: ";
    if (!root)
    {
        return ans;
    }
    ans.push_back(root->data);

    left_boundry_traversal(root->left, ans);
    leaf_node_tarversal(root->left, ans);
    leaf_node_tarversal(root->right, ans);
    right_boundry_traversal(root->right, ans);
    return ans;
}

void print_vector(std::vector<int> &v)
{
    std::cout << std::endl
              << "Your answer is: ";
    int n = v.size();
    for (int i = 0; i < n; i++)
    {
        std::cout << v[i] << " ";
    }
    std::cout << std::endl;
}

int main()
{
    Node *root = nullptr;
    root = build_tree(root); // input: 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1 , 3 2 -1 -1 1 -1 -1, 3 9 2 -1 -1 1 -1 -1 20 15 -1 -1 7 -1 -1
    level_order_traversal(root);

    std::vector<int> ans = boundry_traversal(root);
    print_vector(ans);
    return 0;
}