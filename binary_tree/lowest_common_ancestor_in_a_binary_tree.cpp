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

// recursive solution - Optimized
// Node *lca(Node *root, int n1, int n2)
// {
//     if (!root)
//     {
//         return nullptr;
//     }
//     if (root->data == n1 || root->data == n2)
//     {
//         return root;
//     }

//     Node *left = lca(root->left, n1, n2);
//     Node *right = lca(root->right, n1, n2);

//     if (!left && !right)
//     {
//         return nullptr;
//     }
//     else if (left && !right)
//     {
//         return left;
//     }
//     else if (!left && right)
//     {
//         return right;
//     }
//     else
//     {
//         return root;
//     }
// }

// iterative solution
void pre_order_traversal(Node *&root, std::vector<Node *> &v, int n)
{
    if (!root || !v.empty())
    {
        return;
    }
    if (root->data == n)
    {
        v.push_back(root);
        return;
    }
    pre_order_traversal(root->left, v, n);
    pre_order_traversal(root->right, v, n);
    if (!v.empty())
    {
        v.push_back(root);
    }
}

Node *lca(Node *root, int n1, int n2)
{
    std::vector<Node *> v1, v2;
    pre_order_traversal(root, v1, n1);
    pre_order_traversal(root, v2, n2);

    int size1 = v1.size();
    int size2 = v2.size();

    for (int i = 0; i < size1; i++)
    {
        for (int j = 0; j < size2; j++)
            if (v1[i] == v2[j])
            {
                return v1[i];
            }
    }
    return nullptr;
}

int main()
{
    Node *root = nullptr;
    root = build_tree(root); // input: 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1 , 3 2 -1 -1 1 -1 -1
    level_order_traversal(root);

    std::cout << "Enter the value of n1 & n2 to find its LCA(Lowest Common Ancestor): " << std::endl;
    int n1, n2;
    std::cin >> n1;
    std::cin >> n2;
    std::cout << "The LCA is : " << lca(root, n1, n2)->data << std::endl;
    return 0;
}