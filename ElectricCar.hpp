#pragma once
#include "ElectricEngine.hpp"
#include "Car.hpp"

class ElectricCar : virtual public Car
{
public:
    ElectricCar(ElectricEngine* engine);
    ~ElectricCar();
    

    void SetEngine(ElectricEngine* engine);
    ElectricEngine* GetEngine() {return engine_;}
    void refill() override;

private:
    void charge();
    ElectricEngine* engine_;
};

