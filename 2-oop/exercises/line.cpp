#include <iostream>
#include <cmath>
#include <assert.h>

#define PI 3.1415926;

struct LineSegment
{
    double length;
};

class Circle
{
public:
    Circle(LineSegment &line) : m_radius(line){};
    double Area();

private:
    LineSegment &m_radius;
};

double Circle::Area()
{
    return pow(Circle::m_radius.length, 2) * PI;
}

int main()
{
    LineSegment radius{3};
    Circle circle(radius);
    assert(int(circle.Area()) == 28);
}