#include <stdio.h>

int main() {
    char nom[50];
    char prenom[50];
    int age ;
    char sexe[20] ;
    char adresseEmail[100] ;
    printf("inter your name ; ");
    scanf("%s", nom );
    scanf("%s", prenom );
    scanf("%d", &age );
    scanf("%s", sexe );
    scanf("%s", adresseEmail );

    printf("the name ; %s \nthe prenom ; %s \nthe age ; %d \n ..." , nom , prenom , &age);
}