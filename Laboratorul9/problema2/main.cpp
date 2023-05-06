#include "Map.h"

int main()
{
    Map<int, const char*> m;
    //m.Set(10, "C++");
    //m.Set(20, "test");
    //printf("%d\n",m.Count());
    //m.Delete(20);
    //printf("%d\n",m.Count());
    //Map<int, const char*> test;
    //test.Set(10, "C++");
    //if (m.Includes(test))
    //    printf("test e inclusa in m\n");
    //else
    //    printf("test nu e inclusa in m\n");
    //printf("%d\n",m.Count());

    m[10] = "C++";
    m[20] = "test";
    m[30] = "Poo";
    for (auto [key, value, index] : m)
    {
        printf("Index:%d, Key=%d, Value=%s\n", index, key, value);
    }
    m[20] = "result";
    for (auto [key, value, index] : m)
    {
        printf("Index:%d, Key=%d, Value=%s\n", index, key, value);
    }
    return 0;
}