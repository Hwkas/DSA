#include <iostream>
#include <queue>

std::string FirstNonRepeating(std::string &A)
{
    int arr[26] = {0};
    std::queue<int> q;
    std::string ans;

    for (size_t i = 0; i < A.size(); i++)
    {
        //  increase the char count
        arr[A[i] - 'a']++;

        //  put it to the queue
        q.push(A[i]);

        int n = q.size();
        // checking if it is a repeating char
        for (int j = 0; j < n; j++)
        {
            if (arr[q.front() - 'a'] > 1)
            {
                q.pop();
            }
            else
            {
                ans.push_back(q.front());
                break;
            }
        }
        if (q.empty())
        {
            ans.push_back('#');
        }
    }
    return ans;
}

int main()
{
    std::string str = "aabc";
    std::cout << FirstNonRepeating(str) << std::endl;
    return 0;
}