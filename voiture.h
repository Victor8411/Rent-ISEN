#include <stdio.h>
#include <string.h>

struct car 
{
    char prenom_client[50];
    char nom_client[50];
    char id_client[13];
    char voiture_louee[20];
    int n,rent,jour;
    int dr,mr,yr,dret,mret,yret;
};

struct car c,ca[10],cr[10],cn={0};


