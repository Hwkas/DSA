#include <iostream>
#include <stack>
using namespace std;

bool match(char c1, char c2)
{
    if (
        ((c1 == ')') && (c2 == '(')) || 
        ((c1 == '}') && (c2 == '{')) || 
        ((c1 == ']') && (c2 == '['))
    )
    {
        return true;
    }

    return false;
}

bool isValidParenthesis(string &s)
{
    stack<char> st;

    for (size_t i = 0; i < s.size(); i++)
    {
        if ((s[i] == '(') || (s[i] == '{') || (s[i] == '['))
        {
            st.push(s[i]);
        }
        else
        {
            if (st.empty())
            {
                return false;
            }
            if (match(s[i], st.top()))
            {
                st.pop();
            }
        }
    }

    return st.empty() ? true : false;
}

int main()
{
    string s = "[()]{}{[()()]()}";

    cout << (isValidParenthesis(s) ? "Valid" : "Invalid") << endl;

    return 0;
}