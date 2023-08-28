#include <iostream>
#include <stack>
using namespace std;

class SpecialStack
{
public:
    stack<int> st;
    int mini;

    SpecialStack()
    {
        mini = INT_MAX;
    }

    void push(int data)
    {
        if (st.empty())
        {
            st.push(data);
            mini = data;
        }
        else if (data < mini)
        {
            st.push(2 * data - mini);
            mini = data;
        }
        else
        {
            st.push(data);
        }
    }

    void pop()
    {
        int curr = st.top();
        if (curr < mini)
        {
            mini = 2 * mini - curr;
        }
        st.pop();
    }

    int top()
    {
        if (st.empty())
        {
            return -1;
        }
        int curr = st.top();
        if (curr > mini)
        {
            return curr;
        }
        return mini;
    }

    int getMin()
    {
        if (st.empty())
        {
            return -1;
        }
        return mini;
    }
};

int main()
{
    SpecialStack s;

    cout << "push operations" << endl;
    s.push(8);
    cout << "min - " << s.getMin() << endl;
    s.push(9);
    cout << "min - " << s.getMin() << endl;
    s.push(10);
    cout << "min - " << s.getMin() << endl;
    s.push(1);
    cout << "min - " << s.getMin() << endl;
    s.push(6);
    cout << "min - " << s.getMin() << endl;
    s.push(3);
    cout << "min - " << s.getMin() << endl;

    cout << "pop operations" << endl;
    s.pop();
    cout << "min - " << s.getMin() << endl;
    s.pop();
    cout << "min - " << s.getMin() << endl;
    s.pop();
    cout << "min - " << s.getMin() << endl;
    s.pop();
    cout << "min - " << s.getMin() << endl;
    s.pop();
    cout << "min - " << s.getMin() << endl;
    s.pop();
    cout << "min - " << s.getMin() << endl;

    return 0;
}