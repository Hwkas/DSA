#include <iostream>
using namespace std;

// code studio
// Q. Subsequences of String
// https://www.codingninjas.com/codestudio/problems/subsequences-of-string_985087?leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=love_babbar_16

void power_sets(string &str, int size, int index, vector<string> &ans, string subset)
{
    if (index >= size)
    {
        /*
        here we are also adding empty string, to exlcude it just uncomment the below line
        if(subset.size()){
            ans.push_back(subset);
        }
        */
        ans.push_back(subset);
        return;
    }

    // exclude
    power_sets(str, size, index + 1, ans, subset);

    // include
    subset.push_back(str[index]);
    power_sets(str, size, index + 1, ans, subset);
}

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
    int index = 0;

    power_sets(str, str.size(), index, ans, subset);

    print_array(ans, ans.size());

    return 0;
}