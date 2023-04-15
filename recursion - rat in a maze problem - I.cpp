#include <iostream>
using namespace std;

bool valid_move(vector<vector<int> > &m, int n, int x, int y)
{
    if ((x > -1) && (y > -1) && (x < n) && (y < n) && (m[x][y] == 1))
    {
        return true;
    }
    return false;
}

void path(vector<vector<int> > &m, int n, int x, int y, vector<string> &ans, string output)
{
    if (x == n - 1 && y == n - 1)
    {
        ans.push_back(output);
        return;
    }

    m[x][y] = 0;

    if (valid_move(m, n, x + 1, y)) // Down
    {
        output.push_back('D');
        path(m, n, x + 1, y, ans, output);
        output.pop_back();
    }
    if (valid_move(m, n, x, y + 1)) // Right
    {
        output.push_back('R');
        path(m, n, x, y + 1, ans, output);
        output.pop_back();
    }
    if (valid_move(m, n, x, y - 1)) // Left
    {
        output.push_back('L');
        path(m, n, x, y - 1, ans, output);
        output.pop_back();
    }
    if (valid_move(m, n, x - 1, y)) // Up
    {
        output.push_back('U');
        path(m, n, x - 1, y, ans, output);
        output.pop_back();
    }

    m[x][y] = 1;
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
    /*
        Inputs
        4
        1 0 0 0
        1 1 0 1 
        1 1 0 0 
        0 1 1 1

        7
        1 0 1 0 0 1 0 
        1 0 1 1 0 0 0 
        1 0 0 0 1 0 1 
        1 0 1 0 0 0 0 
        1 0 1 1 0 1 0 
        1 1 0 0 0 1 0 
        1 1 1 1 1 1 1

    */

    cout << "Enter the size Maze: ";
    int n;
    cin >> n;
    vector<vector<int> > m(n, vector<int>(n, 0));
    cout << "Enter the element of the Maze" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> m[i][j];
        }
    }

    vector<string> ans;
    string output;

    path(m, n, 0, 0, ans, output);

    print_array(ans, ans.size());

    return 0;
}