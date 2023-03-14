#include "Sort.h"
#include <iostream>
using namespace std;
int main()
{
	Sort S;
	int v[] = { 25,22,27,24 };
	//S.CreateArrayRandom(7, 6, 20);
	//S.CreateArrayFromInitializationList();
	S.CreateArrayFromArray(v,4);
	//S.CreateArrayVariadic(10, 8,2,5,4,1,3,7,6,9,10);
	//S.CreateArrayFromString("10,40,100,5,70");
	//S.InsertSort(true);
	//S.BubbleSort(false);
	S.QuickSort(0,3,false);
	S.Print();
	return 0;
}