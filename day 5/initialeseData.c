#include <stdio.h>


typedef struct
{
    int id;
    char nom[50];
    char Prenom[50];
    
} Joueur;

Joueur data[100];
int counteur = 0 ;

void afficher(){
    if (counteur == 0)
    {
        printf("Aucun joueur n'a ete ajoute.\n");
        return;
    }
    
    for (int i = 0; i < counteur; i++)
    {
        printf("%d / %s / %s ",data[i].id,data[i].nom , data[i].Prenom);
    }
    
}
void inialeData(){
    data[0].id = 1 ;
    strcpy(data[0].nom , "abderrazak");
    strcpy(data[0].Prenom , "elghoul");
    data[1].id = 2 ;
    strcpy(data[1].nom , "youssef");
    strcpy(data[1].Prenom , "elghoul");
    data[2].id = 3 ;
    strcpy(data[2].nom , "amine");
    strcpy(data[2].Prenom , "elghoul");
    counteur = 3 ;
}

int main(){
    afficher();
    inialeData();
    afficher();
    return 0 ;
}