#pragma once
#include "Car.h"
class Seat : public Car
{
    int fuelCapacity, fuelConsumption, SpRain, SpSunny, SpSnow;
    float time;
    const char* name;
    int GetFuelCapacity()
    {
        return this->fuelCapacity;
    }
    int GetFuelConsumption()
    {
        return this->fuelConsumption;
    }
    int AvgSpeedRain()
    {
        return this->SpRain;
    }
    int AvgSpeedSunny()
    {
        return this->SpSunny;
    }
    int AvgSpeedSnow()
    {
        return this->SpSnow;
    }
    void printData()
    {
        printf("Seat\n");
    }
public:
    Seat();
};

