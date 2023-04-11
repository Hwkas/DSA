#include <iostream>
using namespace std;

// Leetcode
// Q.17 Letter Combinations of a Phone Number
// https://leetcode.com/problems/letter-combinations-of-a-phone-number/

void phone_key(string &digits, int n, string mapping[], int index, vector<string> &ans, string output)
{
    if (index >= n)
    {
        ans.push_back(output);
        return;
    }

    int number = digits[index] - '0';
    string value = mapping[number];
    int m = value.size();
    for (int i = 0; i < m; i++)
    {
        output.push_back(value[i]);
        phone_key(digits, n, mapping, index + 1, ans, output);
        output.pop_back(); // back-tracking, to avoid repetition of chars
    }
}

inline void print_array(vector<string> &ans, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
}

int main()
{
    string digits = "234";
    vector<string> ans;
    string output;
    int index = 0;
    string mapping[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tvu", "wxyz"};

    phone_key(digits, digits.size(), mapping, index, ans, output);

    print_array(ans, ans.size());
    return 0;
}