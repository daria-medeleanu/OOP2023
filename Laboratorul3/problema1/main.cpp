#include "Math.h"
#include <iostream>
using namespace std;
int main()
{
	cout<<Math::Add(23, 34)<<endl;
	cout<<Math::Add(23, 34, 56)<<endl;
	cout<<Math::Add(1.2, 1.3)<<endl;
	cout<<Math::Add(1.5, 1.5, 1.5)<<endl;
	cout<<Math::Mul(2, 3)<<endl;
	cout<<Math::Mul(2, 3, 4)<<endl;
	cout<<Math::Mul(2.5, 2.5)<<endl;
	cout<<Math::Mul(2.5, 2.5, 2.5)<<endl;
	cout<<Math::Add(10,1, 2, 3, 4, 5, 6, 7, 8, 9, 10)<<endl;
	cout << Math::Add("daria", "aterminatex1");
	return 0;
}