#pragma once
#include "PetrolCar.hpp"
#include "ElectricCar.hpp"

class HybridCar : public ElectricCar, public PetrolCar
{
public:
    HybridCar(std::unique_ptr<PetrolEngine> petrolEng, std::unique_ptr<ElectricEngine> electricEng);
    ~HybridCar();

    
    HybridCar(HybridCar &&other) noexcept : PetrolCar(std::move(other)), ElectricCar(std::move(other)) {}


    void refill() override;
};
