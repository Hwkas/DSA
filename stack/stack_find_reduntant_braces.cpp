#include <iostream>
#include <stack>
using namespace std;

bool match(char ch)
{
    if (ch == '+' ||
        ch == '-' ||
        ch == '*' ||
        ch == '/')
    {
        return true;
    }
    return false;
}

bool findRedundantBrackets(string &s)
{
    // Write your code here.
    stack<char> st;

    for (size_t i = 0; i < s.size(); i++)
    {
        if (s[i] == '(')
        {
            st.push(s[i]);
        }
        else if (!st.empty() && st.top() == '(' && match(s[i]))
        {
            st.push('+');
        }
        else if (s[i] == ')')
        {
            if (st.top() != '+')
            {
                return true;
            }

            st.pop();
            st.pop();
        }
    }

    return false;
}

int main()
{

    string str = "(a+b*(c/d))";

    cout << (findRedundantBrackets(str) ? "YES" : "NO") << endl;

    return 0;
}