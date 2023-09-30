#include "Car.hpp"
#include "PetrolCar.hpp"
#include "ElectricCar.hpp"
#include "HybridCar.hpp"
#include <iostream>
#include <vector>
#include <memory>

int main()
{

    std::vector<std::shared_ptr<Car>> cars_v;

    
    std::cout << std::endl << "OPEL" << std::endl;
    PetrolCar opel(new PetrolEngine(120, 1800, 6));
    cars_v.push_back(std::make_shared<PetrolCar>(opel));

    cars_v[0].get()->accelerate(50);
    cars_v[0].get()->brake();
    cars_v[0].get()->accelerate(-900);
    cars_v[0].get()->refill();

    std::cout << std::endl << "NISSAN" << std::endl;
    ElectricCar nissan(new ElectricEngine(130, 650));
    cars_v.push_back(std::make_shared<ElectricCar>(nissan));

    cars_v[1].get()->refill();
    cars_v[1].get()->accelerate(80);
    //cars_v[1].get()->engine_ = new ElectricEngine(150, 700);  // Changing an engine during driving is not safe
    cars_v[1].get()->turnLeft();

    std::cout << std::endl << "cars_v[2]get()->" << std::endl;
    HybridCar toyota(new PetrolEngine(80, 1400, 5), new ElectricEngine(100, 540));
    cars_v.push_back(std::make_shared<HybridCar>(toyota));

    
    cars_v[2].get()->accelerate(100);
    cars_v[2].get()->brake();
    cars_v[2].get()->refill();


}
