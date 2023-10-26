#include "ElectricEngine.hpp"

ElectricEngine::ElectricEngine(int power, int batteryCapacity)
    : Engine(power), batteryCapacity_(batteryCapacity)
{
    std::cout << __FUNCTION__ << std::endl;
}

void ElectricEngine::SetBatteryCapacity(int batteryCapacity)
{
    batteryCapacity_ = batteryCapacity;
}
