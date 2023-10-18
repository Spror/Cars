#include "HybridCar.hpp"

HybridCar::HybridCar(std::unique_ptr<PetrolEngine> petrolEng, std::unique_ptr<ElectricEngine> electricEng) 
: ElectricCar(std::move(electricEng))
, PetrolCar(std::move(petrolEng))
{
    std::cout << __FUNCTION__ << std::endl;
}

HybridCar::~HybridCar() { std::cout << __FUNCTION__ << std::endl; }


 void HybridCar::refill()
 {
    ElectricCar::refill();
    PetrolCar::refill();
 }