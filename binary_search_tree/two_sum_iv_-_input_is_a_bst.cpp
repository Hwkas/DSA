#include <iostream>

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
            this->left = this->right = nullptr;
        }
    }
};

// his solution
Node *insertIntoNode(Node *&root, int data)
{
    if (!root)
    {
        return new Node(data);
    }
    if (data < root->data)
    {
        root->left = insertIntoNode(root->left, data);
    }
    else
    {
        root->right = insertIntoNode(root->right, data);
    }
    return root;
}

void takeInput(Node *&root)
{
    int data;
    std::cin >> data;

    while (data != -1)
    {
        root = insertIntoNode(root, data);
        std::cin >> data;
    }
}

void printNode(Node *root)
{
    if (!root)
    {
        return;
    }
    std::cout << root->data << " ";
    printNode(root->left);
    printNode(root->right);
}

// my solution
bool twoSumInBST(Node *root, int target, std::unordered_map<int, bool> &map)
{
    if (!root)
    {
        return false;
    }
    if (map[target - root->data])
    {
        return true;
    }
    map[root->data] = true;
    bool left = twoSumInBST(root->left, target, map);
    bool right = twoSumInBST(root->right, target, map);
    return (left || right);
}

void inOrderTraversal(Node *root, std::vector<int> &v)
{
    if (!root)
    {
        return;
    }
    inOrderTraversal(root->left, v);
    v.push_back(root->data);
    inOrderTraversal(root->right, v);
}

// his solution
bool twoSumInBST(Node *root, int target, std::vector<int> &v)
{
    inOrderTraversal(root, v);
    int i = 0;
    int j = v.size() - 1;

    while (i < j)
    {
        if ((v[i] + v[j]) > target)
        {
            j--;
        }
        else if ((v[i] + v[j] < target))
        {
            i++;
        }
        else
        {
            return true;
        }
    }
    return false;
}

int main()
{
    // 10 8 21 7 27 5 4 3 -1
    std::cout << "Enter the data to create Binary Search Tree: " << std::endl;
    Node *root = nullptr;
    takeInput(root);

    std::unordered_map<int, bool> map;
    int target = 25;
    std::cout << "Two sum for the target " << target << (twoSumInBST(root, target, map) ? " " : " does not ") << "exists in the BST." << std::endl;

    std::vector<int> v;
    std::cout << "Two sum for the target " << target << (twoSumInBST(root, target, v) ? " " : " does not ") << "exists in the BST." << std::endl;
    return 0;
}