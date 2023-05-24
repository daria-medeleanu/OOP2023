#include "Number.h"
Number Get(Number ex)
{
	return ex;
}
int main()
{
	Number n1("10110010", 2);
	Number n2("734", 8);
	Number n3("FF", 16);
	//printf("n1 has %d digits and it is written in base %d\n", n1.GetDigitsCount(), n1.GetBase());
	//for (int tr = 0; tr < n1.GetDigitsCount(); tr++)
	//{
	//	printf("n1[%d]=%c\n", tr, n1[tr]);
	//}
	//n1.Print();
	//n2.Print();
	n1 = n2 + n3;
	n1.Print();
	//Number n4 = n2;//apel copy constructor
	//Number n4 = Get(Number());//apel move constructor 
	//n4.Print();
	return 0;
}