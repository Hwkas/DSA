#include <iostream>
using namespace std;

void permutation(string str, int n, vector<string> &ans, string output, int map[])
{
    int out_size = output.size();
    if (out_size == n)
    {
        ans.push_back(output);
    }

    for (int i = 0; i < n; i++)
    {
        if (!map[i])
        {
            output.push_back(str[i]);
            map[i] = 1;
            permutation(str, n, ans, output, map);
            map[i] = 0;
            output.pop_back();
        }
    }
}

// // optimized solution
// void permutation(string str, int n, int index, vector<string> &ans)
// {
//     if (index >= n)
//     {
//         ans.push_back(str);
//         return;
//     }

//     for (int i = index; i < n; i++)
//     {
//         swap(str[index], str[i]);
//         permutation(str, n, index + 1, ans);
//         swap(str[index], str[i]);
//     }
// }

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
    string str = "abcd";
    int n = str.size();

    vector<string> ans;
    int *map = new int[n];
    for (int i = 0; i < n; i++)
    {
        map[i] = 0;
    }
    string output;

    permutation(str, n, ans, output, map);
    print_array(ans, ans.size());

    return 0;
}

// // optimized solution
// int main()
// {
//     string str = "abc";
//     int n = str.size();

//     vector<string> ans;
//     string output;
//     int index = 0;

//     permutation(str, n, index, ans);
//     print_array(ans, ans.size());

//     return 0;
// }