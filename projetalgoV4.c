#include <stdio.h>
#include <string.h>
#include "voiture.h"


char marque_voiture[10][20]={"RENAULT","PEUGEOT","PORSCHE","TOYOTA","FORD","OPEL","MERCEDES","AUDI","VOLKSWAGEN"};
char modele_voiture[10][20]={"Espace","206","Cayenne","Yaris","Fiesta","Corsa","E-Class","A3","Golf"};
int places_voiture[10]={8,4,4,8,4,4,5,4,5}; //détail pas utilisé
int prix_par_jour[10]={100,150,300,150,200,200,200,200,200};
int nbjourparmois[12]={31,28,31,30,31,30,31,31,30,31,30,31};
int z=0,u=0;


void location_voiture()
{
    
    int i,f;
    int t,jour1=0,jour2=0,jour3=0;
    char ch;
    int j,x;
    printf("\n\t\t\t     BIENVENUE CHER CLIENT!!! \n");
    display();                //affichage du tableau
    printf("\n\t\t        ENTREZ LA MARQUE DE VOTRE CHOIX: ");
    scanf("%s",c.voiture_louee);  //on écrit dans la variable c la marque de la voiture
    printf("\n\t\tENTREZ LA DATE VOULUE POUR LA LOCATION (jj mm aaaa): ");
    scanf("%d%d%d",&c.dr,&c.mr,&c.yr); //on entre le jour,le mois et l'année dans les composantes dr,mr,yr de la structure car
    printf("\n\t\tENTREZ LA DATE DE FIN DE LOCATION (jj mm aaaa): ");
    scanf("%d%d%d",&c.dret,&c.mret,&c.yret);// pareil mais pour les composantes dret,mret,yret de la structure car
    printf("\n\t\t      VERIFIONS SI LA VOITURE EST DISPONIBLE\n");
    //FILE *ptr; //on stock l'information relative au flux ouvert en read qui mène au fichier "location_voiture.txt"
    //ptr=fopen("location_voiture.txt","r"); 
    //fread(ca,sizeof(ca),1,ptr); //On lit 1 block d'octet de la taille du buffer à partir du flux "ptr" qui seront stocké dans le buffer "ca"
       for(i=0;i<10;i++)
       {
        if(strcmp(ca[i].voiture_louee,c.voiture_louee)==0) //on prend le nom de la voiture entré par l'utilisateur(ca[i].voiture_louee) et on le compare au nom inscrit dans la base de données, si les deux chaines de caractères sont egales, strcmp renvoi une valeur nulle.
        {
           
            for(t=0;t<=ca[i].mr;t++)
                jour1+=nbjourparmois[t];  // Verification de la disponibilité de la voiture
            for(t=0;t<=ca[i].mret;t++)       //
                jour2+=nbjourparmois[t];  //
            for(t=0;t<=c.mr;t++)             //
                jour3+=nbjourparmois[t];  //
            jour1+=ca[i].dr;			//
            jour2+=ca[i].dret;		//
            jour3+=c.dr;			//
            if((jour3-jour1)*(jour2-jour3)>=0)//
                f=1;
            else
            f=0;
               if(f==1)
               {
                 printf("\n\t\tLa voiture n'est pas disponible, voulez vous en chercher une autre ?\n\t\tSi oui, entrez O, sinon entrez N N\n");
                 getchar();
                 scanf("%c",&ch);
                 //fclose(ptr);
                 if(ch=='o'||ch=='O')
                    location_voiture();
                 else
                 {
                     printf("\n\t\t\tMERCI DE VOTRE VISITE ! \n\n\n");
                     //fclose(ptr);
                     break;
                 }
               }
        }
        else if(strcmp(ca[i].voiture_louee,c.voiture_louee)!=0 ||f==0)
        {
            printf("\n\t\t\tVOTRE VOITURE EST DISPONIBLE !! \n");
            FILE *fp;
            fp=fopen("location_voiture","a");
            strcpy(ca[u].voiture_louee,c.voiture_louee);
            ca[u].dr=c.dr;			                                //reservation des dates
            ca[u].mr=c.mr;
            ca[u].yr=c.yr;
            ca[u].dret=c.dret;
            ca[u].mret=c.mret;
            ca[u].yret=c.yret;
            //u++;
            fwrite(&ca,sizeof(ca),1,fp);
            fclose(fp);
            printf("\n\t\t\tENTREZ VOTRE NOM: ");
            scanf("%s",c.nom_client);
            printf("\n\t\t\tENTREZ VOTRE PRENOM: ");
            scanf("%s",c.prenom_client);
            printf("\n\t\t\tENTREZ VOTRE MOT DE PASSE: ");
            scanf("%s",c.id_client);
            c.n=date(c.yr,c.yret,c.mr,c.mret,c.dr,c.dret);
            for(j=0;j<10;j++)
            {
                x=strcmp(c.voiture_louee,marque_voiture[j]);
                if(x==0)
                    break;
            }
            c.rent=c.n*prix_par_jour[j];
            printf("\nATTENTION. Tout dommage materiel sur la voiture sera de votre responsabilite. La voiture doit etre retournee dans le meme etat que l'etat initial.\n");
            printf("\n\t\t=================================\t\n");
            printf("\n\t\t\tDetails:\n");
            printf("\n\tNOM:%s\n\tMDP:%s\n\tVOITURE:%s\n\tNOMBRE DE JOURS:%d\n\tLOCATION:%d\n",c.nom_client,c.id_client,c.voiture_louee,c.n,c.rent);
            printf("\n\t\t=================================\t\n");
            //fclose(ptr);
            strcpy(cr[z].nom_client,c.nom_client);
            strcpy(cr[z].id_client,c.id_client);
            strcpy(cr[z].voiture_louee,c.voiture_louee);
            strcpy(cr[z].prenom_client,c.prenom_client);
            cr[z].n=c.n;
            cr[z].rent=c.rent;
            //z++;
            FILE *fptr;
            fptr=fopen("location_voiture.txt","a+");
            fwrite(&cr,sizeof(cr),1,fptr);
            fclose(fptr);
            break;
        }
    }
}
int date(int y1,int y2,int m1,int m2,int d1,int d2)
{
    int i,jour1=0,jour2=0,jour3=0 ;
        for(i=0;i<=m1;i++)
            jour1+=nbjourparmois[i];
        for(i=0;i<=m2;i++)
            jour2+=nbjourparmois[i];
        jour1+=d1;
        jour2+=d2;
        return(jour2-jour1);
}

