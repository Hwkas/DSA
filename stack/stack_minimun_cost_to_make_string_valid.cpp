#include <iostream>
#include <stack>
using namespace std;

int findMinimumCost(string str)
{
    // Write your code here
    stack<char> st;

    for (size_t i = 0; i < str.size(); i++)
    {
        if (str[i] == '{')
        {
            st.push(str[i]);
        }
        else
        {
            if (!st.empty() && st.top() != str[i])
            {
                st.pop();
            }
            else
            {
                st.push(str[i]);
            }
        }
    }

    if (st.empty())
    {
        return 0;
    }

    int cost = 0;
    char ch;

    while (!st.empty())
    {
        ch = st.top();
        st.pop();
        if (st.empty())
        {
            return -1;
        }
        else if (ch == st.top())
        {
            cost++;
        }
        else if (ch != st.top())
        {
            cost += 2;
        }
        st.pop();
    }

    return cost;
}

int main()
{
    string str = "}}}}}{";

    cout << findMinimumCost(str) << endl;

    return 0;
}