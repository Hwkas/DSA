#include <iostream>
#include <queue>
#include <vector>

// My Solution
// std::vector<long long> printFirstNegativeInteger(
//     long long int A[], long long int N, long long int K)
// {
//     std::queue<int> q;
//     std::vector<long long> ans;

//     for (int i = 0; i < N; i++)
//     {
//         if (A[i] < 0)
//         {
//             q.push(i);
//         }
//     }

//     for (int i = 0; i < N - K + 1; i++)
//     {
//         if (!q.empty() && q.front() >= i && q.front() <= i + K - 1)
//         {
//             ans.push_back(A[q.front()]);
//             if (q.front() == i)
//             {
//                 q.pop();
//             }
//         }
//         else
//         {
//             ans.push_back(0);
//         }
//     }
//     return ans;
// }

// His Solution
std::vector<long long> printFirstNegativeInteger(
    long long int A[], long long int N, long long int K)
{
    std::queue<int> q;
    std::vector<long long> ans;

    for (int i = 0; i < K; i++)
    {
        if (A[i] < 0)
        {
            q.push(i);
        }
    }

    ans.push_back(q.empty() ? 0 : A[q.front()]);

    for (int i = K; i < N; i++)
    {
        if (!q.empty() && i - q.front() >= K)
        {
            q.pop();
        }
        if (A[i] < 0)
        {
            q.push(i);
        }
        ans.push_back(q.empty() ? 0 : A[q.front()]);
    }
    return ans;
}

void print(std::vector<long long> v)
{
    for (size_t i = 0; i < v.size(); i++)
    {
        std::cout << v[i] << " ";
    }
    std::cout << std::endl;
}

int main()
{
    long long int arr[] = {-8, 2, 3, -6, 10};
    long long int n = 5;
    long long int k = 2;

    std::vector<long long> ans = printFirstNegativeInteger(arr, n, k);

    print(ans);
    return 0;
}