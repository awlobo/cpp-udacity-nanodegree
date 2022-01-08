// Example solution for Rectangle and Square friend classes
#include <assert.h>

class Rectangle;

class Square
{
public:
    Square(double side) : m_side(side) {}

private:
    double m_side;
    friend class Rectangle;
};

class Rectangle
{
public:
    Rectangle(const Square &a);
    double Area() const;

private:
    double m_width{0};
    double m_height{0};
};



Rectangle::Rectangle(const Square &a) : m_width(a.m_side), m_height(a.m_side) {}

double Rectangle::Area() const
{
    return m_width * m_height;
}

// Define Area() to compute area of Rectangle

int main()
{
    Square square(4);
    Rectangle rectangle(square);
    assert(rectangle.Area() == 16);
}