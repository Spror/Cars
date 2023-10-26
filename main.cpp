#include "Car.hpp"
#include "PetrolCar.hpp"
#include "ElectricCar.hpp"
#include "HybridCar.hpp"
#include <iostream>
#include <vector>
#include <memory>

int main()
{

    std::vector<std::unique_ptr<Car>> cars_v;

    std::cout << std::endl
              << "OPEL" << std::endl;
    PetrolCar opel(std::make_unique<PetrolEngine>(120, 1800, 6));
    cars_v.push_back(std::make_unique<PetrolCar>(std::move(opel)));

    cars_v[0].get()->accelerate(50);
    cars_v[0].get()->brake();
    cars_v[0].get()->accelerate(-900);
    cars_v[0].get()->refill();

    std::cout << std::endl
              << "NISSAN" << std::endl;
    ElectricCar nissan(std::make_unique<ElectricEngine>(130, 650));
    cars_v.push_back(std::make_unique<ElectricCar>(std::move(nissan)));

    cars_v[1].get()->refill();
    cars_v[1].get()->changeEngine(std::make_unique<ElectricEngine>(150, 700));
    cars_v[1].get()->accelerate(80);
    std::cout << cars_v[1].get()->changeEngine(std::make_unique<ElectricEngine>(150, 700)); // Changing an engine during driving is not safe
    cars_v[1].get()->turnLeft();

    std::cout << std::endl
              << "cars_v[2]get()->" << std::endl;
    HybridCar toyota(std::make_unique<PetrolEngine>(80, 1400, 5), std::make_unique<ElectricEngine>(100, 540));

    cars_v.push_back(std::make_unique<HybridCar>(std::move(toyota)));
    cars_v[2].get()->accelerate(100);
    cars_v[2].get()->brake();
    cars_v[2].get()->refill();
}
