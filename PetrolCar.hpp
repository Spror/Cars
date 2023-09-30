#pragma once

#include <iostream>
#include "Car.hpp"
#include "PetrolEngine.hpp"


class PetrolCar : virtual public Car
{
public:
    PetrolCar(PetrolEngine *engine);
    ~PetrolCar();
    


    PetrolCar GetPetrolEngine() {return engine_;}
    void SetPetrolEngine(PetrolEngine* engine);
    void refill() override;

private:
    PetrolEngine *engine_;
    void refuel();
};
