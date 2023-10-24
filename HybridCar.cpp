#include "HybridCar.hpp"

HybridCar::HybridCar(std::unique_ptr<PetrolEngine> petrolEng, std::unique_ptr<ElectricEngine> electricEng)
    : ElectricCar(std::move(electricEng)), PetrolCar(std::move(petrolEng))
{
    if (petrolEng == nullptr && electricEng == nullptr)
    {}

    else if (petrolEng == nullptr)
    {
        maxSpeed_ = ElectricCar::getMaxSpeed();
    }

    else if (electricEng == nullptr)
    {
        maxSpeed_ = PetrolCar::getMaxSpeed();
    }
    

    else
    {
        maxSpeed_ = PetrolCar::getMaxSpeed() + 0.2*ElectricCar::getMaxSpeed();
    }   
}

HybridCar::~HybridCar() { std::cout << __FUNCTION__ << std::endl; }

void HybridCar::refill()
{
    ElectricCar::refill();
    PetrolCar::refill();
}

bool HybridCar::checkSpeed(int speed)
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