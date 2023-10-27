#include "Car.hpp"

void Car::turnLeft() { std::cout << __FUNCTION__ << std::endl; }
void Car::turnRight() { std::cout << __FUNCTION__ << std::endl; }
void Car::brake() { speed = 0;}
void Car::accelerate(int speed)
{
    if (speed < 0)
    {
        throw std::out_of_range("Speed cannot be negative");
    }
    else if (!checkSpeed(speed))
    {
        throw std::out_of_range("Maximum speed exceeded");
    }
    else
    {
        this->speed = speed;
    }
}
