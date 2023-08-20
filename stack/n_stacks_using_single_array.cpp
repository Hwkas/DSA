#include <iostream>
using namespace std;

class NStack
{
public:
    int *arr;
    int *next; // Note : the index array acts as a pointer to the next or prev indexes
    int *top;
    int free_spot;

    NStack(int n, int s) // n = No. of Stacks, s = Size of array
    {
        arr = new int[s];
        next = new int[s];
        top = new int[n];
        free_spot = 0;

        memset(top, -1, n * sizeof(top));

        int i = 0;
        for (; i < s - 1; i++)
        {
            next[i] = i + 1;
        }
        next[i] = -1;
    }

    bool push(int x, int m) // x = element to be inserted to stack, m = the stack on which we need to do the operation
    {
        if (free_spot == -1)
        {
            // stack overflow
            return false;
        }

        // getting the free spot index
        int index = free_spot;

        // updating free_spot to next free index
        free_spot = next[index];

        // pushin the value into the stack
        arr[index] = x;

        // updating the next to hold the previous index of the top's index
        next[index] = top[m - 1];

        // updating the top, the last index of a particaular stack
        top[m - 1] = index;

        return true;
    }

    int pop(int m) // m = the stack on which we need to do the operation
    {
        if (top[m - 1] == -1)
        {
            // stack underflow
            return -1;
        }

        // getting top's index
        int index = top[m - 1];

        // updating the top to hold previous index from the top or say updating to its prev index
        top[m - 1] = next[index];

        // updating the next to hold the next free space index;
        next[index] = free_spot;

        // updating the free_stop to next free space index
        free_spot = index;

        return arr[index];
    }
};

int main()
{
    NStack s(3, 6);

    // cout << s.push(10, 1) << endl;
    // cout << s.push(22, 1) << endl;

    // cout << s.push(30, 2) << endl;

    // cout << s.pop(1) << endl;
    // cout << s.pop(2) << endl;

    cout << s.pop(2) << endl;

    cout << s.push(8, 2) << endl;
    cout << s.push(1, 2) << endl;
    cout << s.push(25, 2) << endl;

    cout << s.push(41, 3) << endl;

    cout << s.push(20, 2) << endl;
    cout << s.push(17, 2) << endl;

    cout << s.pop(2) << endl;
    cout << s.pop(2) << endl;
    cout << s.pop(2) << endl;

    return 0;
}