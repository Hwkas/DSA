#include <iostream>
using namespace std;

class Human
{
    int age;
    float height;

    friend void print(Human);
    void speak()
    {
        cout << "I have a voice" << endl;
    }

public:
    Human(int age, float height)
    {
        this->age = age;
        this->height = height;
    }
};

// Note we can to pass class into friend function by refrence.
void print(Human h)
{
    cout << "Age: " << h.age << endl
         << "Height: " << h.height << " m" << endl;
}

int main()
{
    Human h(2, 1.2);
    print(h);
    return 0;
}