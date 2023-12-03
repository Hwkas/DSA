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

Node *solve(int in[], int post[], int &post_index, int in_start, int in_end, int n)
{
    if (post_index < 0 || in_start >= in_end)
    {
        return nullptr;
    }
    int data = post[post_index--];
    Node *root = new Node(data);
    int index = find_index(data, in, in_start, in_end);
    root->right = solve(in, post, post_index, index + 1, in_end, n);
    root->left = solve(in, post, post_index, in_start, index, n);
    return root;
}

Node *build_tree(int in[], int post[], int n)
{
    int post_index = n - 1;
    return solve(in, post, post_index, 0, n, n);
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
    int inorder[] = {4, 8, 2, 5, 1, 6, 3, 7};
    int postorder[] = {8, 4, 5, 2, 6, 7, 3, 1};

    Node *root = nullptr;
    root = build_tree(inorder, postorder, 8);
    level_order_traversal(root);
    return 0;
}
