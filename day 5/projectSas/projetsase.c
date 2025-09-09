#include <stdio.h>
#include <string.h>

typedef struct
{
    int day;
    int month;
    int year;
} date;

typedef struct
{
    int Numero;
    char nom[50];
    char prenom[50];
    date date_naissance;
    char departement[50];
    int note_generale;
} etudiant;

etudiant etudiants[100];
int conteur = 0;

int valideDateNaissance(char dateNessans[50])
{
    if (strlen(dateNessans) != 10)
    {
        return 0;
    }

    if (dateNessans[2] != '/' || dateNessans[5] != '/')
    {
        return 0;
    }
    if (dateNessans[0] < '0' || dateNessans[0] > '9' ||
        dateNessans[1] < '0' || dateNessans[1] > '9' ||
        dateNessans[3] < '0' || dateNessans[3] > '9' ||
        dateNessans[4] < '0' || dateNessans[4] > '9' ||
        dateNessans[6] < '0' || dateNessans[6] > '9' ||
        dateNessans[7] < '0' || dateNessans[7] > '9' ||
        dateNessans[8] < '0' || dateNessans[8] > '9' ||
        dateNessans[9] < '0' || dateNessans[9] > '9')
    {
        return 0;
    }

    return 1;
}

date changeLesDate(char dateN[50])
{
    date d;
    d.day = (dateN[0] - '0') * 10 + (dateN[1] - '0');
    d.month = (dateN[3] - '0') * 10 + (dateN[4] - '0');
    d.year = (dateN[6] - '0') * 1000 + (dateN[7] - '0') * 100 + (dateN[8] - '0') * 10 + (dateN[9] - '0');
    return d;
}

void ajouterEtudiant()
{

    if (etudiants[conteur - 1].Numero == conteur)
    {
        for (int i = 0; i < conteur; i++)
        {
            if (i != etudiants[i].Numero)
            {
                etudiants[conteur].Numero = i;
                break;
            }
        }
    }
    else
    {
        etudiants[conteur].Numero = conteur;
    }

    printf("nom ; ");
    scanf("%s", etudiants[conteur].nom);

    printf("Prenom ; ");
    scanf("%s", etudiants[conteur].prenom);

    printf("departement ; ");
    scanf("%s", etudiants[conteur].departement);

    printf("Note generale ; ");
    scanf("%d", &etudiants[conteur].note_generale);

    char date[50];
    int dateIsValide;
    do
    {
        printf("date de naissance dd/mm/yyyy ; ");
        scanf("%s", date);

        dateIsValide = valideDateNaissance(date);
        if (dateIsValide)
        {
            etudiants[conteur].date_naissance = changeLesDate(date);
        }
        else
        {
            printf("date is note correct ; \n");
        }

    } while (!dateIsValide);
    conteur++;
}

void calculer_la_moyenne(char departomon[50])
{
    int somme = 0;
    for (int i = 0; i < conteur; i++)
    {
        if (strcmp(etudiants[i].departement, departomon) == 0)
        {
        }
    }
}

void modifier(int i)
{
    int le_choi;

    printf("modiea le choi ;");
    scanf("%d", &le_choi);
    do
    {
        switch (le_choi)
        {
        case 1:
            printf("nom ; ");
            scanf("%s", etudiants[i].nom);
            break;
        case 2:
            printf("Prenom ; ");
            scanf("%s", etudiants[i].prenom);
        case 3:
            printf("departement ; ");
            scanf("%s", etudiants[i].departement);
        case 4:
            printf("Note generale ; ");
            scanf("%d", &etudiants[i].note_generale);
        case 5:
            char date[50];
            int dateIsValide;
            do
            {
                printf("date de naissance dd/mm/yyyy ; ");
                scanf("%s", date);

                dateIsValide = valideDateNaissance(date);
                if (dateIsValide)
                {
                    etudiants[i].date_naissance = changeLesDate(date);
                }
                else
                {
                    printf("date is note correct ; \n");
                }

            } while (!dateIsValide);
        default:
            break;
        }
    } while (le_choi == 6);
}

void AffichertoutlesEtudiant()
{
    for (int i = 0; i < conteur; i++)
    {
        printf("le nome %s , le p %s , dep %s , n %d , %d/%d/%d \n", etudiants[i].nom, etudiants[i].prenom, etudiants[i].departement, etudiants[i].note_generale, etudiants[i].date_naissance.day, etudiants[i].date_naissance.month, etudiants[i].date_naissance.year);
    }
}

void afficherEtudianteBy(int index)
{
    printf("le nome %s , le p %s , dep %s , n %d , %d/%d/%d \n", etudiants[index].nom, etudiants[index].prenom, etudiants[index].departement, etudiants[index].note_generale, etudiants[index].date_naissance.day, etudiants[index].date_naissance.month, etudiants[index].date_naissance.year);
}

int RochercheById(int numero)
{
    for (int i = 0; i < conteur; i++)
    {
        if (etudiants[i].Numero = numero)
        {
            return i;
        }
    }
    return -1;
}

void suppreme(int index)
{
    conteur--;
    for (int i = index; i < conteur; i++)
    {
        etudiant e;
        e = etudiants[i];
        etudiants[i] = etudiants[i + 1];
        etudiants[i + 1] = e
    }
}

int main()
{
    printf("hello abderrazak");

    int le_choi = 0;
    do
    {
        printf("le choi ;");
        scanf("%d", &le_choi);
        switch (le_choi)
        {
        case 1:
            ajouterEtudiant();
            break;
        case 2:
            modifier(0);
            break;
        case 3:
            AffichertoutlesEtudiant();
        case 4:
            printf("entree le id du etudiante ; ");
            int id ;
            scanf("%d",&id);
            int index =  RochercheById(id);
            if (index >= 0)
            {
                afficherEtudianteBy(index);
            }else
            {
                printf("this id is note correct ; ")
            }
            
            
        case 5:
            Afficher();
        case 6:
            Afficher();
        case 7:
            Afficher();
        case 8:
            Afficher();
        default:
            break;
        }
    } while (le_choi != 0);

    // printf("le nome ; %s \n le dat n ; %d/%d/%d", etudiants[0].nom , etudiants[0].date_naissance.day , etudiants[0].date_naissance.month ,  etudiants[0].date_naissance.year );
}
