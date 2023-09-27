#pragma once

#include <iostream>
#include "Car.hpp"
#include "PetrolEngine.hpp"


class PetrolCar : virtual public Car
{
public:
    PetrolCar(PetrolEngine *engine);
    ~PetrolCar();
    void refuel();


    PetrolCar GetPetrolEngine() {return engine_;}
    void SetPetrolEngine(PetrolEngine* engine);

private:
    PetrolEngine *engine_;
};
