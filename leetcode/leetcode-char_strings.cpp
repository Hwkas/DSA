#include <iostream>
#include <vector>

// 1047. Remove All Adjacent Duplicates In String

// Online C++ compiler to run C++ program online

using namespace std;
int main()
{
    // Write C++ code here
    string s = "";
    vector<char> c;
    c.push_back(s[0]);
    int i = 1;
    while (i < s.length())
    {
        if (c.back() == s[i])
        {
            c.pop_back();
            s.replace((i - 1), 2, "");
            i--;
        }
        else
        {
            c.push_back(s[i]);
            i++;
        }
    }
    cout << s;

    return 0;
}