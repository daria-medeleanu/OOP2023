#include <iostream>
#include "NumberList.h"
using namespace std;
void NumberList::Init()
{
	this->count = 0;
	for (int i = 0; i <= 9; i++)
		this->numbers[i] = 0;
}
bool NumberList::Add(int x)
{
	if (this->count >= 10)
		return 0;
	this->numbers[count] = x;
	this->count++;
	return 1;
}
void NumberList::Sort()
{
	for (int i = 0; i < this->count ; i++)
		for (int j = i + 1; j < this->count; j++)
			if (this->numbers[i] > this->numbers[j])
				swap(this->numbers[i], this->numbers[j]);
}
void NumberList::Print()
{
	for (int i = 0; i < count; i++)
		printf("%d ", numbers[i]);
}
