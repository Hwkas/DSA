// #include <iostream>
// #include <thread>

// void thread_func(std::string &s)
// {
//     std::cout << "Hello! from " << s << std::endl;
// }

// int main()
// {
//     std::cout << "Inside main thread, before thread initialization." << std::endl;

//     std::string s = "First Thread";
//     std::thread first_thread(&thread_func, std::ref(s));
//     first_thread.join();

//     std::cout << "Inside main thread, after thread execution." << std::endl;
//     return 0;
// }

// // clang++ -std=c++20 -stdlib=libc++ -pthread <file name> -o <output file name>

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

int main()
{
    Node first(10);
    std::cout << first.data;
    return 0;
}