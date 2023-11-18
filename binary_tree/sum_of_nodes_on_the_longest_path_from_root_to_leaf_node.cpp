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

// my solution
// void pre_order_traversal(Node *root, std::vector<int> temp, std::vector<std::vector<int> > &nodes)
// {
//     if (!root)
//     {
//         nodes.push_back(temp);
//         return;
//     }
//     temp.push_back(root->data);
//     pre_order_traversal(root->left, temp, nodes);
//     if (root->right)
//     {
//         pre_order_traversal(root->right, temp, nodes);
//     }
// }

// int sumOfLongRootToLeafPath(Node *root)
// {
//     if (!root)
//     {
//         return 0;
//     }
//     std::vector<std::vector<int> > nodes;
//     std::vector<int> temp;
//     pre_order_traversal(root, temp, nodes);

//     int max_length, max_sum, sum, curr_size;
//     max_length = max_sum = sum = curr_size = 0;

//     for (auto i : nodes)
//     {
//         curr_size = i.size();
//         if (curr_size >= max_length)
//         {
//             sum = 0;
//             for (auto j : i)
//             {
//                 sum += j;
//             }
//             max_sum = (max_length == curr_size) ? std::max(sum, max_sum) : sum;
//             max_length = curr_size;
//         }
//     }
//     return max_sum;
// }

// his approch
// void pre_order_traversal(Node *root, std::pair<int, int> &temp, std::pair<int, int> &ans)
// {
//     if (!root)
//     {
//         if ((temp.first > ans.first) || (temp.first == ans.first && temp.second > ans.second))
//         {
//             ans = temp;
//         }
//         return;
//     }
//     temp = std::make_pair(temp.first + 1, temp.second + root->data);
//     pre_order_traversal(root->left, temp, ans);
//     pre_order_traversal(root->right, temp, ans);
//     temp = std::make_pair(temp.first - 1, temp.second - root->data);
// }

// int sumOfLongRootToLeafPath(Node *root)
// {
//     if (!root)
//     {
//         return 0;
//     }
//     std::pair<int, int> ans;
//     std::pair<int, int> temp;
//     pre_order_traversal(root, temp, ans);
//     return ans.second;
// }

// his solution
void pre_order_traversal(Node *root, int &curr_len, int &curr_sum, int &max_len, int &max_sum)
{
    if (!root)
    {
        if ((curr_len > max_len) || (curr_len == max_len && curr_sum > max_sum))
        {
            max_len = curr_len;
            max_sum = curr_sum;
        }
        return;
    }
    curr_len++;
    curr_sum += root->data;
    pre_order_traversal(root->left, curr_len, curr_sum, max_len, max_sum);
    pre_order_traversal(root->right, curr_len, curr_sum, max_len, max_sum);
    curr_len--;
    curr_sum -= root->data;
}

int sumOfLongRootToLeafPath(Node *root)
{
    if (!root)
    {
        return 0;
    }
    int curr_len, curr_sum, max_len, max_sum;
    curr_len = curr_sum = max_len = max_sum = 0;
    pre_order_traversal(root, curr_len, curr_sum, max_len, max_sum);
    return max_sum;
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

    int ans = sumOfLongRootToLeafPath(root);
    std::cout << "Ans: " << ans << std::endl;
    return 0;
}
