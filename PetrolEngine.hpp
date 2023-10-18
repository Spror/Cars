#pragma once
#include "Engine.hpp"
#include <stdexcept>

class PetrolEngine : virtual public Engine
{
public:
    PetrolEngine(int power, float capacity, int gears);
    void changeGear(int gear);

    class InvalidGear : public std::exception{
        public:
        InvalidGear(const char* message) : message_(message) {}
        const char* what() const noexcept override {
            return message_.c_str();
        }
        private:
        std::string message_;
    };

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
