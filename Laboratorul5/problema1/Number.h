#pragma once
#include <cstring>
#include <iostream>

class Number
{
private:
	char* m_Data;
	int m_Size;
	int m_Base;
public:
	Number(const char* string, int base);//constructor
	Number(const Number& other);//copy constructor
	Number(Number&& other);//move constructor
	~Number()
	{
		printf("Destroyed!\n");
		delete m_Data;
	}
	void Print();
	void SwitchBase(int newBase);
	int  GetDigitsCount(); // returns the number of digits for the current number
	int  GetBase(); // returns the current base
	friend int operator+(Number &nr1, Number &nr2);
	Number& operator=(const Number& other)//copy assignment operator
	{
		if (this == &other) // Check for self-assignment
		{
			return *this;
		}

		// Free existing memory
		//delete[] m_Data;

		// Allocate new memory
		m_Size = other.m_Size;
		m_Base = other.m_Base;
		m_Data = new char[m_Size]; // Allocate memory for m_Data, +1 for null-termination
		strcpy_s(m_Data,strlen(other.m_Data+1), other.m_Data); // Copy other.m_Data to m_Data

		//return *this;
	}
	Number& operator= (Number&& ex) //move assignment operator
	{	
		if (this == &ex)
		{
			return *this;
		}
		delete[] m_Data;

		m_Data = ex.m_Data;
		m_Size = ex.m_Size;
		m_Base = ex.m_Base;

		ex.m_Data = nullptr;
		ex.m_Size = 0;
		ex.m_Base = 0;

		return *this;
	}
	char& operator[](unsigned int index)//index operator
	{
		return m_Data[index];
	}
};