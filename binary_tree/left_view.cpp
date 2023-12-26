#include <iostream>
#include <queue>
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

// my solution
// std::vector<int> leftView(Node *root)
// {
//     std::vector<int> ans;
//     if (!root)
//     {
//         return ans;
//     }
//     /*
//         Here we are not taking Horizontal distance because we only the first element of every level.
//     */
//     // level, Node/Node_data
//     std::queue<std::pair<int, Node *> > q;
//     q.push(std::make_pair(0, root));
//     std::pair<int, Node *> temp;
//     Node *front_node;
//     int level, n;

//     while (!q.empty())
//     {
//         temp = q.front();
//         q.pop();

//         level = temp.first;
//         front_node = temp.second;

//         n = ans.size();
//         if (level == n)
//         {
//             ans.push_back(front_node->data);
//         }

//         if (front_node->left)
//         {
//             q.push(std::make_pair(level + 1, front_node->left));
//         }
//         if (front_node->right)
//         {
//             q.push(std::make_pair(level + 1, front_node->right));
//         }
//     }
//     return ans;
// }

// recursive solution
void pre_order_tarversal(Node *root, int level, std::vector<int> &ans)
{
    if (!root)
    {
        return;
    }
    if (level == ans.size())
    {
        ans.push_back(root->data);
    }
    pre_order_tarversal(root->left, level + 1, ans);
    pre_order_tarversal(root->right, level + 1, ans);
}

std::vector<int> leftView(Node *root)
{
    std::vector<int> ans;
    pre_order_tarversal(root, 0, ans);
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

    std::vector<int> ans = leftView(root);
    print_vector(ans);
    return 0;
}
