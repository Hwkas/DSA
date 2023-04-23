#include <iostream>
using namespace std;

void print_no_in_words(int n, string arr[])
{
    if (n == 0)
    {
        return;
    }
    print_no_in_words(n / 10, arr);
    cout << arr[n % 10] << " ";
}

int main()
{
    cout << "Enter the number you want to print in words: ";
    int n;
    cin >> n;

    string arr[10] = {"Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};

    print_no_in_words(n, arr);
}