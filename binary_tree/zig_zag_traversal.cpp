#include <iostream>
#include <deque>
#include <queue>
#include <vector>

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

// My Solution
std::vector<int> zig_zag_level_order_traversal(Node *root)
{
    std::cout << "Zig Zag Level Order Traversal: " << std::endl;

    std::deque<Node *> dq;
    dq.push_back(root);
    dq.push_back(nullptr);

    Node *temp;
    std::vector<int> ans;
    bool left_to_right = true;

    while (!dq.empty())
    {
        if (left_to_right)
        {
            temp = dq.front();
            dq.pop_front();

            if (!temp)
            {
                if (dq.empty())
                {
                    break;
                }
                dq.push_front(nullptr);
                left_to_right = false;
                continue;
            }
            ans.push_back(temp->data);
            if (temp->left)
            {
                dq.push_back(temp->left);
            }
            if (temp->right)
            {
                dq.push_back(temp->right);
            }
        }
        else
        {
            temp = dq.back();
            dq.pop_back();

            if (!temp)
            {
                if (dq.empty())
                {
                    break;
                }
                dq.push_back(nullptr);
                left_to_right = true;
                continue;
            }
            ans.push_back(temp->data);
            if (temp->right)
            {
                dq.push_front(temp->right);
            }
            if (temp->left)
            {
                dq.push_front(temp->left);
            }
        }
    }
    return ans;
}

// His solution
std::vector<int> zig_zag_level_order_traversal(Node *root, int i)
{
    std::vector<int> ans;
    if (!root)
    {
        return ans;
    }

    std::queue<Node *> q;
    q.push(root);

    Node *temp;
    int n;
    int index;
    bool left_to_right = true;

    while (!q.empty())
    {
        n = q.size();
        std::vector<int> v(n);
        for (int i = 0; i < n; i++)
        {
            temp = q.front();
            q.pop();

            index = left_to_right ? i : n - i - 1;
            v[index] = temp->data;

            if (temp->left)
            {
                q.push(temp->left);
            }
            if (temp->right)
            {
                q.push(temp->right);
            }
        }
        for (auto i : v)
        {
            ans.push_back(i);
        }
        left_to_right = !left_to_right;
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

    std::vector<int> ans;
    ans = zig_zag_level_order_traversal(root);
    print_vector(ans);

    ans = zig_zag_level_order_traversal(root, 98);
    print_vector(ans);
    return 0;
}