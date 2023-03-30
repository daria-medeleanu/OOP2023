#pragma once
#include "Car.h"
#include "Weather.h"
#include <stdlib.h>
class Circuit
{
	Car* vectorDate[100];
	int currentIndex;
	int lenght;
	int weather;
	float vecTime[100];
	char* carName[100];
public:
	Circuit();
	void SetLength(int value);//lungimea circuitului
	void SetWeather(int valueWeather);//0 pentru sunny 1,2 samd
	void AddCar(Car* pointerCar);
	void Race();
	void ShowFinalRanks();
	//void ShowWhoDidNotFinish();
	void printCar();
};

