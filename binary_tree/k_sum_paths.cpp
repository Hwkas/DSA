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

// his solution
// void pre_order_traversal(Node *&root, std::vector<int> &path, int &k, int &count)
// {
//     if (!root)
//     {
//         return;
//     }
//     path.push_back(root->data);
//     pre_order_traversal(root->left, path, k, count);
//     pre_order_traversal(root->right, path, k, count);

//     int size = path.size();
//     int sum = 0;
//     for (int i = size - 1; i > -1; i--)
//     {
//         sum += path[i];
//         if (sum == k)
//         {
//             count++;
//         }
//     }
//     path.pop_back();
// }

// int k_sum_paths(Node *root, int k)
// {
//     std::vector<int> path;
//     int count = 0;
//     pre_order_traversal(root, path, k, count);
//     return count;
// }

void dfs(Node *node, int currPathSum, int target, std::unordered_map<int, int> &pathCount, int &res)
{
    if (node == NULL)
    {
        return;
    }
    currPathSum += node->data;
    res += pathCount[currPathSum - target];
    pathCount[currPathSum]++;
    dfs(node->left, currPathSum, target, pathCount, res);
    dfs(node->right, currPathSum, target, pathCount, res);
    pathCount[currPathSum]--;
}
int k_sum_paths(Node *root, int k)
{
    std::unordered_map<int, int> pathCount;
    pathCount[0] = 1; // here this is used to increase the count by 1, when the sum is achieved
    int res = 0;
    dfs(root, 0, k, pathCount, res);
    return res;
}

int main()
{
    Node *root = nullptr;
    root = build_tree(root); // input: 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1 , 3 2 -1 -1 1 -1 -1
    level_order_traversal(root);

    std::cout << "Enter the value of k: " << std::endl;
    int k;
    std::cin >> k;
    std::cout << "The K Sum Paths is : " << k_sum_paths(root, k) << std::endl;
    return 0;
}