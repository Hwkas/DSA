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

void inOrderTraversal(Node *root)
{
    if (!root)
    {
        return;
    }
    inOrderTraversal(root->left);
    std::cout << root->data << " ";
    inOrderTraversal(root->right);
}

void findKthLargest(Node *root, int &k, int &ans)
{
    if (!root)
    {
        return;
    }
    findKthLargest(root->right, k, ans);
    k--;
    if (k == 0)
    {
        ans = root->data;
        return;
    }
    findKthLargest(root->left, k, ans);
}

int findKthLargest(Node *root, int &k)
{
    if (!root)
    {
        return -1;
    }
    int ans;
    ans = findKthLargest(root->right, k);
    k--;
    if (k == 0)
    {
        return root->data;
    }
    if (ans == -1)
    {
        ans = findKthLargest(root->left, k);
    }
    return ans;
}

int main()
{
    // 10 8 21 7 27 5 4 3 -1
    std::cout << "Enter the data to create Binary Search Tree: " << std::endl;

    Node *root = nullptr;
    takeInput(root);
    printNode(root);

    std::cout << std::endl;
    inOrderTraversal(root);

    int k = 2;
    // int ans = -1;
    // findKthLargest(root, k, ans);
    // std::cout << std::endl
    //           << "Kth Largest element is: " << ans << std::endl;
    std::cout << std::endl
              << "Kth Largest element is: " << findKthLargest(root, k) << std::endl;
    return 0;
}
