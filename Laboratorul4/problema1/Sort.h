#pragma once
using namespace std;
class Sort
{
private:
    // add data members
    int size = 100;
    int *x=new int [size];
    int initList[5] = { 10,2,-5,8,7 };
    //int vec[100] = { 1,2,3,4 };
public:
    // add constuctors
    void CreateArrayRandom(int n, int mini, int maxi);
    void CreateArrayFromInitializationList();
    void CreateArrayFromArray(int v[], int size);
    void CreateArrayVariadic(int count, ...);
    void CreateArrayFromString(const char* str);
    void InsertSort(bool ascendent = false);
    void QuickSort(int p,int q, bool ascendent = false);
    int Partitioneaza(int p, int q, bool ascendent = false);
    void BubbleSort(bool ascendent = false);
    void Print();
    int  GetElementsCount();
    int  GetElementFromIndex(int index);
};
