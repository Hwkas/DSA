#include <iostream>
using namespace std;

class Shape
{
    string shapeType;

public:
    Shape(string shapeType)
    {
        this->shapeType = shapeType;
    }
    void printMyType()
    {
        cout << this->shapeType << endl;
    }
};

class Square : protected Shape
{
    int lenght;

public:
    Square(int lenght) : Shape("square")
    {
        this->lenght = lenght;
    }
    int calculateArea()
    {
        printMyType();
        return lenght * lenght;
    }
};

class Rectangle : protected Shape
{
    int length;
    int breadth;

public:
    Rectangle(int length, int breadth) : Shape("rectangle")
    {
        this->length = length;
        this->breadth = breadth;
    }
    int calculateArea()
    {
        printMyType();
        return length * breadth;
    }
};

int main()
{
    Square s(5);
    Rectangle r(4, 5);

    cout << s.calculateArea() << endl;
    cout << r.calculateArea() << endl;

    return 0;
}