#pragma once
#include "PetrolCar.hpp"
#include "ElectricCar.hpp"

class HybridCar : public ElectricCar, public PetrolCar
{
public:
    HybridCar(PetrolEngine *petrolEng, ElectricEngine *electricEng);
    ~HybridCar();
    
    void refill() override;
};
