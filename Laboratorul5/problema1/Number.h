#pragma once
#include <cstring>
#include <iostream>
#pragma warning(suppress : 4996)
class Number
{
private:
	char* m_Data;
	int m_Size;
	int m_Base;
public:
	Number();//constructor default
	Number(const char* string, int base);//constructor
	Number(const Number& other);//copy constructor
	Number(Number&& other);//move constructor
	~Number();//deconstructor;
	void Print();
	void SwitchBase(int newBase);
	int  GetDigitsCount(); // returns the number of digits for the current number
	int  GetBase(); // returns the current base
	const char* GetData();//returns the Data storred
	char& operator[](unsigned int index)//index operator
	{
		return m_Data[index];
	}
	Number& operator=(const Number& other)//copy assignment operator
	{
		if (this == &other) // Check for self-assignment
		{
			return *this;
		}
		//Eliberam memoria existenta
		delete[] m_Data;
		//alocare memorie noua
		m_Size = other.m_Size;
		m_Base = other.m_Base;
		m_Data = new char[m_Size + 1]; //+1 pentru null
		strncpy_s(m_Data, m_Size + 1, other.m_Data, m_Size); 
		m_Data[m_Size] = '\0';//punem null
		return *this;
	}
	friend Number operator+(Number& nr1, Number& nr2);
};