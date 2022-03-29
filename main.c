#include <stdio.h>
#include <string.h>



int main() 
{
    int q,p=0,g,h;
    int u,z;
                     printf("\n\n\n\t\t ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
            printf("\t           ____  _______   _________  _________ _______   __  \n");
            printf("\t          / __ \/ _____/ | / /_  __( )/  _/ ___// ____/ | / /\n");
            printf("\t         / /_/ / __/ /  |/ / / /  |/ / / |__ |/ __/ /  |/ /\n");
            printf("\t        / _, _/ /___/ /|  / / /    _/ / ___/ / /___/ /|  /\n");
            printf("\t       /_/ |_/_____/_/ |_/ /_/    /___//____/_____/_/ |_/\n");
                 printf("\n\t\t ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n \n");
	    printf("\t     ______                           \n");
	    printf("\t    /|_||_|`.__                         \n");
	    printf("\t   (   _    _ _)                             \n");
	    printf("\t===`-(_)--(_)-'                           \n");
    for(g=1;g<=365;g++)
    {
        for(h=1;h<=10;h++)
        {

            printf("\n\t\t\tAVEZ VOUS BESOIN DE NOS SERVICES ?\n\t\t\tENTREZ 1 POUR OUI ET 0 POUR NON\n");
            scanf("%d",&p);
            if(p==1)
            {
                label:
                printf("\a\tBONJOUR!! ETES VOUS ICI POUR LOUER UNE VOITURE OU POUR UN RETOUR ? \n\n\t\t\t 1.VOUS VOULEZ LOUER UNE VOITURE.\n\t\t\t 2.VOUS VOULEZ RETOURNER LA VOITURE.\n\t\t\t 3. AFFICHER VOTRE PROFIL\n\t\t\t");
                scanf("%d",&q);
                switch(q)
                {
                    case 1:{location_voiture();u++;z++;
                    break;}
                    case 2:retour_voiture();
                    break;
                    case 3:client();
                    break;
                    default:{printf("Mauvais choix!! Reessayez.\n");
                    goto label;}
                }
            }
           else return;
        }
        printf("\n\n\nAU REVOIR!!\a\n\n\n");
    }
}

