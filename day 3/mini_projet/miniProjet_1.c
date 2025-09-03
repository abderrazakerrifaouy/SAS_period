#include <stdio.h>
#include <string.h>

char titre[100][50];
char auteur[100][50];
double prix[100];
int quantite[100];
int nLiver = 0;

char name[10];
int age;

void addLivre()
{

    printf("Titre du liver ; ");
    scanf("%s", titre[nLiver]);
    printf("Auteur du liver ; ");
    scanf("%s", auteur[nLiver]);
    printf("Prix du liver ; ");
    scanf("%lf", &prix[nLiver]);
    printf("Quantite en stock ; ");
    scanf("%d", &quantite[nLiver]);
    nLiver++;
}

void afficherAll()
{
    for (int i = 0; i < nLiver; i++)
    {
        afficherLivre(i);
    }
}
void afficherLivre(int i)
{
    if (i >= 0)
    {
        printf("le liver %d ==> \n\tle Titre = %s , \n\tle auteur = %s , \n\tle prix = %2lf , \n\tle quantite = %d", i + 1, titre[i], auteur[i], prix[i], quantite[i]);
    }
    else
    {
        printf("this titel is note correct");
    }
}

int Rechercher(char t[50])
{
    for (int i = 0; i < nLiver; i++)
    {
        if (strcmp(t, titre[i]) == 0)
        {
            return i;
        }
    }
    return -1;
}

void updateLivre(int i, int m)
{
    switch (m)
    {
    case 1:
        printf("Écrivez new Titer ; ");
        scanf("%s", titre[i]);
        break;
    case 2:
        printf("Écrivez new auteur ; ");
        scanf("%s", auteur[i]);
        break;
    case 3:
        printf("Écrivez new prix ; ");
        scanf("%lf", prix[i]);
        break;
    case 4:
        printf("Écrivez new quantite ; ");
        scanf("%d", quantite[i]);
        break;

    default:
        break;
    }
}

void Supprimer(int i)
{
    for (int j = i; j < nLiver; j++)
    {
        strcpy(titre[j], titre[j + 1]);
        strcpy(auteur[j], auteur[j + 1]);
        prix[j] = prix[j + 1];
        quantite[j] = quantite[j + 1];
    }
    nLiver--;
}

int main()
{
    int y = 0;
    do
    {
        printf("\n\n\n");
        printf("                          |*************************************************|   \n");
        printf("                          |                   Menu                          |   \n");
        printf("                          |                                                 |   \n");
        printf("                          |**************************************************   \n");
        printf("                          |                                                 |   \n");
        printf("                          |       1. Ajouter une livre                      |   \n");
        printf("                          |       2. Afficher tous les livres disponibles   |   \n");
        printf("                          |       3. Rechercher un livre par son titre      |   \n");
        printf("                          |       4. Mettre a jour la quantite d'un livre   |   \n");
        printf("                          |       5. Supprimer un livre du stock.           |   \n");
        printf("                          |       6. Le nombre total de livres en stock     |   \n");
        printf("                          |       7. Quite                                  |   \n");
        printf("                          |                                                 |   \n");
        printf("                          |*************************************************|   \n\n\n");
        printf("Quel est votre choix ? : ");
        scanf("%d", &y);

        switch (y)
        {
        case 1:
            addLivre();
            break;
        case 2:
            afficherAll();
            break;
        case 3:
            char t[50];
            printf("Quel est le titre de livre ; ");
            scanf("%s", t);
            int ir = Rechercher(t);
            afficherLivre(ir);
            break;
        case 4:
            int lechio;
            char le_titrem[50];
            printf("Quel est le titre de livre ; ");
            scanf("%s", le_titrem);
            int im = Rechercher(le_titrem);
            printf("\n\n\n\t\t\t 1 =>  le titer \n\t\t\t 2 =>  le auteur\n\t\t\t 3 =>  le prix\n\t\t\t 4 =>  le quantite");
            scanf("%d", &lechio);
            updateLivre(im, lechio);
            break;
        case 5:
            char le_titres[50];
            printf("Quel est le titre de livre ; ");
            scanf("%s", le_titres);
            int is = Rechercher(le_titres);
            Supprimer(is);
            break;
        case 6:
            printf(" Le nombre total de livres en stock ==> %d \n", nLiver);
            break;
        default:
            break;
        }
    } while (y != 7);
}