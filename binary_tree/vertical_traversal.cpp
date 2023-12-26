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
std::vector<int> verticalOrder(Node *root)
{
    std::vector<int> ans;
    if (!root)
    {
        return ans;
    }
    std::map<int, std::vector<int> > nodes;
    std::queue<std::pair<Node *, int> > q;

    q.push(std::make_pair(root, 0));

    while (!q.empty())
    {
        std::pair<Node *, int> temp = q.front();
        q.pop();

        Node *front_node = temp.first;
        int hd = temp.second; // hd = horizontal_distance

        nodes[hd].push_back(front_node->data);
        if (front_node->left)
        {
            q.push(std::make_pair(front_node->left, hd - 1));
        }
        if (front_node->right)
        {
            q.push(std::make_pair(front_node->right, hd + 1));
        }
    }

    for (auto i : nodes)
    {
        for (auto j : i.second)
        {
            ans.push_back(j);
        }
    }
    return ans;
}

// his solution
// This implement is usefull if we need to play with level
// std::vector<int> verticalOrder(Node *root)
// {
//     // Your code here
//     std::vector<int> ans;
//     if (!root)
//     {
//         return ans;
//     }
//     std::map<int, std::map<int, std::vector<int> > > nodes;
//     std::queue<std::pair<Node *, std::pair<int, int> > > q;

//     q.push(std::make_pair(root, std::make_pair(0, 0)));

//     while (!q.empty())
//     {
//         std::pair<Node *, std::pair<int, int> > temp = q.front();
//         q.pop();

//         Node *front_node = temp.first;
//         int hd = temp.second.first; // hd = horizontal_distance
//         int level = temp.second.second;

//         nodes[hd][level].push_back(front_node->data);

//         if (front_node->left)
//         {
//             q.push(std::make_pair(front_node->left, std::make_pair(hd - 1, level + 1)));
//         }
//         if (front_node->right)
//         {
//             q.push(std::make_pair(front_node->right, std::make_pair(hd + 1, level + 1)));
//         }
//     }

//     for (auto i : nodes)
//     {
//         for (auto j : i.second)
//         {
//             for (auto k : j.second)
//                 ans.push_back(k);
//         }
//     }
//     return ans;
// }

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

    std::vector<int> ans = verticalOrder(root);
    print_vector(ans);
    return 0;
}