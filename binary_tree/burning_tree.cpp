#include <iostream>
#include <queue>
#include <unordered_map>

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
// void create_mapping(Node *root, Node *parent, int &target, std::unordered_map<Node *, Node *> &node_to_parent)
// {
//     if (!root)
//     {
//         return;
//     }
//     node_to_parent[root] = parent;
//     create_mapping(root->left, root, target, node_to_parent);
//     create_mapping(root->right, root, target, node_to_parent);
// }

Node *create_mapping(Node *root, int &target, std::unordered_map<Node *, Node *> &node_to_parent)
{
    Node *target_node = nullptr;
    std::queue<Node *> q;
    Node *temp = nullptr;

    q.push(root);
    node_to_parent[root] = nullptr;

    while (!q.empty())
    {
        temp = q.front();
        q.pop();

        if (temp->data == target)
        {
            target_node = temp;
        }

        if (temp->left)
        {
            node_to_parent[temp->left] = temp;
            q.push(temp->left);
        }
        if (temp->right)
        {
            node_to_parent[temp->right] = temp;
            q.push(temp->right);
        }
    }
    return target_node;
}

int burn_tree(Node *target_node, std::unordered_map<Node *, Node *> &node_to_parent)
{
    std::unordered_map<Node *, bool> visited;
    std::queue<Node *> q;
    Node *temp = nullptr;
    int size = 0;
    bool flag = false;
    int time = 0;

    visited[target_node] = true;
    q.push(target_node);

    while (!q.empty())
    {
        size = q.size();
        flag = false;
        for (int i = 0; i < size; i++)
        {
            temp = q.front();
            q.pop();

            if (!visited[temp->left] && temp->left)
            {
                q.push(temp->left);
                visited[temp->left] = true;
                flag = true;
            }
            if (!visited[temp->right] && temp->right)
            {
                q.push(temp->right);
                visited[temp->right] = true;
                flag = true;
            }
            if (!visited[node_to_parent[temp]] && node_to_parent[temp])
            {
                q.push(node_to_parent[temp]);
                visited[node_to_parent[temp]] = true;
                flag = true;
            }
        }

        if (flag)
        {
            time++;
        }
    }
    return time;
}

// Better solution
/*
myFun returns pair of int,int.
First one is distance of node containing target value from current node and second one is height tree from current node.
If there is no node containing target value then it will return -1 as first value.
We store final ans in variable 'fin'. At every node it compares fin with appropriate value.
*/
std::pair<int, int> burn_tree(Node *root, int target, int &fin)
{
    std::pair<int, int> ans(-1, -1);
    if (root == nullptr)
    {
        return ans;
    }
    std::pair<int, int> left = burn_tree(root->left, target, fin);
    std::pair<int, int> right = burn_tree(root->right, target, fin);
    ans.second = (std::max(left.second, right.second) + 1);
    if (left.first != -1)
    {
        ans.first = left.first + 1;
        fin = std::max(fin, ans.first + right.second + 1);
        return ans;
    }
    if (right.first != -1)
    {
        ans.first = right.first + 1;
        fin = std::max(fin, ans.first + left.second + 1);
        return ans;
    }
    if (root->data == target)
    {
        ans.first = 0;
        fin = std::max(fin, std::max(left.second, right.second) + 1);
    }
    return ans;
}

int minTime(Node *root, int target)
{
    // his solution
    // std::unordered_map<Node *, Node *> node_to_parent;
    // Node *target_node = create_mapping(root, target, node_to_parent);
    // return burn_tree(target_node, node_to_parent);

    // better solution
    int fin = 0;
    burn_tree(root, target, fin);
    return fin;
}

int main()
{
    Node *root = nullptr;
    root = build_tree(root); // input: 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1 , 3 2 -1 -1 1 -1 -1
    level_order_traversal(root);

    std::cout << "The minimum time to burn the tree is : " << minTime(root, 17) << std::endl;
    return 0;
}
