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

// My solution
void height_of_binary_tree(Node *root, int &max_element, int count)
{
    if (root == nullptr)
    {
        max_element = std::max(max_element, count);
        return;
    }
    count++;
    height_of_binary_tree(root->left, max_element, count);
    height_of_binary_tree(root->right, max_element, count);
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

int main()
{
    Node *root = nullptr;
    root = build_tree(root); // input: 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    level_order_traversal(root);

    int max_element = 0;
    int count = 0;
    height_of_binary_tree(root, max_element, count);
    std::cout << "Height of Binary Tree are: " << max_element << std::endl;
    std::cout << "Height of Binary Tree are: " << height_of_binary_tree(root) << std::endl;
    return 0;
}