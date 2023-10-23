#pragma once

#include <iostream>
#include "Car.hpp"
#include "PetrolEngine.hpp"
#include <memory>


class PetrolCar : virtual public Car
{
public:
    PetrolCar() = default;
    PetrolCar(std::unique_ptr<PetrolEngine> engine);
    ~PetrolCar();
    
    PetrolCar(PetrolCar &&other) noexcept : engine_(std::move(other.engine_)) {}
 


    void SetPetrolEngine(std::unique_ptr<PetrolEngine> engine);
    void SetGear(int gear);
    void refill() override;
    bool changeEngine(std::unique_ptr<PetrolEngine> engine) override;

private:
    std::unique_ptr<PetrolEngine>  engine_;
    void refuel();
};
