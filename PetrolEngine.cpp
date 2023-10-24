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
        throw InvalidGear("Gear cannot be negative");
    if(gear > gears_)
        throw InvalidGear("Gear not avaliable");
    if(gear == -1 && currentGear_ != 0)
        throw InvalidGear("Cannot change gear to reverse from a forward gear!");


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

