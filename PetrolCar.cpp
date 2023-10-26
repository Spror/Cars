#include "PetrolCar.hpp"

PetrolCar::PetrolCar(std::unique_ptr<PetrolEngine> engine)
    : engine_(std::move(engine))
{

    if (engine_.get() == nullptr)
    {
    }

    else
    {
        constexpr auto correctionFactor = 1.5;
        auto capacityLiter = engine_->GetCapacity() / 1000;
        maxSpeed_ = (engine_->GetGears() * engine_->GetPower()) / (float(capacityLiter * correctionFactor));
    }
}

PetrolCar::~PetrolCar() { std::cout << __FUNCTION__ << std::endl; }
void PetrolCar::refuel() { std::cout << __FUNCTION__ << std::endl; }

void PetrolCar::SetPetrolEngine(std::unique_ptr<PetrolEngine> engine)
{
    engine_ = std::move(engine);
}

void PetrolCar::refill()
{
    refuel();
}

void PetrolCar::SetGear(int gear)
{
    engine_->changeGear(gear);
}

bool PetrolCar::changeEngine(std::unique_ptr<PetrolEngine> engine)
{
    std::cout << "Petrol Engine is changed";
    if (getSpeed() != 0)
    {
        return false;
    }

    else
    {
        engine_ = std::move(engine);
        return true;
    }
}

int PetrolCar::GetGear() const
{
    if (engine_.get() == nullptr)
    {
        return -2;
    }

    return engine_->GetCurrentGear();
}

bool PetrolCar::checkSpeed(int speed)
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