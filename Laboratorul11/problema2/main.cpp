#include <iostream>
template <typename T>
class Sortare
{
private:
    T* arr;
    int lg;
    void swap(int* xp, int* yp)
    {
        int temp = *xp;
        *xp = *yp;
        *yp = temp;
    }

public:
    Sortare(T* v, int lg)
    {
        int i;
        this->lg = lg;
        arr = new T[lg];
        for (i = 0; i <= lg - 1; i++)//eroare4: trebuia sa mearga pana la lg-1 inclusiv deci am adaugat =
            arr[i] = v[i + 1];
    }
    void bubbleSort(T* arr, int lg)
    {
        int i, j;
        for (i = 0; i < lg - 1; i++)//eroare2: i-ul mergea pana la antepenultimul element lg - 2 
            for (j = 0; j < lg - i - 1; j++)//eroare 3: j-ul mergea pana la lg - i -2
                if (arr[j] > arr[j + 1])
                    swap(&arr[j], &arr[j + 1]);
    }
    void Afisare(T* arr)
    {
        int i;
        for (i = 0; i < this->lg; i++) //eroare1: i-ul incepea de la 1
            printf("%d ", arr[i]);
    }
};
int main()
{
    int x[] = { 1, 3, 2, 5, 4 };
    Sortare<int> y(x, 5);
    y.bubbleSort(x, 5);
    y.Afisare(x);
}