void retour_voiture() 
{
    //FILE *fptr,*nptr;
    char id[13];
    int dd,mm,yy,d,m,y,flag=0,i,j;
    printf("\n\t\t\t    Bienvenue cher client ! \n");
    printf("\n\t\t\t     Entrez votre mot de passe :\n");
    scanf("%s",id);
    //fptr=fopen("location_voiture","r");
    //fread(cr,sizeof(struct car),1,fptr);
    for(i=0;i<10;i++)
    {
        if(strcmp(cr[i].id_client,id)==0)
        {
            flag=1;
            printf("\n\t\t\tBONJOUR M/MME %s\n",cr[i].nom_client);
            printf("Pour confirmer, entrez la date de debut et de fin de votre location sous le format (jj mm aaaa).\n");
            scanf("%d%d%d",&dd,&mm,&yy);
            scanf("%d%d%d",&d,&m,&y);
            cr[i].jour=date(yy,y,mm,m,dd,d);
            if(cr[i].jour>cr[i].n)
            {
                    cr[i].rent+=50*(cr[i].jour-cr[i].n);
            }
            printf("\n\t\t\tFACTURE TOTALE :%d \n",cr[i].rent);
            printf("\n\n");
            printf("\nA BIENTOT! ");
            break;
        }
    }
    if(flag==0)
           {
             printf("\n\t\t\tClient introuvable\n");
            //fclose(fptr);
           }
        else
        {
            //nptr=fopen("location_voiture","w+");
            //fread(cr,sizeof(cr),1,nptr);
            for(j=0;j<10;j++)
            {
                if(j==i)
                    memset(&cr[j].voiture_louee[0],0,sizeof(cr[j].voiture_louee[0]));
            }
            //fclose(fptr);
            //remove("location_voiture");
            //rename("Car_temp","location_voiture");
            //fclose(nptr);
        }
}
void display()
{
    printf("\t\t________________________________________________ \n");
    printf("\t\t|                |          |                  | \n");
    printf("\t\t|      marque    |  modèle  |     prix/jour    | \n");
    printf("\t\t|________________|__________|__________________| \n");
    printf("\t\t|     RENAULT    |  Espace  |       100        | \n");
    printf("\t\t|________________|__________|__________________| \n");
    printf("\t\t|     PEUGEOT    |   206    |       150        | \n");
    printf("\t\t|________________|__________|__________________| \n");
    printf("\t\t|     PORSCHE    |  Cayenne |       300        | \n");
    printf("\t\t|________________|__________|__________________| \n");
    printf("\t\t|     TOYOTA     |   Yaris  |       150        | \n");
    printf("\t\t|________________|__________|__________________| \n");
    printf("\t\t|      FORD      |  Fiesta  |       200        | \n");
    printf("\t\t|________________|__________|__________________| \n");
    printf("\t\t|      OPEL      |  Corsa   |       200        | \n");
    printf("\t\t|________________|__________|__________________| \n");
    printf("\t\t|    MERCEDES    |  E-Class |       200        | \n");
    printf("\t\t|________________|__________|__________________| \n");
    printf("\t\t|      AUDI      |    A3    |       200        | \n");
    printf("\t\t|________________|__________|__________________| \n");
    printf("\t\t|   VOLKSWAGEN   |   Golf   |       200        | \n");
    printf("\t\t|________________|__________|__________________| \n");
}


void client() 
{
    int i,flag=0;
    char id[13];
    
    printf("Veuillez entrer votre mdp:");
    scanf("%s",id);
    for(i=0;i<=10;i++)
    {
        if (strcmp(cr[i].id_client,id)==0)
            {
                flag=1;
    		 printf("\n\t\t_______________________________________________________\n");
    		 printf("\t\t|      nom       |      prenom       |     voiture      | \n");
    		 printf("\t\t|________________|___________________|__________________| \n");
    		 printf("\t\t|%s             %s                %s                \n",cr[i].nom_client,cr[i].prenom_client,cr[i].voiture_louee);
    		 printf("\t\t|________________|___________________|__________________| \n");
    	 }
    }
    if (flag==0)
    {
    	printf("Mot de passe inconnu\n");
    }
}



