#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define RED "\033[0;31m"
#define GREEN "\033[0;32m"
#define YELLOW "\033[0;33m"
#define BLUE "\033[0;34m"
#define CYAN "\033[0;36m"
#define RESET "\033[0m"

struct Contact
{
    char nom[50];
    char numero_de_telephone[50];
    char adresse_e_mail[50];
};

struct Contact contacts[100];
int conteur = 0;
void afficher_le_contact(int i);
void ajouter();
void Modifier(int index_contact);
void afficher_tous_les_contacts();
int Supprimer(int index_contact);
int Rechercher(char nom_contact[50]);

int main()
{
    int le_choi = 0;
    char nom[50];
    int index;

    do
    {
        printf(YELLOW "\n\n\n");
        printf("                          |*************************************************|   \n");
        printf("                          |                   Menu                          |   \n");
        printf("                          |                                                 |   \n");
        printf("                          |*************************************************|   \n");
        printf("                          |                                                 |   \n");
        printf(GREEN "                          |       1. Ajouter une contact                    |   \n" RESET);
        printf(YELLOW "                          |       2. Afficher tous les contacts             |   \n" RESET);
        printf(BLUE "                          |       3. Rechercher un contact par son nom      |   \n" RESET);
        printf(CYAN "                          |       4. Modifier un contact                    |   \n" RESET);
        printf(RED "                          |       5. Supprimer un contact .                 |   \n" RESET);
        printf("                          |       6. Quitter                                |   \n");
        printf("                          |                                                 |   \n");
        printf("                          |*************************************************|   \n\n\n");
        printf("Quel est votre choix ? : ");
        scanf("%d", &le_choi);

        switch (le_choi)
        {
        case 1:
            ajouter();
            break;
        case 2:
            afficher_tous_les_contacts();
            break;
        case 3:
            printf("entre le nom de contacte ; ");
            scanf("%s", nom);

            system("cls");
            index = Rechercher(nom);

            if (index >= 0)
            {
                afficher_le_contact(index);
            }
            else
            {
                printf("ce nom n'est pas correct ");
            }
            getchar();
            printf("\nAppuyez sur Entrer pour continuer...");
            getchar();
            system("cls");
            break;
        case 4:
            printf("entre le nom de contacte ; ");
            scanf("%s", nom);
            index = Rechercher(nom);
            if (index >= 0)
            {
                Modifier(index);
            }
            else
            {
                printf("ce nom n'est pas correct");
            }
            break;
        case 5:
            printf("entre le nom de contacte ; ");
            scanf("%s", nom);
            system("cls");
            index = Rechercher(nom);
            if (index >= 0)
            {
                afficher_le_contact(index);
                char conf;
                printf(RED " vous supprimez le contact (y/n) ; " RESET);
                scanf(" %c", &conf);
                if (conf == 'n' || conf == 'N')
                {
                    system("cls");
                    break;
                }
                else if (conf == 'y' || conf == 'Y')
                {
                    Supprimer(index);
                    printf(GREEN "\n Contact supprimer avec succes !\n" RESET);
                }
            }
            else
            {
                printf("ce nom n'est pas correct");
            }
            getchar();
            printf("\nAppuyez sur Entrer pour continuer...");
            getchar();
            system("cls");
            break;

        default:
            break;
        }

    } while (le_choi != 6);
}

int valideEmail(char email[50])
{
    int countur1 = 0;
    int countur2 = 0;
    for (int i = 0; i < strlen(email); i++)
    {

        if (email[i] == '@')
        {
            countur1++;
            for (int j = i; j < strlen(email); j++)
            {
                if (email[j] == '.')
                {
                    countur2++;
                }
            }
        }
    }

    return countur1 == 1 && countur2 == 1 && !(email[0] == '@');
}

int validePhonNmper(char nPhone[50])
{
    if (strlen(nPhone) != 10)
    {
        return 0;
    }
    if (nPhone[0] != '0')
    {
        return 0;
    }
    if (nPhone[1] != '6' && nPhone[1] != '7')
    {
        return 0;
    }
    for (int i = 0; i < 10; i++)
    {
        if (nPhone[i] < '0' || nPhone[i] > '9')
        {
            return 0;
        }
    }
    return 1;
}

void ajouter()
{
    system("cls");
    printf(GREEN "                          +*************************************************+   \n");
    printf("                          |                   add contact                   |   \n");
    printf("                          |                                                 |   \n");
    printf("                          |**************************************************   \n");
    printf("                                  - Nom du contact : " RESET);
    scanf("%s", contacts[conteur].nom);
    do
    {
        printf(GREEN "                          |                                                 |   \n");
        printf("                                  - Numero de telephone : " RESET);
        scanf("%s", contacts[conteur].numero_de_telephone);
        if (!validePhonNmper(contacts[conteur].numero_de_telephone))
        {
            printf(GREEN "                          |");
            printf(RED "     le numéro de téléphone n'est pas correct " RESET);
            printf(GREEN "            |   \n");
        }
    } while (!validePhonNmper(contacts[conteur].numero_de_telephone));
    int check;
    do
    {
        printf(GREEN "                          |                                                 |   \n");
        printf("                                  - Adresse e-mail : " RESET);
        scanf("%s", contacts[conteur].adresse_e_mail);

        check = valideEmail(contacts[conteur].adresse_e_mail);
        if (!check)
        {
            printf(GREEN "                          |");
            printf(RED "    l'adresse e-mail n'est pas correcte " RESET);
            printf(GREEN "            |   \n");
        }

    } while (!check);
    printf(GREEN "                          +*************************************************+   \n" RESET);
    conteur++;
    printf(GREEN "\n Contact ajoute avec succes !\n" RESET);
    getchar();
    printf("\nAppuyez sur Entrer pour continuer...");
    getchar();
    system("cls");
}

