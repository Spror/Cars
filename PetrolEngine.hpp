#pragma once
#include "Engine.hpp"

class PetrolEngine : virtual public Engine
{
public:
    PetrolEngine(int power, float capacity, int gears);
    void changeGear(int gear);


    float GetCapacity() {return capacity_;}
    int GetGears() {return gears_;}
    int GetCurrentGear() {return currentGear_;}
    void SetCapacity(float capacity);
    void SetGears(int gears);
    void SetCurrentGear(int currentGear);

private:
    float capacity_; // in ccm
    int gears_;
    int currentGear_;
};
