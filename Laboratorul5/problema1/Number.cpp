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
Number::Number(const Number& other)//copy constructor
	:m_Size(other.m_Size), m_Base(other.m_Base)
{
	printf("Copied\n");
	m_Data = new char[m_Size + 1];
	memcpy(m_Data, other.m_Data, m_Size);
	m_Data[m_Size] = '\0';
}
Number::Number(Number&& other)//move constructor
	:m_Data(other.m_Data)
{
	printf("Moved!\n");
	m_Size = other.m_Size;
	m_Data = other.m_Data;
	m_Base = other.m_Base;
	other.m_Base = 0;
	other.m_Size = 0;
	other.m_Data = nullptr;
}
char reVal(int num)
{
	if (num >= 0 && num <= 9)
		return (char)(num + '0');
	else
		return (char)(num - 10 + 'A');
}
void strev(char* str)
{
	for (int i = 0; i < strlen(str) / 2; i++)
	{
		char temp = str[i];
		str[i] = str[strlen(str) - i - 1];
		str[strlen(str) - i - 1] = temp;
	}
}
void Number::SwitchBase(int newBase)
{
	int oldBase = GetBase();
	//convert oldBase -> baza 10
	int p = 1;
	for (int i = 1; i < GetDigitsCount(); i++)
		p = p * oldBase;
	int num = 0;
	for (int i = 0; i < GetDigitsCount(); i++)
	{
		if (oldBase <= 9)
			num += (m_Data[i] - '0') * p;
		else
			num += (m_Data[i] + 10 - 'A')*p;
		p /= oldBase;
	}
	//convert baza 10 -> newBase
	int index = 0;
	while (num > 0)
	{
		m_Data[index++] = reVal(num % newBase);
		num /= newBase;
	}
	m_Data[index] = '\0';
	m_Size = index;
	m_Base = newBase;
	strev(m_Data);
}
int stringToInt(const char* string,int base)
{
	int num=0;
	for (int i = 0; i < strlen(string); i++)
		if (base<= 9)
			num = num*base + (string[i] - '0') ;
		else
			if (string[i] >= 'A' && string[i] <= 'F')
				num = num * base + (string[i] - 'A' + 10);
	return num;
}
//char* intToString(int nr, int base)
//{
//
//}
Number operator+(Number& nr1, Number& nr2)
{
	int biggerBase;
	if (nr1.GetBase() > nr2.GetBase())
		biggerBase = nr1.GetBase();
	else
		biggerBase = nr2.GetBase();
	Number temp1 = nr1;
	temp1.SwitchBase(10);
	Number temp2 = nr2;
	temp2.SwitchBase(10);
	int inr1 = stringToInt(temp1.GetData(), temp1.GetBase());
	int inr2 = stringToInt(temp2.GetData(), temp2.GetBase());
	int sum = inr1 + inr2;
	return temp1;
}