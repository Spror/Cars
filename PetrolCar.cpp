#include "PetrolCar.hpp"

 
PetrolCar::PetrolCar(PetrolEngine* engine)
    : engine_(engine)
{
    std::cout << __FUNCTION__ << std::endl;
}

PetrolCar::~PetrolCar()         { std::cout << __FUNCTION__ << std::endl; }
void PetrolCar::refuel()        { std::cout << __FUNCTION__ << std::endl; }

void PetrolCar::SetPetrolEngine(PetrolEngine* engine)
{
    if(engine_ != nullptr)
        delete engine_;
    engine_ = engine;
}

void PetrolCar::refill()
{
    refuel();
}