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

    int cost = 0;
    char ch;

    // calculating cost
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

    return cost;
}

int main()
{
    string str = "}}}}}{";

    cout << findMinimumCost(str) << endl;

    return 0;
}