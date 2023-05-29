#include "Number.h"
#include <cstring>
Number::Number()
{
	printf("Constructor default!\n");
}
Number::Number(const char* string, int base)//constructor
{
	printf("Created!\n");
	m_Size = strlen(string);
	m_Base = base;
	m_Data = new char[100];
	for (int i = 0; i < m_Size; i++)
		m_Data[i] = string[i];
	//memcpy(m_Data, string, m_Size); in loc de for
	m_Data[m_Size] = '\0';
}
char* intToString(int nr, int base)
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
Number::Number(int value)
{
	char* string = intToString(value, 10);
	m_Size = strlen(string);
	m_Base = 10;
	m_Data = new char[100];
	for (int i = 0; i < m_Size; i++)
		m_Data[i] = string[i];
	//memcpy(m_Data, string, m_Size); in loc de for
	m_Data[m_Size] = '\0';
}
Number::~Number()
{
	printf("Destroyed!\n");
	delete [] m_Data;
}
int Number::GetDigitsCount()
{
	return m_Size;
}
int Number::GetBase() 
{
	return m_Base;
}
const char* Number::GetData()
{
	return m_Data;
}
void Number:: Print()
{
	for (int i = 0; i < m_Size; i++)
		printf("%c", m_Data[i]);
	printf("\n");
}
Number::Number(const Number& other)
	: m_Size(other.m_Size), m_Base(other.m_Base)
{
	printf("Copied\n");
	//m_Data = new char[m_Size + 1];
	m_Data = new char[100];
	memcpy(m_Data, other.m_Data, m_Size + 1);
}
Number::Number(Number&& other) 
	: m_Size(other.m_Size), m_Base(other.m_Base), m_Data(other.m_Data)
{
	printf("Moved!\n");
	other.m_Base = 0;
	other.m_Size = 0;
	other.m_Data = nullptr;
}

void ReverseString(char* str)
{
	int length = strlen(str);
	for (int i = 0; i < length / 2; i++)
	{
		char temp = str[i];
		str[i] = str[length - i - 1];
		str[length - i - 1] = temp;
	}
}
void Number::SwitchBase(int newBase)
{
	int oldBase = GetBase();
	// Convert oldBase -> base 10
	int p = 1;
	for (int i = 1; i < GetDigitsCount(); i++)
		p = p * oldBase;
	int num = 0;
	for (int i = 0; i < GetDigitsCount(); i++)
	{
		if (oldBase <= 9)
			num += (m_Data[i] - '0') * p;
		else
			if(m_Data[i]>='A' && m_Data[i]<='F')
				num += (m_Data[i] + 10 - 'A') * p;
			else
				num += (m_Data[i] - '0') * p;
		p /= oldBase;
	}

	// Convert base 10 -> newBase
	// Set null in m_Data
	memset(m_Data, 0, sizeof(m_Data));
	int k = 0, rest = 0;
	while (num != 0)
	{
		rest = num % newBase;
		if (rest <= 9)
			m_Data[k++] = rest + '0';
		else
			m_Data[k++] = rest - 10 + 'A';
		num /= newBase;
	}
	m_Data[k] = '\0';
	ReverseString(m_Data);
	m_Base = newBase;
	m_Size = strlen(m_Data);
}
int stringToInt(const char* string,int base)
{
	int num=0;
	for (int i = 0; i < strlen(string); i++)
		if (base<= 10)
			num = num*base + (string[i] - '0') ;
		else
			if (string[i] >= 'A' && string[i] <= 'F')
				num = num * base + (string[i] - 'A' + 10);
			else
				num = num * base + (string[i] - '0');
	return num;
}
Number operator+(const Number& nr1, const Number& nr2)
{
	int biggerBase;
	if (nr1.m_Base > nr2.m_Base)
		biggerBase = nr1.m_Base;
	else
		biggerBase = nr2.m_Base;
	int num1 = stringToInt(nr1.m_Data, nr1.m_Base);
	int num2 = stringToInt(nr2.m_Data, nr2.m_Base);
	int sum = num1 + num2;
	char* resultData = intToString(sum, biggerBase);
	Number result(resultData, biggerBase);
	delete[] resultData;
	return result;
}
Number operator-(const Number& nr1, const Number& nr2)
{
	int biggerBase;
	if (nr1.m_Base > nr2.m_Base)
		biggerBase = nr1.m_Base;
	else
		biggerBase = nr2.m_Base;
	int num1 = stringToInt(nr1.m_Data, nr1.m_Base);
	int num2 = stringToInt(nr2.m_Data, nr2.m_Base);
	int dif = num1 - num2;
	char* resultData = intToString(dif, biggerBase);
	Number result(resultData, biggerBase);
	delete[] resultData;
	return result;
}
bool Number::operator>(const Number& nr2)
{
	int num1 = stringToInt(this->GetData(), this->GetBase());
	int num2 = stringToInt(nr2.m_Data, nr2.m_Base);
	if (num1 > num2)
		return 1;
	else
		return 0;
}
bool Number::operator<(const Number& nr2)
{
	int num1 = stringToInt(this->GetData(), this->GetBase());
	int num2 = stringToInt(nr2.m_Data, nr2.m_Base);
	if (num1 < num2)
		return 1;
	else
		return 0;
}
bool Number::operator>=(const Number& nr2)
{
	int num1 = stringToInt(this->GetData(), this->GetBase());
	int num2 = stringToInt(nr2.m_Data, nr2.m_Base);
	if (num1 >= num2)
		return 1;
	else
		return 0;
}
bool Number::operator<=(const Number& nr2)
{
	int num1 = stringToInt(this->GetData(), this->GetBase());
	int num2 = stringToInt(nr2.m_Data, nr2.m_Base);
	if (num1 <= num2)
		return 1;
	else
		return 0;
}
bool Number::operator==(const Number& nr2)
{
	int num1 = stringToInt(this->GetData(), this->GetBase());
	int num2 = stringToInt(nr2.m_Data, nr2.m_Base);
	if (num1 == num2)
		return 1;
	else
		return 0;
}
Number& Number::operator+=(const Number& nr2)
{
	int biggerBase;
	if (this->m_Base > nr2.m_Base)
		biggerBase = this->m_Base;
	else
		biggerBase = nr2.m_Base;
	int num1 = stringToInt(m_Data, m_Base);
	int num2 = stringToInt(nr2.m_Data, nr2.m_Base);
	int sum = num1 + num2;
	char* resultData = intToString(sum, biggerBase);
	delete[] m_Data;
	m_Size = strlen(resultData);
	m_Data = new char[100];
	strncpy_s(m_Data, m_Size + 1, resultData, m_Size);
	m_Data[m_Size] = '\0';
	delete[] resultData;
	return *this;
}
Number& Number::operator--()//prefixat
{
	//fara primul caracter din m_Data
	//parcurg pana la m_Size+1 si mut totul cu o pozitie la stanga
	for (int i = 1; i <= m_Size + 1; i++)
		m_Data[i - 1] = m_Data[i];
	m_Size = m_Size-1;
	m_Data[m_Size] = '\0';
	return *this;
}
Number& Number::operator--(int value)
{
	//fara ultimul caracter din m_Data
	//mut '\0'
	m_Data[m_Size] = '\0';
	m_Size = m_Size - 1;
	return *this;
}