#pragma once
#include "Vehicles.h"
#include <iostream>
#include <vector>
#include <functional>

// * Получения самого большого power в массиве
float getHighestPower(const std::vector<Vehicle*>& v)
{
    float highest = 0.f;
    for (int i = 0; i < v.size(); ++i)
    {
        if (highest < v[i]->getPower())
        {
            highest = v[i]->getPower();
        }
    }
    return highest;
}

int main()
{
    // * Первая часть
    Car c(Engine(150), Wheel(17), Wheel(17), Wheel(18), Wheel(18), 150);
    std::cout << c << '\n';

    std::cout << "------------------";
    
    Bicycle t(Wheel(20), Wheel(20), 300);
    std::cout << t << '\n';

    std::cout << "-----------------------------------";

    // * Вторая часть
    std::vector<Vehicle*> v;
    v.push_back(new Car(Engine(150), Wheel(17), Wheel(17), Wheel(18), Wheel(18), 250));
    v.push_back(new Bicycle(Wheel(20), Wheel(20), 300));
    v.push_back(new Car(Engine(200), Wheel(19), Wheel(19), Wheel(19), Wheel(19), 130));
    v.push_back(new WaterVehicle(5000));
    
    for (int i = 0; i < v.size(); ++i)
    {
        std::cout << *v[i] << '\n';
        std::cout << "------------------";
    }
    std::cout << "Highest Power in v is " << getHighestPower(v) << '\n';
}