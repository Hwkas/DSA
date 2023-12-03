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

int find_index(int data, int *inorder, int start, int end)
{
    for (int i = start; i < end; i++)
    {
        if (inorder[i] == data)
        {
            return i;
        }
    }
    return -1;
}

Node *solve(int in[], int pre[], int &pre_index, int in_start, int in_end, int n)
{
    if (pre_index >= n || in_start >= in_end)
    {
        return nullptr;
    }
    int data = pre[pre_index++];
    Node *root = new Node(data);
    int index = find_index(data, in, in_start, in_end);
    root->left = solve(in, pre, pre_index, in_start, index, n);
    root->right = solve(in, pre, pre_index, index + 1, in_end, n);
    return root;
}

Node *build_tree(int in[], int pre[], int n)
{
    int pre_index = 0;
    return solve(in, pre, pre_index, 0, n, n);
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

int main()
{
    int inorder[] = {3, 1, 4, 0, 5, 2};
    int preorder[] = {0, 1, 3, 4, 2, 5};

    Node *root = nullptr;
    root = build_tree(inorder, preorder, 6);
    level_order_traversal(root);
    return 0;
}
