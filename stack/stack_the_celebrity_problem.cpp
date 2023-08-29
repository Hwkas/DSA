#include <iostream>
#include <stack>
using namespace std;

// Normal Solution
// int celebrity(vector<vector<int> > &M, int n)
// {
//     for (int i = 0; i < n; i++)
//     {
//         int j = 0;
//         for (; j < n; j++)
//         {
//             if ((i != j) && M[i][j])
//             {
//                 break;
//             }
//         }

//         if (j == n)
//         {
//             for (j = 0; j < n; j++)
//             {
//                 if ((i != j) && !M[j][i])
//                 {
//                     break;
//                 }
//             }

//             if (j == n)
//             {
//                 return i;
//             }
//         }
//     }
//     return -1;
// }

// Optimized Solution
int celebrity(vector<vector<int> > &M, int n)
{
    stack<int> s;
    for (int i = 0; i < n; i++)
    {
        s.push(i);
    }

    int a;
    int b;

    while (s.size() > 1)
    {
        a = s.top();
        s.pop();

        b = s.top();
        s.pop();

        if (M[a][b])
        {
            s.push(b);
        }
        else
        {
            s.push(a);
        }
    }

    // checking if he know anybody, if yes return -1
    a = s.top();

    for (int i = 0; i < n; i++)
    {
        if ((a != i) && M[a][i])
        {
            return -1;
        }
    }

    // checking if he is known by all, if not return -1
    for (int i = 0; i < n; i++)
    {
        if ((a != i) && !M[i][a])
        {
            return -1;
        }
    }

    return a;
}

int main()
{
    vector<vector<int> > v;

    vector<int> temp;

    temp.push_back(0);
    temp.push_back(1);
    temp.push_back(0);

    v.push_back(temp);
    temp.clear();

    temp.push_back(0);
    temp.push_back(0);
    temp.push_back(0);

    v.push_back(temp);
    temp.clear();

    temp.push_back(0);
    temp.push_back(1);
    temp.push_back(0);

    v.push_back(temp);
    temp.clear();

    cout << celebrity(v, v.size()) << endl;

    return 0;
}