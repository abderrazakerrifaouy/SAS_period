#include "stdio.h"
#include "string.h"

int affichecaracter()
{

    char str[] = "abderrazak errifaouy devoam 201";

    int conture = 0;
    for (int i = 0; i < strlen(str); i++)
    {
        printf("%c", str[i]);
    }
}
int affichernstring()
{

    char str[] = "abderrazak errifaouy devoam 201";

    int conture = 0;
    for (int i = 1; i < strlen(str); i++)
    {
        if (' ' == str[i])
        {
            conture++;
        }
    }
    conture++;
    printf("%d", conture);
}

int ncaracter()
{
    char str[] = "abd";

    int conture = sizeof(str);
    printf("%d \n", conture - 1);
    printf("%d", strlen(str));
}

int ncaracter_2()
{
    char str[5];
    printf("ecrire le text ; ");
    scanf("%s", str);
    int counteur = 0;
    while (str[counteur] != '\0')
    {
        counteur++;
    }

    printf("%d\n", counteur);
    printf("%s" , str);
}


int challeng4(){
    char str1[100] , str2[100] ;
    printf("enter le 1 str = ");
    scanf("%s",str1);
    printf("enter le 2 str = ");
    scanf("%s",str2);
    int isEquale ;


    if (strlen(str1) == strlen(str2))
    {
        for (int i = 0; i < strlen(str1); i++)
        {
            if (str1[i] != str2[i])
            {
                isEquale = 0 ;
                break;
            }
            isEquale = 1 ;
        }
        

        if (isEquale)
        {
            printf("true");
        }else
        {
            printf("faux");
        }  
    }else
    {
        printf("faux");
    }
    
    
    

}

// int challenge5(){
//  char str[50];

//  printf("ecrire le tsr ; ");
//  scanf("%s",str);
//  for(int i =0 ; i < strlen(str) ; i++ ){
//     for (int j = str; j <0 ; j++)
//     {
//         char s = str[j];
//         str[j] = str[i];
//         str[i] = s ;
//     }
    
//  }
//  printf("%s",str);
// }

int main()
{
    ncaracter_2();
}