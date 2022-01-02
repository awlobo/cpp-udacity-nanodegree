#include <cassert>
#include <cmath>
#include <stdexcept>
#include <iostream>
#include <string>

class Sphere
{
public:
    Sphere(int radius) : radius_(radius)
    {
        if (radius < 0)
        {
            throw std::invalid_argument("Radius must be greater than 0");
        }
    };
    static float Volume(int radius)
    {
        return (4.0 / 3.0) * M_PI * pow(radius, 3);
    }
    int Radius() const;
    void Radius(int radius);
    int Volume() const;

private:
    int radius_;
};

int Sphere::Radius() const
{
    return radius_;
}

void Sphere::Radius(int radius)
{
    if (radius < 0)
    {
        throw std::invalid_argument("Radius must be greater than 0");
    }
    radius_ = radius;
}

int Sphere::Volume() const
{
    return M_PI * 4 / 3 * pow(radius_, 3);
}

// Test
int main(void)
{
    Sphere sphere(5);
    assert(sphere.Radius() == 5);
    assert(abs(sphere.Volume() - 523.6) < 1);
}
