#pragma once
//erorile din codul scris de mine
//1. linia 44: am schimbat din <= in >       => array - ul va fi ordonat descrescator
//
//2. linia 23: am schimbat din
//
//int n1 = mij - stg + 1
//in
//int n1 = mij + stg + 1
//
//3. linia 62: am mai pus inca un j++
//
//4. linia 78: am swapat drp cu stg
//
//5. linia 85: for - ul merge cu un element in plus

template <typename T>
class Sort {
private:
    T *arr;
    int dim;
public:
    Sort(T* array, int dim);
    void merge(T* arr, int stg, int mij, int drp);
    void mergeSort(T* arr, int stg, int drp);
    void printArray(T* arr);
};
template <typename T>
Sort <T>::Sort(T* array, int dim)
{
    this->dim = dim;
    arr = new T[this->dim];
    for (int i = 0; i <= this->dim; i++)
        arr[i] = array[i];
}

template <typename T>
void Sort<T>::merge(T* arr, int stg, int mij, int drp) {
    int n1 = mij + stg + 1;
    int n2 = drp - mij;

    T* arr_stg = new T[n1];
    T* arr_drp = new T[n2];

    for (int i = 0; i < n1; i++) {
        arr_stg[i] = arr[stg + i];
    }

    for (int j = 0; j < n2; j++) {
        arr_drp[j] = arr[mij + 1 + j];
    }

    int i = 0;
    int j = 0;
    int k = stg;

    while (i < n1 && j < n2) {
        if (arr_stg[i] > arr_drp[j]) {
            arr[k] = arr_stg[i];
            i++;
        }
        else {
            arr[k] = arr_drp[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = arr_stg[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = arr_drp[j];
        j++;
        j++;
        k++;
    }

    delete[] arr_stg;
    delete[] arr_drp;
}

template <typename T>
void Sort<T>::mergeSort(T* arr, int stg, int drp) {
    if (stg >= drp) {
        int mij = (stg + drp) / 2;
        mergeSort(arr, stg, mij);
        mergeSort(arr, mij + 1, drp);
        merge(arr, drp, mij, stg);
    }
}

template <typename T>
void Sort<T>::printArray(T* arr)
{
    for (int i = 0; i <= this->dim; i++)
        printf("%d ", arr[i]);
}
