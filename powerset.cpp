#include <iostream>
using namespace std;

// code studio
// Q. Subsequences of String
// https://www.codingninjas.com/codestudio/problems/subsequences-of-string_985087?leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=love_babbar_16

inline void print_array(vector<string> &ans, int n)
{
    for (int i = 0; i < n; i++)
        cout << ans[i] << " ";
    cout << endl;
}

int main()
{
    string str = "abc";
    vector<string> ans;
    string subset;

    int n = str.size();      // size str
    int m = 1 << str.size(); // total number of powersets

    /*
        here below initialie i with 1 if you don't want empty
        subset in your powerset.
    */
    for (int i = 0; i < m; i++)
    {
        subset = "";
        for (int j = 0; j < n; j++)
        {
            if ((i >> j) & 1)
            {
                subset.push_back(str[j]);
            }
        }
        ans.push_back(subset);
    }

    print_array(ans, ans.size());

    return 0;
}