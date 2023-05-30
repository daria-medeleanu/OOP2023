#pragma once
#include "Car.h"
#include "Weather.h"
#include <stdlib.h>
class Circuit
{
	Car** cars;
	float circuitLength;
	int numCars;
	int maxCars;
	Weather weather;

public:
	Circuit();
	~Circuit();
	void SetLength(float length);//lungimea circuitului
	void SetWeather(Weather weather);//0 pentru sunny 1,2 samd
	void AddCar(Car* car);
	void Race();
	void ShowFinalRanks();
	void ShowWhoDidNotFinish();
	void printCar();
};