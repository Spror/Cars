#pragma once
#include "ElectricEngine.hpp"
#include "Car.hpp"
#include <memory>

class ElectricCar : virtual public Car
{
public:
    ElectricCar() = default;
    ElectricCar(std::unique_ptr<ElectricEngine> engine);
    ~ElectricCar();
    ElectricCar(ElectricCar &&other) noexcept : engine_(std::move(other.engine_)) {}

    void SetEngine(std::unique_ptr<ElectricEngine> engine);
    void refill() override;

    bool changeEngine(std::unique_ptr<ElectricEngine> engine) override;

private:
    void charge();
    std::unique_ptr<ElectricEngine> engine_;
};

