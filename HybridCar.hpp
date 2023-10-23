#pragma once
#include "PetrolCar.hpp"
#include "ElectricCar.hpp"

class HybridCar : public ElectricCar, public PetrolCar
{
public:
    HybridCar() = default;
    HybridCar(std::unique_ptr<PetrolEngine> petrolEng, std::unique_ptr<ElectricEngine> electricEng);
    ~HybridCar();

    
    HybridCar(HybridCar &&other) noexcept :  ElectricCar(std::move(other)), PetrolCar(std::move(other)) {}


    void refill() override;
};
