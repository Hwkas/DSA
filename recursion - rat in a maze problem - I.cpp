#include <iostream>
using namespace std;

bool valid_move(int m[7][7], int n, int x, int y)
{
    if ((m[x][y] == 1) && (x > -1) && (y > -1) && (x < n) && (y < n))
    {
        return true;
    }
    return false;
}

void path(int m[7][7], int n, int x, int y, vector<string> &ans, string output)
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
    // int m[4][4] = {{1, 0, 0, 0}, {1, 1, 0, 1}, {1, 1, 0, 0}, {0, 1, 1, 1}};
    int m[7][7] = {{1, 0, 1, 0, 0, 1, 0}, {1, 0, 1, 1, 0, 0, 0}, {1, 0, 0, 0, 1, 0, 1}, {1, 0, 1, 0, 0, 0, 0}, {1, 0, 1, 1, 0, 1, 0}, {1, 0, 0, 0, 0, 1, 0}, {1, 1, 1, 1, 1, 1, 1}};

    vector<string> ans;
    string output;

    path(m, 7, 0, 0, ans, output);

    print_array(ans, ans.size());

    return 0;
}