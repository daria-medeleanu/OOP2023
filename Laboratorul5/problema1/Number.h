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
	Number();//constructor default
	Number(const char* string, int base);//constructor
	Number(int value);//constructor pentru int
	Number(const Number& other);//copy constructor
	Number(Number&& other);//move constructor
	~Number();//deconstructor;
	void Print();
	void SwitchBase(int newBase);
	int  GetDigitsCount(); // returns the number of digits for the current number
	int  GetBase(); // returns the current base
	const char* GetData();//returns the Data storred
	char* intToString1(int nr, int base)
	{
		//caz cu 0
		if (nr == 0)
		{
			char* result = new char[2];
			result[0] = '0';
			result[1] = '\0';
			return result;
		}
		//daca nr e negativ
		bool isNegative = false;
		if (nr < 0)
		{
			isNegative = true;
			nr = -nr;
		}
		//cate cifre sunt
		int count = 0;
		int temp = nr;
		while (temp != 0)
		{
			count++;
			temp /= base;
		}
		//alocam memorie pentru result
		int resultSize;
		if (isNegative == 1)
			resultSize = count + 1;
		else
			resultSize = count;
		resultSize++;//pt null
		char* result = new char[resultSize];
		//convertim numarul la baza specificata
		int index = resultSize - 2;//incep de la penultimul element din sir
		while (nr != 0)
		{
			int rest = nr % base;
			char digit;
			if (rest < 10)
			{
				digit = '0' + rest;
			}
			else
			{
				digit = 'A' + rest - 10;
			}
			result[index] = digit;
			index--;
			nr /= base;
		}
		//pune - daca e negativ
		if (isNegative)
		{
			result[0] = '-';
		}
		result[resultSize - 1] = '\0';
		return result;
	}
	char& operator[](unsigned int index)//index operator
	{
		return m_Data[index];
	}
	Number& operator=(const Number& other)//copy assignment operator
	{
		if (this == &other) 
		{
			return *this;
		}
		//Eliberam memoria existenta
		delete[] m_Data;
		//alocare memorie noua
		m_Size = other.m_Size;
		m_Base = other.m_Base;
		m_Data = new char[100]; //+1 pentru null
		strncpy_s(m_Data, m_Size + 1, other.m_Data, m_Size); 
		m_Data[m_Size] = '\0';//punem null
		return *this;
	}
	Number& operator=(int value)//move assignment operator pentru int
	{
		char* string = intToString1(value, m_Base);
		delete[] m_Data;
		m_Size = strlen(string);
		m_Data = new char[100];
		strncpy_s(m_Data, m_Size + 1, string, m_Size);
		m_Data[m_Size] = '\0';
		delete[] string;
		return *this;
	}
	Number& operator=(const char* string)
	{
		delete[] m_Data;
		m_Size = strlen(string);
		m_Data = new char[100];
		strncpy_s(m_Data, m_Size + 1, string, m_Size);
		m_Data[m_Size] = '\0';
		return *this;
	}
	friend Number operator+(const Number& nr1, const Number& nr2);
	friend Number operator-(const Number& nr1, const Number& nr2);
	bool operator>(const Number& nr2);
	bool operator<(const Number& nr2);
	bool operator>=(const Number& nr2);
	bool operator<=(const Number& nr2);
	bool operator==(const Number& nr2);
	Number& operator+=(const Number& nr2);
	Number& operator--();//prefixat
	Number& operator--(int value);//postfixat
};