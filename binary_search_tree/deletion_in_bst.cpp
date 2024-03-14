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

void linkPrevToCurrentsNext(Node *previous_node, Node *current_next, int &data)
{
    if (!previous_node)
    {
        return;
    }
    if (previous_node->data > data)
    {
        previous_node->left = current_next;
    }
    else
    {
        previous_node->right = current_next;
    }
}

void unlinkAndDeleteNode(Node *&node_to_delete)
{
    node_to_delete->right = nullptr;
    node_to_delete->left = nullptr;
    delete node_to_delete;
}

// my solution
void deleteNode(Node *&root, Node *current_node, Node *previous_node, int data)
{
    if (!current_node)
    {
        return;
    }
    if (current_node->data == data)
    {
        Node *node_to_delete = current_node;
        if (!node_to_delete->left && !node_to_delete->right)
        {
            linkPrevToCurrentsNext(previous_node, nullptr, data);
        }
        else if (!node_to_delete->left && node_to_delete->right)
        {
            linkPrevToCurrentsNext(previous_node, node_to_delete->right, data);
        }
        else if (node_to_delete->left && !node_to_delete->right)
        {
            linkPrevToCurrentsNext(previous_node, node_to_delete->left, data);
        }
        else
        {
            Node *temp = node_to_delete->left;
            Node *prev_temp = nullptr;

            while (temp->right)
            {
                prev_temp = temp;
                temp = temp->right;
            }

            if (prev_temp)
            {
                prev_temp->right = nullptr;
                temp->left = node_to_delete->left;
            }
            temp->right = node_to_delete->right;
            linkPrevToCurrentsNext(previous_node, temp, data);
            if (!previous_node)
            {
                root = temp;
            }
        }
        unlinkAndDeleteNode(node_to_delete);
        return;
    }

    if (current_node->data > data)
    {
        deleteNode(root, current_node->left, current_node, data);
    }
    else
    {
        deleteNode(root, current_node->right, current_node, data);
    }
}

// his solution
Node *deleteNode(Node *root, int data)
{
    if (!root)
    {
        return nullptr;
    }
    if (root->data == data)
    {
        Node *temp = nullptr;
        if (!root->left && !root->right)
        {
            // not doing anything here because deletion is done at the end.
        }
        else if (!root->left && root->right)
        {
            temp = root->right;
        }
        else if (root->left && !root->right)
        {
            temp = root->left;
        }
        else
        {
            Node *current = root->left;
            Node *previous = nullptr;

            while (current->right)
            {
                previous = current;
                current = current->right;
            }

            if (previous)
            {
                previous->right = nullptr;
                current->left = root->left;
            }
            current->right = root->right;
            temp = current;
        }
        unlinkAndDeleteNode(root);
        return temp;
    }

    if (root->data > data)
    {
        root->left = deleteNode(root->left, data);
    }
    else
    {
        root->right = deleteNode(root->right, data);
    }
    return root;
}

int main()
{
    // 10 8 21 7 27 5 4 3 -1
    std::cout << "Enter the data to create Binary Search Tree: " << std::endl;

    Node *root = nullptr;
    takeInput(root);
    std::cout << "Before deleting the node: " << std::endl;
    printNode(root);

    int data = 21;
    // deleteNode(root, root, nullptr, data);
    root = deleteNode(root, data);

    std::cout << std::endl
              << "After deleting the node: " << std::endl;
    printNode(root);
    return 0;
}
