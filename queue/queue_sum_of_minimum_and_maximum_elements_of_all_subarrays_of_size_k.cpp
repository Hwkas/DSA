#include <iostream>
#include <queue>
#include <deque>

inline int get_new_min(std::queue<int> q, int size)
{
    int min = INT_MAX;
    for (int i = 0; i < size; i++)
    {
        if (q.front() < min)
        {
            min = q.front();
        }
        q.push(q.front());
        q.pop();
    }
    return min;
}

inline int get_new_max(std::queue<int> q, int size)
{
    int max = INT_MIN;
    for (int i = 0; i < size; i++)
    {
        if (q.front() > max)
        {
            max = q.front();
        }
        q.push(q.front());
        q.pop();
    }
    return max;
}

int my_solve(int *arr, int n, int k) // arr: array, n: size of array, k: size of sub array
{
    std::queue<int> q;
    int min = INT_MAX;
    int max = INT_MIN;
    int sum = 0;
    int i = 0;
    for (; i < k; i++)
    {
        if (arr[i] < min)
        {
            min = arr[i];
        }
        if (arr[i] > max)
        {
            max = arr[i];
        }
        q.push(arr[i]);
    }
    sum += min + max;
    int temp;
    for (; i < n; i++)
    {
        temp = q.front();
        q.pop();
        if (temp == min)
        {
            min = get_new_min(q, k - 1);
        }
        else if (temp == max)
        {
            max = get_new_max(q, k - 1);
        }
        if (arr[i] < min)
        {
            min = arr[i];
        }
        if (arr[i] > max)
        {
            max = arr[i];
        }
        q.push(arr[i]);
        sum += min + max;
    }
    return sum;
}

int his_solve(int *arr, int n, int k) // arr: array, n: size of array, k: size of sub array
{
    std::deque<int> q_min, q_max;
    int sum = 0;

    for (int i = 0; i < k; i++)
    {
        while (!q_min.empty() && arr[i] <= arr[q_min.back()])
        {
            q_min.pop_back();
        }
        while (!q_max.empty() && arr[i] >= arr[q_max.back()])
        {
            q_max.pop_back();
        }
        q_min.push_back(i);
        q_max.push_back(i);
    }
    sum += arr[q_min.front()] + arr[q_max.front()];
    for (int i = k; i < n; i++)
    {
        // removal
        while (!q_min.empty() && i - q_min.front() >= k)
        {
            q_min.pop_front();
        }
        while (!q_max.empty() && i - q_max.front() >= k)
        {
            q_max.pop_front();
        }
        // addition
        while (!q_min.empty() && arr[i] <= arr[q_min.back()])
        {
            q_min.pop_back();
        }
        while (!q_max.empty() && arr[i] >= arr[q_max.back()])
        {
            q_max.pop_back();
        }
        q_min.push_back(i);
        q_max.push_back(i);
        sum += arr[q_min.front()] + arr[q_max.front()];
    }
    return sum;
}

int main()
{
    int arr[] = {2, 5, -1, 7, -3, -1, -2};
    int n = 7;
    int k = 4;

    std::cout << my_solve(arr, n, k) << std::endl;
    std::cout << his_solve(arr, n, k) << std::endl;
    return 0;
}