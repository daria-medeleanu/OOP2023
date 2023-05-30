#pragma once
#include <iostream>
//clasa abstracta = are doar metode virtuale
class Car
{
public:
	const char* name;
	int fuelCapacity, fuelConsumption, SpRain, SpSunny, SpSnow;
	float time;
public:
	virtual int GetFuelCapacity()=0;
	virtual int GetFuelConsumption()=0;
	virtual int AvgSpeedRain()=0;
	virtual int AvgSpeedSunny()=0;
	virtual int AvgSpeedSnow()=0;
	virtual const char* GetName() = 0;
	//virtual void SetTime()=0;
	virtual void printData() = 0;
};

