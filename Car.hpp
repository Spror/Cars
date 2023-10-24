#pragma once

#include <iostream>
#include <memory>
#include "PetrolEngine.hpp"
#include "ElectricEngine.hpp"

class Car
{
public:
    void turnLeft();
    void turnRight();
    void brake();
    void accelerate(int speed);
    int getSpeed() {return speed;}
    virtual void refill() = 0;
    virtual bool changeEngine([[maybe_unused]] std::unique_ptr<ElectricEngine> engine)  {return false;}
    virtual bool changeEngine([[maybe_unused]] std::unique_ptr<PetrolEngine> engine)  {return false;}

    virtual ~Car() = default;

private:
    virtual bool checkSpeed(int speed) = 0; 
    int speed = 0;
};