void Modifier(int index_contact)
{
    system("cls");
    int le_choi = 0;
    do
    {
        afficher_le_contact(index_contact);

        printf("\n\n\n");
        printf(CYAN "                          |*************************************************|   \n");
        printf("                          |                   Modifier                      |   \n");
        printf("                          |                                                 |   \n");
        printf("                          |**************************************************   \n");
        printf("                          |                                                 |   \n");
        printf("                          |       1. modifier le nom                        |   \n");
        printf("                          |       2. modifier le adresse e-mail             |   \n");
        printf("                          |       3. modifier le numero de telephone        |   \n");
        printf("                          |       4. Quite                                  |   \n");
        printf("                          |                                                 |   \n");
        printf("                          |*************************************************|  \n\n\n" RESET);
        printf("Quel est votre choix ? : ");
        scanf("%d", &le_choi);

        switch (le_choi)
        {
        case 1:
            printf("entre nouvel nom ; ");
            scanf("%s", contacts[index_contact].nom);
            printf(GREEN "\n Contact modifier avec succes !\n" RESET);
            break;
        case 2:

            do
            {
                printf("entre nouvel numero de telephone ; ");
                scanf("%s", contacts[index_contact].numero_de_telephone);
                if (!validePhonNmper(contacts[index_contact].numero_de_telephone))
                {
                    printf(RED "le numéro de téléphone n'est pas correct \n" RESET);
                }
            } while (!validePhonNmper(contacts[index_contact].numero_de_telephone));

            printf(GREEN "\n Contact modifier avec succes !\n" RESET);
            break;
        case 3:

            int check;
            do
            {
                printf("entre nouvel Adresse e_mail ; ");
                scanf("%s", contacts[index_contact].adresse_e_mail);

                check = valideEmail(contacts[index_contact].adresse_e_mail);
                if (!check)
                {
                    printf(RED " l'adresse e-mail n'est pas correcte \n" RESET);
                }

            } while (!check);
            printf(GREEN "\n Contact modifier avec succes !\n" RESET);
            break;
        case 4:
            printf(BLUE " Retour au menu...\n" RESET);
            break;

        default:
            break;
        }
        getchar();
        printf("\nAppuyez sur Entrer pour continuer...");
        getchar();
        system("cls");

    } while (le_choi != 4);
}

void afficher_tous_les_contacts()
{
    system("cls");
    if (conteur > 0)
    {
        printf(YELLOW "                                               +************************************************************************************+\n");
        printf("                                              ||                        ||                                ||                        ||\n");
        printf("                                              || %-*s || %-*s || %-*s ||\n", 22, "nom", 30, "numero de telephone", 22, "adress e-mail");
        printf("                                              ||                        ||                                ||                        ||\n");
        printf("                    +************************+**************************************************************************************+\n");

        for (int i = 0; i < conteur; i++)
        {
            printf("                    ||                        ||                        ||                                ||                        ||\n");
            printf("                    || contact %-*d || %-*s || %-*s || %-*s ||\n", 14, i, 22, contacts[i].nom, 30, contacts[i].numero_de_telephone, 22, contacts[i].adresse_e_mail);
            printf("                    ||                        ||                        ||                                ||                        ||\n");
        }
        printf("                    +************************+**************************************************************************************+\n" RESET);
    }
    else
    {
        printf("le contacts vide ;");
    }
    getchar();
    printf("\nAppuyez sur Entrer pour continuer...");
    getchar();
    system("cls");
}

int Supprimer(int index_contact)
{
    for (int i = index_contact; i < conteur - 1; i++)
    {
        contacts[i] = contacts[i + 1];
    }
    conteur--;
}

int Rechercher(char nom_contact[50])
{
    for (int i = 0; i < conteur; i++)
    {
        if (strcmp(contacts[i].nom, nom_contact) == 0)
        {
            return i;
        }
    }

    return -1;
}

void afficher_le_contact(int i)
{

    printf(YELLOW "                                               +************************************************************************************+\n");
    printf("                                              ||                        ||                                ||                        ||\n");
    printf("                                              || %-*s || %-*s || %-*s ||\n", 22, "nom", 30, "numero de telephone", 22, "adress e-mail");
    printf("                                              ||                        ||                                ||                        ||\n");
    printf("                      +**************************+**********************************************************************************+\n");
    printf("                    ||                        ||                        ||                                ||                        ||\n");
    printf("                    || contact %-*d || %-*s || %-*s || %-*s ||\n", 14, i, 22, contacts[i].nom, 30, contacts[i].numero_de_telephone, 22, contacts[i].adresse_e_mail);
    printf("                    ||                        ||                        ||                                ||                        ||\n");
    printf("                      +**************************+**********************************************************************************+\n");
}
