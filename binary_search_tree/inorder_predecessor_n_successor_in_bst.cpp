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

void inOrderPredecessorSuccessor(Node *root, std::pair<int, bool> &predecessor, std::pair<int, bool> &successor, int data)
{
    if (!root)
    {
        return;
    }
    inOrderPredecessorSuccessor(root->left, predecessor, successor, data);
    if (root->data == data)
    {
        predecessor.second = true;
    }
    if (!predecessor.second && root->data != data)
    {
        predecessor.first = root->data;
    }
    if (successor.first == -1)
    {
        if (root->data == data)
        {
            successor.second = true;
        }
        else if (successor.second)
        {
            successor.first = root->data;
        }
    }
    inOrderPredecessorSuccessor(root->right, predecessor, successor, data);
}

void inOrderPredecessorSuccessor(Node *root, int *arr, int data)
{
    if (!root)
    {
        return;
    }
    inOrderPredecessorSuccessor(root->left, arr, data);
    if (root->data != data && arr[1] == -1)
    {
        arr[0] = root->data;
    }
    else if (root->data == data)
    {
        arr[1] = root->data;
    }
    else if (arr[1] == data && arr[2] == -1)
    {
        arr[2] = root->data;
    }
    inOrderPredecessorSuccessor(root->right, arr, data);
}

// better sol
void inOrderPredecessorSuccessor(Node *root, Node *&predecessoor, Node *&successoor, int data, bool &found)
{
    if (!root)
    {
        return;
    }

    if (root->data == data)
    {
        found = true;
        if (root->left != NULL)
        {
            Node *tmp = root->left;
            while (tmp->right)
                tmp = tmp->right;
            predecessoor = tmp;
        }
        if (root->right != NULL)
        {
            Node *tmp = root->right;
            while (tmp->left)
                tmp = tmp->left;
            successoor = tmp;
        }
        return;
    }

    if (root->data > data)
    {
        successoor = root;
        inOrderPredecessorSuccessor(root->left, predecessoor, successoor, data, found);
    }
    else
    {
        predecessoor = root;
        inOrderPredecessorSuccessor(root->right, predecessoor, successoor, data, found);
    }
}

std::pair<int, int> inOrderPredecessorSuccessor(Node *root, int data)
{
    int predecessor = -1;
    int successor = -1;

    Node *temp = root;

    while (temp && temp->data != data)
    {
        if (temp->data > data)
        {
            successor = temp->data;
            temp = temp->left;
        }
        else
        {
            predecessor = temp->data;
            temp = temp->right;
        }
    }
    if (!temp)
    {
        return std::make_pair(-1, -1);
    }

    Node *leftSubTree = temp->left;
    while (leftSubTree)
    {
        predecessor = leftSubTree->data;
        leftSubTree = leftSubTree->right;
    }
    Node *rightSubTree = temp->right;
    while (rightSubTree)
    {
        predecessor = rightSubTree->data;
        rightSubTree = rightSubTree->left;
    }
    return std::make_pair(predecessor, successor);
}

int main()
{
    // 10 8 21 7 27 5 4 3 -1
    std::cout << "Enter the data to create Binary Search Tree: " << std::endl;

    Node *root = nullptr;
    takeInput(root);

    std::pair<int, bool> predecessor = std::make_pair(-1, false);
    std::pair<int, bool> successor = std::make_pair(-1, false);

    inOrderTraversal(root);

    int data = 27;

    inOrderPredecessorSuccessor(root, predecessor, successor, data);
    std::cout << std::endl
              << "In Order Predecessor of " << data << " is: "
              << (predecessor.second ? predecessor.first : -1) << std::endl
              << "In Order Successor of " << data << " is: "
              << successor.first << std::endl;

    int arr[] = {-1, -1, -1};
    inOrderPredecessorSuccessor(root, arr, data);
    std::cout << std::endl
              << "In Order Predecessor of " << data << " is: "
              << ((arr[1] != -1) ? arr[0] : -1) << std::endl
              << "In Order Successor of " << data << " is: "
              << arr[2] << std::endl;

    Node *pre = nullptr;
    Node *suc = nullptr;
    bool found = false;
    inOrderPredecessorSuccessor(root, pre, suc, data, found);
    std::cout << std::endl
              << "In Order Predecessor of " << data << " is: "
              << (found && pre ? pre->data : -1) << std::endl
              << "In Order Successor of " << data << " is: "
              << (found && suc ? suc->data : -1) << std::endl;

    std::pair<int, int> ans = inOrderPredecessorSuccessor(root, data);
    std::cout << std::endl
              << "In Order Predecessor of " << data << " is: "
              << (ans.first) << std::endl
              << "In Order Successor of " << data << " is: "
              << (ans.second) << std::endl;

    return 0;
}