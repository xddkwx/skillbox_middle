#pragma once
#include "VehicleParts.h"

// Wheel
Wheel::Wheel(float v) : diameter(v) {}
float Wheel::getDiameter() const
{
    return diameter;
}

// Engine
Engine::Engine(float v) : power(v) {}
float Engine::getPower() const
{
    return power;
}