#include <iostream>
#include <string>

class Animal
{
public:
    std::string name;
    std::string color;
    int age;

private:
};

class Snake : public Animal
{
public:
    float length;
    void MakeSound()
    {
        std::cout << "Zsssss\n";
    };
};

class Cat : public Animal
{
public:
    float height;
    void MakeSound()
    {
        std::cout << "Meow!\n";
    };
};

int main(int argc, char const *argv[])
{
    Cat cat;
    cat.age = 12;
    cat.height = 2.5;
    Snake snake;
    snake.age = 5;
    snake.length = 5.5;

    cat.MakeSound();
    snake.MakeSound();
    /* code */
    return 0;
}
