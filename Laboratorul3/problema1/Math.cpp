#include "Math.h"
#include <iostream>
#include <stdarg.h>
#include <cstring>
using namespace std; 
int Math::Add(int x, int y)
{
	return x+y;
}
int Math::Add(int x, int y, int z)
{
	return x + y + z;
}
int Math::Add(double x, double y)
{
	return x + y;
}
int Math::Add(double x, double y, double z)
{
	return  x + y + z;
}
int Math::Mul(int x, int y)
{
	return x * y;
}
int Math::Mul(int x, int y, int z)
{
	return x * y * z;
}
int Math::Mul(double x, double y)
{
	return x * y;
}
int Math::Mul(double x, double y, double z)
{
	return x * y * z;
}
int Math::Add(int count, ...)
{
	va_list args;
	va_start(args, count);
	int S = 0;
	for (int i = 0; i < count; i++)
		S=S+va_arg(args, int);
	va_end(args);
	return S;
}
char *Math::Add(const char* s1, const char* s2)
{
	int ls1 = strlen(s1), ls2 = strlen(s2);
	char* s3 = new char[ls1 + ls2];
	if (s1 == nullptr || s2 == nullptr)
		return nullptr;
	else
	{
		for (int i = 0; i < ls1; i++)
			s3[i] = s1[i];
		for (int j = 0; j < ls2; j++)
			s3[ls1 + j] = s2[j];
		s3[ls1 + ls2] = '\0';
	}
	return s3;
}