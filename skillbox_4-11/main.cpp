#pragma once
#include "Vehicles.h"
#include <iostream>
#include <vector>

int main()
{
    Car c(150, 17, 17, 18, 18, 300);
    std::cout << c << '\n';

    std::cout << "-----------------------------------";
    
    Bicycle t(300, 20, 20);
    std::cout << t << '\n';
}