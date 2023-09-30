#pragma once
#include <iostream>

class Engine
{
public:
    Engine(int power);
    ~Engine();

    int GetPower() {return power_;}
    void SetPower(int power);

private:
    int power_; // in HP
};