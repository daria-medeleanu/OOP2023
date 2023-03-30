#include "Circuit.h"
Circuit::Circuit()
{
	this->currentIndex = 0;
	this->lenght = 0;
	this->weather = 0;
}

void Circuit::AddCar(Car* pointerCar)
{
	this->vectorDate[currentIndex++] = pointerCar;
}

void Circuit::SetLength(int value)
{
	this->lenght = value;
}

void Circuit::SetWeather(int valueWeather)
{
	switch (valueWeather){
		case 0: this->weather = 0;
			break;
		case 1: this->weather = 1;
			break;
		case 2: this->weather = 2;
			break;
	}
}

void Circuit::Race()
{
	for (int i = 0; i < this->currentIndex; i++)
	{
		switch (this->weather)
		{
		case 0:this->vectorDate[i]->time =(float)this->lenght / this->vectorDate[i]->AvgSpeedRain();
			break;
		case 1:this->vectorDate[i]->time = (float)this->lenght / this->vectorDate[i]->AvgSpeedSunny();
			break;
		case 2:this->vectorDate[i]->time = (float)this->lenght / this->vectorDate[i]->AvgSpeedSnow();
			break;
		}
	}
}

//it will print the time each car needed to finish the circuit sorted from the fastest car to the slowest.
void Circuit::ShowFinalRanks()
{
	
	for (int i = 0; i < currentIndex; i++)
	{
		vecTime[i] = this->vectorDate[i]->time;
		//strcpy_s(carName[i],100, this->vectorDate[i]->GetName());
	}
	//sortare dupa timp
	for(int i=0;i<currentIndex-1;i++)
		for(int j=i+1;j<currentIndex;j++)
			if (this->vectorDate[i]->time > this->vectorDate[j]->time)
			{
				float aux = vecTime[i];
				vecTime[i] = vecTime[j];
				vecTime[j] = aux;
				
			}
	for (int i = 0; i < currentIndex; i++)
	{
		printf("%f de la %s\n", vecTime[i],this->vectorDate[i]->name);
		//strcpy_s(carName[i],100, this->vectorDate[i]->GetName());
	}
}			

void Circuit::printCar()
{
	for (int i = 0; i < this->currentIndex; i++)
		this->vectorDate[i]->printData();
}
