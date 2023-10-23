#include <iostream>
#include <deque>
#include <queue>
#include <stack>

// Optimized solution
void reverse_first_k(std::queue<int> &q, int k)
{

    if (k == 0)
    {
        return;
    }
    int temp = q.front();
    q.pop();
    reverse_first_k(q, --k);
    q.push(temp);
}

void solve(std::queue<int> &q, int k, int n)
{
    reverse_first_k(q, k);
    for (int i = 0; i < n - k; i++)
    {
        q.push(q.front());
        q.pop();
    }
}

// Normal Solution
// void reverse_first_k(std::queue<int> &q, int k)
// {
//     int n = q.size();
//     std::deque<int> dq;
//     for (int i = 0; i < n; i++)
//     {
//         (i < k) ? dq.push_front(q.front()) : dq.push_back(q.front());
//         q.pop();
//     }

//     for (int i = 0; i < n; i++)
//     {
//         q.push(dq.front());
//         dq.pop_front();
//     }
// }

void print(std::queue<int> q)
{
    while (!q.empty())
    {
        std::cout << q.front() << " ";
        q.pop();
    }
    std::cout << std::endl;
}

int main()
{
    std::queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);

    int n = 5, k = 3;

    print(q);
    // reverse_first_k(q, k);
    solve(q, k, n);
    print(q);

    return 0;
}