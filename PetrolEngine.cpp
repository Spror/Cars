#include "PetrolEngine.hpp"


PetrolEngine::PetrolEngine(int power, float capacity, int gears)
    : Engine(power)
    , capacity_(capacity)
    , gears_(gears)
    , currentGear_(0)
{
    std::cout << __FUNCTION__ << std::endl;
}

void PetrolEngine::changeGear(int gear)
{
    // TODO: Add checking if gear is between -1 and gears_
    // -1 is for REAR
    // 0 is for NEUTRAL

    if(gear  < -1)
        throw "Gear cannot be minus";
    if(gear > gears_)
        throw "Gear not avaliable";
    if(gear == -1 && currentGear_ != 0)
        throw "R means REAR not ROCKET!";


    else
        currentGear_ = gear;
}

void PetrolEngine::SetCapacity(float capacity)
{
    capacity_ = capacity;
}

void PetrolEngine::SetGears(int gears)
{
    gears_ = gears;
}


void PetrolEngine::SetCurrentGear(int currentGear)
{
    currentGear_ = currentGear;
}
