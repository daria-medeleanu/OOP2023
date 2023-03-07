#include <iostream>
#include "Canvas.h"
using namespace std;
int main()
{
	Canvas C(10,10);
	C.DrawLine(5,2,3,2,'*');
	C.Clear();
	C.SetPoint(4, 5, '*');
	C.Clear();
	C.DrawRect(1, 2, 5, 7, '*');
	C.FillRect(1, 2, 5, 7, '-');
	C.Clear();
	C.DrawCircle(4, 4, 4, '*');
	C.FillCircle(5, 5, 4, '-');
	C.Print();
}