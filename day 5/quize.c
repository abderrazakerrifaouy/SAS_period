#include <stdio.h>
#include <string.h>


int main(){
    int input = 10 ;

    for (int i = 0; i <= input*2; i++)
    {
        for (int j = 0; j <= input*2; j++)
        {
            if ( i + j == input || j - input == i ||  i - input == j || i + j == input*2+input  || j == input || i == input )
            {
                printf("*");
            }else if (i < input && j < input && i+j>input)
            {
                printf("*");
            }else if (i > input && j > input && i+j<input*3)
            {
                printf("*");
            }else if (i>input && j<input && i - j < input)
            {
                printf("*");
            }else if (i<input && j>input && j-i<input)
            {
                printf("*");
            }
            
            
            else
            {
                printf(" ");
            }
        }
        printf("\n");
    }
    
}