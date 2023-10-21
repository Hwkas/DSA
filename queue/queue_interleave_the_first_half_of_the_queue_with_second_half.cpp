#include <iostream>
#include <queue>
#include <vector>

std::vector<int> rearrangeQueue(std::queue<int> &q)
{
    int n = q.size();
    std::vector<int> v(n);

    for (int i = 0; i < n; i = i + 2)
    {
        v[i] = q.front();
        q.pop();
    }

    for (int i = 1; i < n; i = i + 2)
    {
        v[i] = q.front();
        q.pop();
    }

    return v;
}

void print(std::vector<int> &v, int n)
{
    for (int i = 0; i < n; i++)
    {
        std::cout << v[i] << " ";
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

    std::vector<int> ans = rearrangeQueue(q);

    print(ans, ans.size());
    return 0;
}
