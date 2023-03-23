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
	//Number() = default;
	Number(const char* string, int base);//constructor

	Number(const Number& other)//copy constructor
		:m_Data(other.m_Data)
	{
		printf("Copied\n");
		m_Size = other.m_Size;
		m_Data = new char[m_Size];
		memcpy(m_Data, other.m_Data, m_Size);
	}

	Number(Number&& other) noexcept //move constructor
		:m_Data(other.m_Data)
	{
		printf("Moved!\n");
		m_Size = other.m_Size;
		m_Data = other.m_Data;

		other.m_Data = 0;
		other.m_Data = nullptr;
	}

	~Number()
	{
		printf("Destroyed!\n");
		delete m_Data;
	}
	void Print()
	{
		for (int i = 0; i < m_Size; i++)
			printf("%c", m_Data[i]);
		printf("\n");
	}
	void SwitchBase(int newBase);
	int  GetDigitsCount(); // returns the number of digits for the current number
	int  GetBase(); // returns the current base
	friend int operator+(Number &nr1, Number &nr2);
	//friend int operator-(Number &nr1, Number &nr2);
	Number& operator=(Number&& ex) //move assignment operator
	{	
		for (int i = 0; ex.m_Data[i] != '\0'; i++)
			m_Data[i] = ex.m_Data[i];
	}
	char& operator[](unsigned int index)//index operator
	{
		return m_Data[index];
	}
};