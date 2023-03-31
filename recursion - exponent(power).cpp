#include <iostream>
using namespace std;

// normal function
// int exponent(int n, int m)
// {
//     if (m == 0)
//     {
//         return 1;
//     }
//     return n * exponent(n, --m);
// }

// inline function
// inline int exponent(int n, int m)
// {
//     return (m == 0) ? 1 : (n * exponent(n, --m));
// }

// optimized solution
int exponent(int n, int m)
{
    if (m == 0)
    {
        return 1;
    }
    if (m & 1)
    {
        return n * exponent(n, m / 2) * exponent(n, m / 2);
    }

    return exponent(n, m / 2) * exponent(n, m / 2);
}

int main()
{
    int n = 3;
    int m = 3;
    cout << exponent(n, m) << endl;
    return 0;
}
