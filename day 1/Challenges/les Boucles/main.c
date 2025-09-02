#include <stdio.h>
// challenge 1
// int main() {
//     for ( int i = 1 ; i < 11 ; i++){
//         int result = i4 ;
//         printf("numeber %d ==> %d \n",i , result);
//     }
// }


// Challenge 2 

// int main(){
//     int number ;
//     int  factorielle = 1 ;
//     printf("inter your namber : ");
//     scanf("%d",&number);
//     for (int i = 1 ; i <= number ; i++){
//         factorielle = factorielle i ;
//     }
//     printf("le factorielle %d ==> %d" , number , factorielle);
//     return 0 ; 
// }

// Challenge 3

int main(){
     int number ;
     int  somme = 0 ;
     printf("inter your namber : ");
     scanf("%d",&number);
     for( int i = 0 ; i <= number ; i++){
        somme = somme + i ;
     }
     printf("somme = %d ", somme);
}