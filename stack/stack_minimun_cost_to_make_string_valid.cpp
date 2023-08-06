#include <iostream>
#include <stack>
using namespace std;

int findMinimumCost(string str)
{
    // Write your code here
    stack<char> st;

    size_t size = str.size();

    if (size % 2 != 0)
    {
        return -1;
    }

    // creating invalid strings stacks
    for (size_t i = 0; i < size; i++)
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

    // calculating cost
    int cost = 0;

    // approch 1
    char ch;
    while (!st.empty())
    {
        ch = st.top();
        st.pop();

        if (ch == st.top())
        {
            cost++;
        }
        else if (ch != st.top())
        {
            cost += 2;
        }

        st.pop();
    }

    // approch 2
    // int opening_braces_count = 0;
    // int closing_brances_count = 0;

    // while (!st.empty())
    // {
    //     if (st.top() == '{')
    //     {
    //         opening_braces_count++;
    //     }
    //     else
    //     {
    //         closing_brances_count++;
    //     }

    //     st.pop();
    // }

    // cost = (++opening_braces_count) / 2 + (++closing_brances_count) / 2;

    return cost;
}

int main()
{
    string str = "}}}}}{";

    cout << findMinimumCost(str) << endl;

    return 0;
}