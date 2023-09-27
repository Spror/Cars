#pragma once
#include "ElectricEngine.hpp"
#include "Car.hpp"

class ElectricCar : virtual public Car
{
public:
    ElectricCar(ElectricEngine* engine);
    ~ElectricCar();
    void charge();

    void SetEngine(ElectricEngine* engine);
    ElectricEngine* GetEngine() {return engine_;}

private:
    ElectricEngine* engine_;
};

