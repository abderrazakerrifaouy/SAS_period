#include <stdio.h>

int main()
{
    int T[] = {10, 11, 5, 0, -1};

    for (int i = 0; i < 5; i++)
    {
        printf("%d \n", T[i]);
    }

    printf("******************\n");

    for (int i = 0; i < 4; i++)
    {
        int min = i;
        for (int j = i + 1; j < 5; j++)
        {
            if (T[min] > T[j])
            {
                min = j;
            }
        }
        if(min != i){
        T[i] = T[i] + T[min];
        T[min] = T[i] - T[min];
        T[i] = T[i] - T[min];
        }
    }

    for (int i = 0; i < 5; i++)
    {
        printf("%d\n", T[i]);
    }
}