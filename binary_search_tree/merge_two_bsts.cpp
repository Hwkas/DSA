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

void printIOrderTraversal(Node *root)
{
    if (!root)
    {
        return;
    }
    printIOrderTraversal(root->left);
    std::cout << root->data << " ";
    printIOrderTraversal(root->right);
}

void inOrderTraversal(Node *root, std::vector<Node *> &v)
{
    if (!root)
    {
        return;
    }
    inOrderTraversal(root->left, v);
    v.push_back(root);
    inOrderTraversal(root->right, v);
}

std::vector<Node *> merge_vectors(std::vector<Node *> &v1, std::vector<Node *> &v2)
{
    std::vector<Node *> v;
    size_t i = 0;
    size_t j = 0;
    while (i < v1.size() && j < v2.size())
    {
        if (v1[i]->data < v2[j]->data)
        {
            v.push_back(v1[i++]);
        }
        else
        {
            v.push_back(v2[j++]);
        }
    }
    while (i < v1.size())
    {
        v.push_back(v1[i++]);
    }
    while (j < v2.size())
    {
        v.push_back(v2[j++]);
    }
    return v;
}

Node *inOrderToBST(std::vector<Node *> &v, int start, int end)
{
    if (start > end)
    {
        return nullptr;
    }
    int mid = start + (end - start) / 2;
    v[mid]->left = inOrderToBST(v, start, mid - 1);
    v[mid]->right = inOrderToBST(v, mid + 1, end);
    return v[mid];
}

// converting BST to Douubly Linked List
void flattenABst(Node *root, Node *&head)
{
    if (!root)
    {
        return;
    }
    flattenABst(root->right, head);
    root->right = head;
    if (head) // to make Douubly Linked List
    {
        head->left = root;
    }
    head = root;
    flattenABst(root->left, head);
}

Node *mergeFlattenedBst(Node *root1, Node *root2)
{
    Node *head = nullptr;
    Node *tail = nullptr;
    if (root1->data < root2->data)
    {
        head = root1;
        root1 = root1->right;
    }
    else
    {
        head = root2;
        root2 = root2->right;
    }
    tail = head;
    while (root1 && root2)
    {
        if (root1->data < root2->data)
        {
            tail->right = root1;
            root1->left = tail; // to make Douubly Linked List
            root1 = root1->right;
        }
        else
        {
            tail->right = root2;
            root2->left = tail; // to make Douubly Linked List
            root2 = root2->right;
        }
        tail = tail->right;
    }
    while (root1)
    {
        tail->right = root1;
        root1->left = tail; // to make Douubly Linked List
        root1 = root1->right;
        tail = tail->right;
    }
    while (root2)
    {
        tail->right = root2;
        root2->left = tail; // to make Douubly Linked List
        root2 = root2->right;
        tail = tail->right;
    }
    return head;
}

int countNodes(Node *root)
{
    int count = 0;
    while (root)
    {
        root = root->right;
        count++;
    }
    return count;
}

Node *flattenBstToBalancedBst(Node *&root, int n)
{
    if (n <= 0 || !root)
    {
        return nullptr;
    }
    Node *left = flattenBstToBalancedBst(root, n / 2);
    Node *temp = root;
    temp->left = left;
    root = root->right;
    temp->right = flattenBstToBalancedBst(root, n - (n / 2) - 1);
    return temp;
}

int main()
{
    // 10 8 21 7 27 5 4 3 -1
    std::cout << "Enter the data to create first Binary Search Tree: " << std::endl;
    Node *root1 = nullptr;
    takeInput(root1);

    // 15 25 35 45 9 6 -1
    std::cout << "Enter the data to create second Binary Search Tree: " << std::endl;
    Node *root2 = nullptr;
    takeInput(root2);

    // solution 1
    // std::vector<Node *> v1;
    // std::vector<Node *> v2;
    // inOrderTraversal(root1, v1);
    // inOrderTraversal(root2, v2);

    // std::vector<Node *> v = merge_vectors(v1, v2);
    // Node *root = inOrderToBST(v, 0, v.size() - 1);
    // printIOrderTraversal(root);

    // solution 2
    Node *flattnedBst1 = nullptr;
    Node *flattnedBst2 = nullptr;
    flattenABst(root1, flattnedBst1);
    flattenABst(root2, flattnedBst2);

    Node *root = mergeFlattenedBst(flattnedBst1, flattnedBst2);

    int n = countNodes(root);
    root = flattenBstToBalancedBst(root, n);
    printIOrderTraversal(root);

    return 0;
}