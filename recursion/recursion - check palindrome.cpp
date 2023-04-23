#include <iostream>
using namespace std;

bool check_palindrome(string &str, int i, int j)
{
    if (i > j)
    {
        return true;
    }
    if (str[i] != str[j])
    {
        return false;
    }
    return check_palindrome(str, ++i, --j);
}

int main()
{
    string str = "aba";
    check_palindrome(str, 0, str.length() - 1) ? cout << "The give string is a Palindrome" << endl : cout << "The give string is not a Palindrome" << endl;
    return 0;
}