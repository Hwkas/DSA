#include <iostream>
#include <queue>
#include <deque>
#include <map>

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

// std::vector<int> daigonal_traversal(Node *root)
// {
//     std::vector<int> ans;
//     std::deque<Node *> q;
//     Node *temp;
//     q.push_back(root);
//     while (!q.empty())
//     {
//         temp = q.front();
//         q.pop_front();
//         ans.push_back(temp->data);
//         if (temp->right)
//             q.push_front(temp->right);
//         if (temp->left)
//             q.push_back(temp->left);
//     }
//     return ans;
// }

// recursive solution
void pre_order_traversal(Node *root, int hd, std::map<int, std::vector<int> > &nodes)
{
    if (!root)
    {
        return;
    }
    nodes[hd].push_back(root->data);
    pre_order_traversal(root->left, hd + 1, nodes);
    pre_order_traversal(root->right, hd, nodes);
}

std::vector<int> daigonal_traversal(Node *root)
{
    std::vector<int> ans;
    std::map<int, std::vector<int> > nodes;
    pre_order_traversal(root, 0, nodes);

    for (auto i : nodes)
    {
        for (auto j : i.second)
        {
            ans.push_back(j);
        }
    }
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

    std::vector<int> ans = daigonal_traversal(root);
    print_vector(ans);
    return 0;
}
