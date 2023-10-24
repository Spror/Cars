#pragma once
#include "Engine.hpp"
#include <stdexcept>

class PetrolEngine : virtual public Engine
{
public:
    PetrolEngine(int power, float capacity, int gears);
    
    class InvalidGear : public std::logic_error{
        public:
        InvalidGear(const char* message) : std::logic_error(message) {}
    };

    float GetCapacity() const {return capacity_;} 
    int GetGears() const {return gears_;} 
    int GetCurrentGear() const {return currentGear_;} 

    void SetCapacity(float capacity); 
    void SetGears(int gears);
    void changeGear(int gear);


private:
    float capacity_; // in ccm
    int gears_;
    int currentGear_ = 0;
};
