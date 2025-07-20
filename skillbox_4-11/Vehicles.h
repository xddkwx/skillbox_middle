#pragma once
#include <iostream>
#include "VehicleParts.h"

// * Абстрактный класс Vehicle 
class Vehicle
{
public:
    virtual ~Vehicle() {}; // виртуальный деструктор
    virtual std::ostream& print(std::ostream& out) const = 0;               // * чистая виртуальная функция
    friend std::ostream& operator<<(std::ostream& out, const Vehicle& v);   // * перегрузка operator<<
};
/* --------------------------------------- */

// * Классы WaterVehicle и RoadVehicle, которые наследуют класс Vehicle
class WaterVehicle : public Vehicle
{
protected:
    float draft;    // * осадка
public:
    WaterVehicle(float value);
    std::ostream& print(std::ostream& out) const override;
    float getDraft() const;
};
/* --------------------------------------- */

class RoadVehicle : public Vehicle
{
protected:
    float groundClearance;  // * дорожный просвет
public:
    RoadVehicle(float value);
    std::ostream& print(std::ostream& out) const override;
    float getGroundClearance() const;
};
/* --------------------------------------- */

// * Классы Bicycle и Car, которые наследуют класс RoadVehicle
class Bicycle : public RoadVehicle
{
private:
    // * должен иметь два колеса класса Wheel
    Wheel forwardWheel;
    Wheel backwardWheel;
public:
    Bicycle(
        float gdClearance,
        float fdWheelDiameter,
        float bdWheelDiameter
    );
    std::ostream& print(std::ostream& out) const override;
};
/* --------------------------------------- */

class Car : public RoadVehicle
{
private:
    // * должен иметь 4 колеса класса Wheel и двигатель класса Engine
    // F - forward
    Wheel LFWheel;
    Wheel RFWheel;
    // B - backward
    Wheel LBWheel;
    Wheel RBWheel;
    Engine CarEngine;
public:
    Car(
        float gdClearance,
        float LFWDiameter,
        float RFWDiameter,
        float LBWDiameter,
        float RBWDiameter,
        float Power
    );
    std::ostream& print(std::ostream& out) const override;
};