#include "ElectricCar.hpp"

ElectricCar::ElectricCar(std::unique_ptr<ElectricEngine> engine)
    : engine_(std::move(engine))
{

    if (engine_.get() == nullptr)
    {}

    else
    {
        constexpr auto correctionFactor = 0.03;
        maxSpeed_ = engine_->GetPower()* engine_->GetBatteryCapacity()  *correctionFactor;
        std::cout << maxSpeed_;
    }
}

ElectricCar::~ElectricCar() { std::cout << __FUNCTION__ << std::endl; }
void ElectricCar::charge() { std::cout << __FUNCTION__ << std::endl; }

void ElectricCar::SetEngine(std::unique_ptr<ElectricEngine> engine)
{
    engine_ = std::move(engine);
}

void ElectricCar::refill()
{
    charge();
}

bool ElectricCar::changeEngine(std::unique_ptr<ElectricEngine> engine)
{
    std::cout << "Electric Engine is changed";
    if (getSpeed() != 0)
        return false;

    else
    {
        engine_ = std::move(engine);
        return true;
    }
}

bool ElectricCar::checkSpeed(int speed)
{
    if (speed > maxSpeed_)
    {
        return false;
    }
    else
    {
        return true;
    }
}