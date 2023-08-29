#include <iostream>
#include <stack>
using namespace std;

int main()
{

    string str = "fedbca";

    stack<char> s;

    for (size_t i = 0; i < str.size(); i++)
    {
        s.push(str[i]);
    }

    str = "";

    while (!s.empty())
    {
        str.push_back(s.top());
        s.pop();
    }

    cout << str << endl;

    return 0;
}