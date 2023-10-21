#include <iostream>

struct petrolPump
{
    int petrol;
    int distance;
};

int tour(petrolPump p[], int n)
{
    // Your code here
    int deficit, balance, start;
    deficit = balance = start = 0;

    for (int i = 0; i < n; i++)
    {
        balance += p[i].petrol - p[i].distance;
        if (balance < 0)
        {
            deficit += balance;
            balance = 0;
            start = i + 1;
        }
    }
    return (deficit + balance >= 0) ? start : -1;
}

int main()
{
    petrolPump arr[] = {{4, 6}, {6, 5}, {7, 3}, {4, 5}};
    std::cout << tour(arr, 4) << std::endl;
    return 0;
}