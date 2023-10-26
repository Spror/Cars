#pragma once
#include "Engine.hpp"

class ElectricEngine : virtual public Engine
{
public:
    ElectricEngine(int power, int batteryCapacity);

    int GetBatteryCapacity() { return batteryCapacity_; }
    void SetBatteryCapacity(int batteryCapacity);

private:
    int batteryCapacity_; // in Ah
};
