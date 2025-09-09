#include <stdio.h>

int max(int T[], int tay)
{
    int m = T[0];
    for (int i = 0; i < tay; i++)
    {
        if (m < T[i])
        {
            m = T[i];
        }
    }
    return m;
}

int min(int T[], int tay)
{
    int m = T[0];
    for (int i = 0; i < tay; i++)
    {
        if (m > T[i])
        {
            m = T[i];
        }
    }
    return m;
}

int somme(int T[], int tay)
{
    int m = 0;
    for (int i = 0; i < tay; i++)
    {
        m = m + T[i];
    }
    return m;
}


void order(int T[], int tay)
{
    
    for (int i = 0; i < tay; i++)
    {
        for (int j = i+1; j < tay; j++)
        {
           if (T[i] > T[j])
           {
            T[i] = T[i] + T[j];
            T[j] = T[i] - T[j];
            T[i] = T[i] - T[j];
           }
           
        }
        
    }
    
}


int rochercher(int valoure , int tay){
    for (int i = 0; i < tay; i++)
    {
        
    }
    
}


int main()
{
    int tay;
    printf("inter tay de le table");
    scanf("%d", &tay);

    int T[tay];
    int T1[tay];

    for (int i = 0; i < tay; i++)
    {
        printf("T1 case %d", i);
        scanf("%d",&T[i]);
    }
    for (int i = 0; i < tay; i++)
    {
        printf("T1 case %d", i);
        scanf("%d",&T1[i]);
    }

    int T2[tay * 2];
    for (int i = 0; i < tay; i++)
    {
        T2[i] = T[i];
    }
    for (int i = tay; i < tay * 2; i++)
    {
        T2[i] = T1[i - tay];
    }

    printf("max = %d ", max(T2, tay * 2));

    printf("min = %d ", min(T2, tay * 2));

    printf("min = %d ", somme(T2, tay * 2));

    for (int i = 0; i < tay*2; i++)
    {
        printf("%d \n",T2[i]);
    }


    


}
