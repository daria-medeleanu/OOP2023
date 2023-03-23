#include "Number.h"
#include <cstring>
Number::Number(const char* string, int base)//constructor
{
	printf("Created!\n");
	m_Size = strlen(string);
	m_Base = base;
	m_Data = new char[100];
	for (int i = 0; i < m_Size; i++)
		m_Data[i] = string[i];
	//memcpy(m_Data, string, m_Size);
}
int Number::GetDigitsCount()
{
	return m_Size;
}
int Number::GetBase()
{
	return m_Base;
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
	strev(m_Data);
}
int stringToInt(char* string,int base)
{
	int num=0;
	for (int i = 0; i < strlen(string); i++)
		if (base<= 9)
			num = num*10 + (string[i] - '0') ;
		else
			num = num*10 + (string[i] + 10 - 'A');
	return num;
}
int operator+(Number &nr1, Number &nr2)
{
	int biggerBase;
	if (nr1.m_Base > nr2.m_Base)
		biggerBase = nr1.m_Base;
	else
		biggerBase = nr2.m_Base;
	nr1.SwitchBase(biggerBase);
	nr2.SwitchBase(biggerBase);
	int inr1 = stringToInt(nr1.m_Data,nr1.m_Base);
	int inr2 = stringToInt(nr2.m_Data,nr2.m_Base);
	return inr1 + inr2;
}
