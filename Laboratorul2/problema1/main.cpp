#include "NumberList.h"
#include <iostream>
using namespace std;
int main()
{
	NumberList N;
	N.Init();
	N.Add(6);
	N.Add(2);
	N.Add(1);
	N.Sort();
	N.Print();
	return 0;
}