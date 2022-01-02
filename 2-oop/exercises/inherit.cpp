#include <iostream>
#include <string>

class Vehicle
{
public:
    int wheels = 0;
    std::string color = "blue";
    std::string brand = "";

    void Print() const
    {
        std::cout << "This " << color << " vehicle has " << wheels << " wheels!\n";
    }
};

class Car : public Vehicle
{
public:
    bool sunroof = false;
};

class Bicycle : public Vehicle
{
public:
    bool kickstand = true;
};

class Truck : public Vehicle
{
public:
    bool isTrailer = false;
};

int main()
{
    Car car;
    car.wheels = 4;
    car.sunroof = true;
    car.Print();
    if (car.sunroof)
        std::cout << "And a sunroof!\n";

    Truck truck;
    truck.wheels = 6;
    truck.color = "red";
    truck.Print();
};