#include "Circuit.h"
Circuit::Circuit()
{
	cars = nullptr;
	circuitLength = 0;
	weather = Weather::Rain;
	numCars = 0;
	maxCars = 0;
}
Circuit::~Circuit()
{
	if (cars != nullptr) {
		for (int i = 0; i < numCars; i++) {
			delete cars[i];
		}
		delete[] cars;
	}
}
void Circuit::SetLength(float length)
{
	circuitLength = length;
}
void Circuit::SetWeather(Weather weather)
{
	this->weather = weather;
}
void Circuit::AddCar(Car* car)
{
	if (numCars >= maxCars) {
		int newMaxCars = (maxCars == 0) ? 1 : maxCars * 2;
		Car** newCars = new Car * [newMaxCars];
		if (cars != nullptr) {
			for (int i = 0; i < numCars; i++) {
				newCars[i] = cars[i];
			}
			delete[] cars;
		}
		cars = newCars;
		maxCars = newMaxCars;
	}
	cars[numCars] = car;
	numCars++;
}
//determina timpul necesar pentru fiecare masina in parte sa termine circuitul in conditiile de vreme curente
void Circuit::Race()
{
	for (int i = 0; i < numCars; i++) 
	{
		float avgSpeed;
		switch (weather) {
		case 0:  //rain
			avgSpeed = cars[i]->AvgSpeedRain();
			break;
		case 1:  //sunny
			avgSpeed = cars[i]->AvgSpeedSunny();
			break;
		case 2:  //snow
			avgSpeed = cars[i]->AvgSpeedSnow();
			break;
		default:
			avgSpeed = 0.0f;
		}
		float time = circuitLength / avgSpeed;
		cars[i]->time = time;
	}
}

//it will print the time each car needed to finish the circuit sorted from the fastest car to the slowest.
void Circuit::ShowFinalRanks() 
{
	//facem vector pentru a sorta
	Car** sortedCars = new Car* [numCars];
	for (int i = 0; i < numCars; i++) {
		sortedCars[i] = cars[i];
	}

	//sortam in functie de timp
	for (int i = 0; i < numCars - 1; i++) 
	{
		for (int j = i + 1; j < numCars; j++) 
		{
			if (sortedCars[i]->time > sortedCars[j]->time) 
			{
				Car* temp = sortedCars[i];
				sortedCars[i] = sortedCars[j];
				sortedCars[j] = temp;
			}
		}
	}
	//afisam
	for (int i = 0; i < numCars; i++)
		std::cout << "Car " << i + 1 << ": " << sortedCars[i]->GetName() << ", Time: " << sortedCars[i]->time << " seconds" << std::endl;
	delete[] sortedCars;
}

//it is possible that some cars don't have enough fuel to finish the circuit
void Circuit::ShowWhoDidNotFinish()
{
	//calculam de cati litri are nevoie fiecare masina in fuelNeeded, daca fuelNeeded>fuelCapacity nu poate termina
	bool didNotFinish = false;
	for (int i = 0; i < numCars; i++)
	{
		float fuelNeeded = (cars[i]->GetFuelConsumption()*circuitLength)/100;
		if (fuelNeeded > cars[i]->GetFuelCapacity())
		{
			didNotFinish = true;
			printf("%s nu a terminat cursa pentru ca a ramas fara fuel\n", cars[i]->GetName());
		}
	}
	if (didNotFinish == false)
		printf("Toate masinile au terminat cursa.\n");

}
void Circuit::printCar()
{
	for (int i = 0; i < this->numCars; i++)
		printf("%s\n", cars[i]->GetName());
}