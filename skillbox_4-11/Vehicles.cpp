#pragma once
#include "Vehicles.h"

// * Vehicle
std::ostream& operator<<(std::ostream& out, const Vehicle& v)
{
    return v.print(out);
}
/* --------------------------------------- */

// * WaterVehicle
WaterVehicle::WaterVehicle(float value) : draft(value) {}

std::ostream& WaterVehicle::print(std::ostream& out) const
{
    out << "\nType: Water Vehicle\nDraft: " << draft << " ";
    return out;
}

float WaterVehicle::getDraft() const
{
    return draft;
}
/* --------------------------------------- */

// * RoadVehicle
RoadVehicle::RoadVehicle(float value) : groundClearance(value) {}

std::ostream& RoadVehicle::print(std::ostream& out) const
{
    out << "\nType: Road Vehicle\nGround Clearance: " << groundClearance << " ";
    return out;
}

float RoadVehicle::getGroundClearance() const
{
    return groundClearance;
}
/* --------------------------------------- */

// * Bicycle
Bicycle::Bicycle(float gdClearance, float fdWheelDiameter, float bdWheelDiameter)
    :   RoadVehicle(gdClearance),
        forwardWheel(fdWheelDiameter),
        backwardWheel(bdWheelDiameter) {}

std::ostream& Bicycle::print(std::ostream& out) const
{
    out << "\nType: Bicycle"
        << "\nRide Height: " << groundClearance
        << "\nForward Wheel: " << forwardWheel.getDiameter() << " "
        << "\nBackward Wheel: " << backwardWheel.getDiameter() << " ";
    return out;
}
/* --------------------------------------- */

// * Car
Car::Car(
    float gdClearance,
    float LFWDiameter,
    float RFWDiameter,
    float LBWDiameter,
    float RBWDiameter,
    float Power
    )
    :   RoadVehicle(gdClearance),
        LFWheel(LFWDiameter),
        RFWheel(RFWDiameter),
        LBWheel(LBWDiameter),
        RBWheel(RBWDiameter),
        CarEngine(Power) {}

std::ostream& Car::print(std::ostream& out) const
{
    out << "\nType: Car"
        << "\nRide Height: " << groundClearance
        << "\nEngine Power: " << CarEngine.getPower()
        << "\nWheels:"
        << "\n  LF: " << LFWheel.getDiameter() << " "
        << "\n  RF: " << RFWheel.getDiameter() << " "
        << "\n  LB: " << LBWheel.getDiameter() << " "
        << "\n  RB: " << RBWheel.getDiameter() << " ";
    return out;
}