#include "Engine.hpp"

Engine::Engine(int power) : power_(power)
{
    std::cout << __FUNCTION__ << std::endl;
}

Engine::~Engine()
{
    std::cout << __FUNCTION__ << std::endl;
}

void Engine::SetPower(int power)
{
    power_ = power;
}