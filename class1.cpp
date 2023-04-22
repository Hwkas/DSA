#include <iostream>
using namespace std;

class Car
{
    string color;

public:
    Car(string color)
    {
        this->color = color;
    }

    void printColor()
    {
        cout << "Color: " << this->color << endl;
    }
};

class RaceCar : public Car
{
    int speed;

public:
    RaceCar(int speed, string color) : Car(color)
    {
        this->speed = speed;
    }

    void printinfo()
    {
        printColor();
        cout << "Speed: " << this->speed << endl;
    }
};

int main()
{
    RaceCar supra(250, "white");
    supra.printinfo();

    return 0;
}