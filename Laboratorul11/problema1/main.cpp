#include <iostream>
#include "Sort.h" 

int main() {
    int arr[] = { 9, 5, 2, 7, 1, 8, 3 };
    int dim = sizeof(arr) / sizeof(arr[0]);

    Sort<int> sorter(arr, dim);
    sorter.mergeSort(arr, 0, dim - 1);

    sorter.printArray(arr);

    return 0;
}

