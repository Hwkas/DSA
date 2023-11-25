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

void print_vector(std::vector<Node *> &v)
{
    std::cout << std::endl
              << "Printing Vector: ";
    int n = v.size();
    for (int i = 0; i < n; i++)
    {
        std::cout << v[i]->data << " ";
    }
    std::cout << std::endl;
}

// my solution
// void tree_traversal(Node *root, std::vector<int> &path, int node, bool &found)
// {
//     if (!root || found)
//     {
//         return;
//     }
//     path.push_back(root->data);
//     if (root->data == node)
//     {
//         found = true;
//     }
//     tree_traversal(root->left, path, node, found);
//     tree_traversal(root->right, path, node, found);
//     if (!found)
//     {
//         path.pop_back();
//     }
// }

// int kthAncestor(Node *root, int k, int node)
// {
//     if (!root)
//     {
//         return -1;
//     }
//     std::vector<int> path;
//     bool found = false;
//     tree_traversal(root, path, node, found);
//     return (found && (path.size() >= (k + 1))) ? path[path.size() - k - 1] : -1;
// }

// void tree_traversal(Node *root, int &k, int node, bool &found, int &ans)
// {
//     if (!root || found)
//     {
//         return;
//     }
//     if (root->data == node)
//     {
//         found = true;
//     }
//     tree_traversal(root->left, k, node, found, ans);
//     tree_traversal(root->right, k, node, found, ans);
//     if (!k)
//     {
//         ans = root->data;
//     }
//     if (found)
//     {
//         k--;
//     }
// }

// int kthAncestor(Node *root, int k, int node)
// {
//     int ans = -1;
//     if (!root)
//     {
//         return ans;
//     }
//     bool found = false;
//     tree_traversal(root, k, node, found, ans);
//     return ans;
// }

// his solution
Node *tree_traversal(Node *root, int &k, int node)
{
    if (!root)
    {
        return nullptr;
    }
    if (root->data == node)
    {
        return root;
    }
    Node *left = tree_traversal(root->left, k, node);
    Node *right = tree_traversal(root->right, k, node);
    if (left && !right)
    {
        k--;
        if (k <= 0)
        {
            k = INT_MAX;
            return root;
        }
        return left;
    }
    if (!left && right)
    {
        k--;
        if (k <= 0)
        {
            k = INT_MAX;
            return root;
        }
        return right;
    }
    return NULL;
}

int kthAncestor(Node *root, int k, int node)
{
    Node *ans = tree_traversal(root, k, node);
    return (!ans || ans->data == node) ? -1 : ans->data;
}

int main()
{
    Node *root = nullptr;
    root = build_tree(root); // input: 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1 , 3 2 -1 -1 1 -1 -1
    level_order_traversal(root);

    std::cout << "Enter the value of k & node: " << std::endl;
    int k, node;
    std::cin >> k;
    std::cin >> node;
    std::cout << "The kth Ancestor is : " << kthAncestor(root, k, node) << std::endl;
    return 0;
}