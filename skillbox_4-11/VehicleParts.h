#pragma once

// * Классы Wheel и Engine
class Wheel
{
private:
    float diameter;     // * диаметр
public:
    Wheel(float v);
    float getDiameter() const;
};
/* --------------------------------------- */
class Engine
{
private:
    float power;        // * мощность
public:
    Engine(float v);
    float getPower() const;
};