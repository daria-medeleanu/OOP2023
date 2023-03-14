#include "Sort.h"
#include <iostream>
#include <cstdlib>
#include <stdarg.h>
using namespace std;
void Sort::CreateArrayRandom(int n, int mini, int maxi)
{
	int range, num;
	this->size = n;
	srand((unsigned)time(NULL));
	for (int i = 0; i < n; ++i)
	{
		range = maxi - mini + 1;
		num = rand() % range + mini;
		*(x + i) = num;
	}
}
int Sort::GetElementFromIndex(int index)
{
	return *(x + index);
}
int Sort::GetElementsCount()
{
	return this->size;
}
void Sort::Print()
{
	for (int i = 0; i < GetElementsCount(); ++i)
		cout << this->GetElementFromIndex(i)<<" ";
}
void Sort::CreateArrayFromInitializationList()
{
	this->size=sizeof(initList)/sizeof(initList[0]);
	for (int i = 0; i < GetElementsCount(); ++i)
		this->x[i] = this->initList[i];
}
void Sort::CreateArrayFromArray(int v[], int size)
{
	this->size = size;
	for (int i = 0; i < GetElementsCount(); ++i)
		this->x[i] = v[i];
}
void Sort::CreateArrayVariadic(int count, ...)
{
	this->size = count;
	va_list args;
	va_start(args, count);
	for (int i = 0; i < count; i++)
		*(x + i) = va_arg(args, int);
	va_end(args);
}
void Sort::CreateArrayFromString(const char* str)
{
	const char* p=str;
	int i = 0, num = 0,k=0;
	while (p[i] != '\0')
	{
		if (p[i] == ',')
		{
			*(x + k) = num;
			k++;
			num = 0;
		}
		else
			num = num * 10 + (p[i] - '0');
		i++;
	}
	*(x + k) = num;
	k++;
	num = 0;
	this->size = k;
}
void Sort::InsertSort(bool ascendent)
{
	for (int i = 1; i < this->size; i++)
	{
		int temp = x[i];
		int j = i - 1;
		if(ascendent==true)
			while (j >= 0 && x[j]>temp)
			{
				x[j + 1] = x[j];
				j--;
			}
		else
			while (j >= 0 && x[j] < temp)
			{
				x[j + 1] = x[j];
				j--;
			}
		if (x[j + 1] != temp)
			x[j + 1] = temp;
	}
}
void Sort::BubbleSort(bool ascendent)
{
	int ultim = this->size - 1,n1;
	bool a;
	while (ultim > 0)
	{
		n1 = ultim - 1;
		ultim = 0;
		for (int i = 0; i <= n1; ++i)
		{
			a = x[i]<x[i+1];
			if ((a+ascendent)==1)
			{
				swap(x[i], x[i + 1]);
				ultim = i;
			}
		}
	}
}
int Sort::Partitioneaza(int p, int q, bool ascendent)
{
	int pivot = x[p];
	int i = p+1, j = q;
	while (i <= j)
	{
		if (ascendent == true)
		{
			if (x[i] <= pivot)
				i++;
			if (x[j] >= pivot)
				j--;
			if (i<j && x[i]>pivot && pivot > x[j])
			{
				swap(x[i], x[j]);
				i++;
				j--;
			}
		}
		else
		{
			if (x[i] >= pivot)
				i++;
			if (x[j] <= pivot)
				j--;
			if (i<j && x[i]<pivot && pivot < x[j])
			{
				swap(x[i], x[j]);
				i++;
				j--;
			}
		}
	}
	int k = i - 1;
	x[p] = x[k];
	x[k] = pivot;
	return k;
}
void Sort::QuickSort(int p, int q,bool ascendent)
{
	if (p < q)
	{
		int k = this->Partitioneaza(p, q, ascendent);
		QuickSort(p, k - 1, ascendent);
		QuickSort(k + 1, q, ascendent);
	}
}