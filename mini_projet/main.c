#include <windows.h>
#include <tchar.h>
#include<stdio.h>
#include"magasin.h"
#include<stdlib.h>
#include<string.h>
#include <time.h>

int main()
{
    time_t secondes ;
    struct tm instant;
    article tab[20];
    char ch[90] ;
    int n,i,var,k=0;
    char code_recherche[5];
    n=0;
    int choix,cd;
    int tableau[50];
    printf("Veuillez entrer le nom de votre magasin \n") ;
    scanf("%s",ch) ;
    SetConsoleTitle(_T(ch));
    FILE *f;
    f=fopen("Miniprojet.txt","rt");
    if (f==NULL)
       {

       SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_RED) ;
        printf("Le fichier n'existe pas\n");}
    else
    {
        while(!feof(f))
        {
            fscanf(f,"%s %s %i %s %f %f %f %3s\n",tab[n].Code,tab[n].Type,&tab[n].Epoque,tab[n].Description,&tab[n].Dimension.hauteur,&tab[n].Dimension.Largeur,&tab[n].Prix,tab[n].Vendu);
            Decoding(tab[n].Description);
            n++;
        }
    }
    fclose(f);
    while (1)
    {
        time(&secondes);
        instant=*localtime(&secondes);
        char variable[3];
        SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_GREEN) ;
        printf("\n~~~ %d/%d/%d  |  %d:%d:%d ~~~\n",instant.tm_mday,instant.tm_mon+1,instant.tm_year+1900,instant.tm_hour, instant.tm_min,instant.tm_sec);
        SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_BLUE|FOREGROUND_RED|BACKGROUND_BLUE|BACKGROUND_GREEN|BACKGROUND_RED|BACKGROUND_INTENSITY) ;
        printf("************MENU*************\n");
        printf("|\t1 : Saisir\t    |\n|\t2 : Afficher\t    |\n|\t3 : Recherche\t    |\n|\t4 : Modifier\t    |\n|\t5 : Supprimer\t    |\n|\t6 : Chiffre_Affaire |\n|\t0 : Quitter\t    |\n");
        printf("*****************************\n");
        SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_BLUE|BACKGROUND_RED|BACKGROUND_BLUE|BACKGROUND_GREEN|BACKGROUND_INTENSITY) ;
        do
        {scanf("%s",variable);
        choix=Controle_Integer(variable);}while(Controle_Integer(variable)==-1);
        switch(choix)
            {
                case 0 :
                    {
                    f=fopen("Miniprojet.txt","wt");
                    //printf("N=%d\n",N);
                    for (i=0;i<n;i++)
                    {
                        Encoding(tab[i].Description);
                        fprintf(f,"%s %s %i %s %0.2f %0.2f %0.2f %3s\n",tab[i].Code,tab[i].Type,tab[i].Epoque,tab[i].Description,tab[i].Dimension.hauteur,tab[i].Dimension.Largeur,tab[i].Prix,tab[i].Vendu);
                    }
                    fclose(f);
                    exit(0);
                    }
                case 1 :
                    {

                        char cds[2];
                        do
                        {
                            tab[n]=fiche(tab,n);
                            n++;
                            do
                            {
                            printf("Voulez-vous ajouter un autre article?\ntaper 1 pour OUI et 0 pour NON\n");
                            SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_BLUE|BACKGROUND_RED|BACKGROUND_BLUE|BACKGROUND_GREEN|BACKGROUND_INTENSITY);
                            scanf("%s",cds);
                            cd=Controle_Integer(cds);}while((Controle_Integer(cds)==-1)||((cd!=0)&&(cd!=1)));
                        }while((n<20)&&(cd==1));
                        break;
                    }
                case 2 :
                {
                        char vero[2];
                        while (1)
                        {
                        SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_BLUE|FOREGROUND_RED|FOREGROUND_INTENSITY|BACKGROUND_RED|BACKGROUND_BLUE|BACKGROUND_GREEN|BACKGROUND_INTENSITY) ;
                        printf("1 : afficher les donnees de tous les articles\n2 : afficher les articles recherche\n3 : afficher les donnees d'un seul article\n0 : retourner\n");
                        SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_BLUE|BACKGROUND_RED|BACKGROUND_BLUE|BACKGROUND_GREEN|BACKGROUND_INTENSITY);
                        do
                        {scanf("%s",vero);
                        var=Controle_Integer(vero);}while(Controle_Integer(vero)==-1);
                        if (var==1)
                        {
                            for (i=0;i<n;i++)
                                affiche(tab[i]);
                            if (n==0)
                                   {printf("\a") ;
                                  Beep(13, 282) ;
                                 SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_RED|BACKGROUND_BLUE|BACKGROUND_GREEN|BACKGROUND_INTENSITY) ;
                                printf("Il n'y a aucun article\n");}
                        }
                        else if (var==2)
                        {
                            if (k==0)
                                {      printf("\a") ;
                                     Beep(13, 282) ;
                                    SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_RED) ;
                                printf("Erreur , veuillez effectuer la recherche dabord avant dafficher\n");}
                            else
                            {
                                for (i=0;i<k;i++)
                                {
                                    affiche(tab[tableau[i]]);
                                }
                            }
                        }
                        else if (var ==0)
                            break;
                        else
                        {
                            int m;
                            char mchar[2];
                            do
                            {
                                SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_RED|BACKGROUND_BLUE|BACKGROUND_GREEN|BACKGROUND_INTENSITY) ;
                                printf("Entrer Le code de l'article\n");
                                SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_BLUE|BACKGROUND_RED|BACKGROUND_BLUE|BACKGROUND_GREEN|BACKGROUND_INTENSITY) ;
                                scanf("%s",code_recherche);
                                i=Recherche(tab,n,code_recherche);
                                if (i==-1)
                                    {
                                        printf("\a") ;
                                        Beep(13, 282) ;
                                     SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_RED|BACKGROUND_BLUE|BACKGROUND_GREEN|BACKGROUND_INTENSITY) ;
                                    printf("Article introuvable\n");}
                                else
                                    affiche(tab[i]);
                                SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_RED|BACKGROUND_BLUE|BACKGROUND_GREEN|BACKGROUND_INTENSITY) ;
                                do
                                {printf("Voulez-vous afficher un autre article?\nEntrer 1 pour Oui Et 0 pour Non\n");
                                SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_BLUE|BACKGROUND_RED|BACKGROUND_BLUE|BACKGROUND_GREEN|BACKGROUND_INTENSITY) ;
                                scanf("%s",mchar);
                                m=Controle_Integer(mchar);}while((Controle_Integer(mchar)==-1)||((m!=0)&&(m!=1)));
                            }while(m==1);
                        }
                        }
                        break;
                }
                case 3 :
                    {
                        int sous_choix_recherche,s,j;
                        while (1)
                        {
                            char ch0[2];
                            SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_BLUE|FOREGROUND_RED|BACKGROUND_BLUE|BACKGROUND_GREEN|BACKGROUND_RED|BACKGROUND_INTENSITY) ;
                            printf("1 : Recherche selon le Code\n2 : Recherche selon le Prix\n3 : Recherche selon L'Epoque\n4 : Recherche selon le Type\n5 : Recherche selon l'Etat\n6 : Filtrer\n7 : Annuler la Recherche\n0 : Retourner\n");
                            SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_BLUE|BACKGROUND_RED|BACKGROUND_BLUE|BACKGROUND_GREEN|BACKGROUND_INTENSITY) ;
                            do
                            {scanf("%s",ch0);
                            sous_choix_recherche=Controle_Integer(ch0);}while(Controle_Integer(ch0)==-1);
                            switch (sous_choix_recherche)
                            {
                                case 0 : goto EndWhile;
                                case 1 :
                                {
                                    do
                                    {
                                        SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_RED|BACKGROUND_BLUE|BACKGROUND_GREEN|BACKGROUND_INTENSITY) ;
                                        printf("Entrez le code de l'article que vous cherchez\n");
                                        SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_BLUE|BACKGROUND_RED|BACKGROUND_BLUE|BACKGROUND_GREEN|BACKGROUND_INTENSITY) ;
                                        scanf("%s",code_recherche);
                                        s=Recherche(tab,n,code_recherche) ;
                                        if(s==-1)
                                        {
                                               printf("\a") ;
                                           Beep(13, 282) ;
                                         SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_RED) ;
                                            printf("Article introuvable, verifiez le code entre\n");}
                                    }while(s==-1);
                                    if (Recherche_int(tableau,k,s)==-1)
                                    {
                                         SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_RED|BACKGROUND_BLUE|BACKGROUND_GREEN|BACKGROUND_INTENSITY) ;
                                        printf("L'article recherche est d'indice %i\n",s);
                                        tableau[k]=s;
                                        k++;
                                    }
                                    else
                                    {

                                      SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_RED|BACKGROUND_BLUE|BACKGROUND_GREEN|BACKGROUND_INTENSITY) ;
                                        printf("L'article est deja recherche\n");}
                                    break;
                                }
                                case 2 :
                                    {
                                        float prix_min,prix_max;
                                        char ch1[9],ch2[9];
                                        do
                                        {    SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_RED|BACKGROUND_BLUE|BACKGROUND_GREEN|BACKGROUND_INTENSITY) ;
                                            printf("Entrez le prix minimum des articles que vous voulez trouver\n");
                                            SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_BLUE|BACKGROUND_RED|BACKGROUND_BLUE|BACKGROUND_GREEN|BACKGROUND_INTENSITY) ;
                                           scanf("%s",ch1);
                                         SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_RED|BACKGROUND_BLUE|BACKGROUND_GREEN|BACKGROUND_INTENSITY) ;
                                        printf("Entrez le prix maximum des articles que vous voulez trouver\n");
                                        SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_BLUE|BACKGROUND_RED|BACKGROUND_BLUE|BACKGROUND_GREEN|BACKGROUND_INTENSITY) ;
                                        scanf("%s",ch2);
                                        prix_min=Controle_Float(ch1);
                                        prix_max=Controle_Float(ch2);}while((prix_min>prix_max)||(Controle_Float(ch1)==-1)||(Controle_Float(ch2)==-1));
                                        j=k;
                                        for (i=0;i<n;i++)
                                        {
                                            if ((tab[i].Prix>=prix_min)&&(tab[i].Prix<=prix_max))
                                            {   SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_RED|BACKGROUND_BLUE|BACKGROUND_GREEN|BACKGROUND_INTENSITY) ;
                                                printf("L'article recherche est d'indice %i et de prix %f\n",i,tab[i].Prix);
                                                if (Recherche_int(tableau,k,i)==-1)
                                                    {tableau[j]=i;
                                                    j++;}
                                            }
                                        }
                                        k=j;
                                        if (k==0)
                                              {

                                               printf("\a") ;
                                               Beep(13, 282) ;
                                             SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_RED|BACKGROUND_BLUE|BACKGROUND_GREEN|BACKGROUND_INTENSITY) ;
                                            printf("Article introuvable\n");}
                                        break;
                                    }
                                case 3 :
                                    {
                                        int epoque;
                                        char ch[9];
                                        do
                                        {   SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_RED|BACKGROUND_BLUE|BACKGROUND_GREEN|BACKGROUND_INTENSITY) ;
                                            printf("Entrer l'Annee\n");
                                            SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_BLUE|BACKGROUND_RED|BACKGROUND_BLUE|BACKGROUND_GREEN|BACKGROUND_INTENSITY) ;
                                         scanf("%s",ch);
                                         epoque=Controle_Integer(ch);}while(Controle_Integer(ch)==-1);
                                         i=k;
                                        j=Recherche_Epoque(tab,n,epoque,-1);
                                        while(j!=-1)
                                        {
                                             SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_RED|BACKGROUND_BLUE|BACKGROUND_GREEN|BACKGROUND_INTENSITY) ;
                                            printf("L'article recherche est d'indice %i\n",j);
                                            if (Recherche_int(tableau,k,j)==-1)
                                                {tableau[i]=j;
                                                i++;}
                                            j=Recherche_Epoque(tab,n,epoque,j);
                                        }
                                        k=i;
                                        if (i==0)
                                            {
                                                printf("\a") ;
                                                Beep(13, 282) ;
                                             SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_RED|BACKGROUND_BLUE|BACKGROUND_GREEN|BACKGROUND_INTENSITY) ;
                                            printf("Il n'y a aucun article\n");}
                                        break;
                                    }
                                case 4 :
                                    {
                                        char type[10];
                                         SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_RED|BACKGROUND_BLUE|BACKGROUND_GREEN|BACKGROUND_INTENSITY) ;
                                        printf("Entrer le Type de l'article\n");
                                         SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_BLUE|BACKGROUND_RED|BACKGROUND_BLUE|BACKGROUND_GREEN|BACKGROUND_INTENSITY) ;
                                        scanf("%s",type);
                                        j=Recherche_Type(tab,n,type,-1);
                                        i=k;
                                        while(j!=-1)
                                        {    SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_RED|BACKGROUND_BLUE|BACKGROUND_GREEN|BACKGROUND_INTENSITY) ;
                                            printf("L'Article Recherche est d'indice %i\n",j);
                                            if (Recherche_int(tableau,k,j)==-1)
                                                {tableau[i]=j;
                                                i++;}
                                            j=Recherche_Type(tab,n,type,j);
                                        }
                                        k=i;
                                        if (i==0)
                                            {
                                                printf("\a") ;
                                               Beep(13, 282) ;
                                             SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_RED|BACKGROUND_BLUE|BACKGROUND_GREEN|BACKGROUND_INTENSITY) ;
                                            printf("Il n'y a aucun article\n");}
                                        break;
                                    }
                                case 5 :
                                    {
                                         char etat[3];
                                        int a = 9 ;
                                         SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_RED|BACKGROUND_BLUE|BACKGROUND_GREEN|BACKGROUND_INTENSITY) ;
                                        printf("Entrer l etat de l'article : veuillez saisir oui pour vendu non pour non vendu\n") ;
                                         SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_BLUE|BACKGROUND_RED|BACKGROUND_BLUE|BACKGROUND_GREEN|BACKGROUND_INTENSITY) ;

                                        scanf("%s",etat);
                                        if (strcmp(etat,"oui")==0)
                                            a = 1 ;
                                        else if(strcmp(etat,"non")== 0)
                                            a= 0 ;
                                        while((a!=0)&&(a!= 1))
                                        {
                                              printf("\a") ;
                                             Beep(13, 282) ;
                                            SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_RED) ;
                                            printf(" erreur veuillez entrer une reponse valide\n") ;
                                            scanf("%s",etat);
                                            if (strcmp(etat,"oui")==0)
                                              a = 1 ;
                                            else if(strcmp(etat,"non")== 0)
                                             a= 0 ;
                                        }



                                        j=Recherche_etat(tab, n, etat, -1);
                                        i=0;
                                        while(j!=-1)
                                        {    SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_RED|BACKGROUND_BLUE|BACKGROUND_GREEN|BACKGROUND_INTENSITY) ;
                                            printf("L'Article Recherche est d'indice %i\n",j);
                                            tableau[i]=j;
                                            j=Recherche_etat(tab, n,etat,j);
                                            i++;
                                        }
                                        k=i;
                                        if (i==0)
                                            {
                                                 printf("\a") ;
                                                Beep(13, 282) ;
                                             SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_RED|BACKGROUND_BLUE|BACKGROUND_GREEN|BACKGROUND_INTENSITY) ;
                                            printf("Il n'y a aucun article\n");}
                                        break;
                                    }
                                case 6 :
                                    {
                                        if (k==0)
                                           {
                                                printf("\a") ;
                                              Beep(13, 282) ;
                                             SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_RED|BACKGROUND_BLUE|BACKGROUND_GREEN|BACKGROUND_INTENSITY) ;
                                           printf("Il n'y a aucun article recherche\n");
                                            break;}
                                        int l;
                                        char ch3[2];
                                        while(k!=0)
                                        {   SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_BLUE|FOREGROUND_RED|FOREGROUND_INTENSITY|BACKGROUND_RED|BACKGROUND_BLUE|BACKGROUND_GREEN|BACKGROUND_INTENSITY) ;
                                            printf("1 : Filtrer selon Code\n2 : Filtrer selon le Prix\n3 : Filtrer selon l'Epoque\n4 : Filtrer selon le Type\n0 : Retourner\n");
                                            SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_BLUE|BACKGROUND_RED|BACKGROUND_BLUE|BACKGROUND_GREEN|BACKGROUND_INTENSITY) ;
                                            do
                                            {scanf("%s",ch3);
                                            l=Controle_Integer(ch3);}while(Controle_Integer(ch3)==-1);
                                            switch(l)
                                            {
                                                case 0 :
                                                    goto kelma;
                                                case 1 :
                                                    {
                                                        int indice,l;
                                                        char code_filtre[5];
                                                         SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_RED|BACKGROUND_BLUE|BACKGROUND_GREEN|BACKGROUND_INTENSITY) ;
                                                        printf("Entrer le Code de l'article a filtrer\t");
                                                        SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_BLUE|BACKGROUND_RED|BACKGROUND_BLUE|BACKGROUND_GREEN|BACKGROUND_INTENSITY) ;
                                                        scanf("%s",code_filtre);
                                                        l=Recherche(tab,n,code_filtre);
                                                        indice=Recherche_int(tableau,k,l);
                                                        if(l==-1)
                                                            {     printf("\a") ;
                                                                 Beep(13, 282) ;
                                                                SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_RED) ;{}
                                                                printf("Article non recherche, verifiez le code entre\n");
                                                            break;}
                                                        Supprimer_int(tableau,&k,indice);
                                                        break;
                                                    }
                                                case 2 :
                                                    {
                                                        float prix_min,prix_max;
                                                        int i = 0 ;
                                                        char ch1[9],ch2[9];
                                                        do
                                                        {   SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_RED|BACKGROUND_BLUE|BACKGROUND_GREEN|BACKGROUND_INTENSITY) ;
                                                            printf("Entrez le prix minimum des articles que vous voulez trouver\n");
                                                            SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_BLUE|BACKGROUND_RED|BACKGROUND_BLUE|BACKGROUND_GREEN|BACKGROUND_INTENSITY) ;
                                                        scanf("%s",ch1);
                                                         SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_RED|BACKGROUND_BLUE|BACKGROUND_GREEN|BACKGROUND_INTENSITY) ;
                                                        printf("Entrez le prix maximum des articles que vous voulez trouver\n");
                                                        SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_BLUE|BACKGROUND_RED|BACKGROUND_BLUE|BACKGROUND_GREEN|BACKGROUND_INTENSITY) ;
                                                        scanf("%s",ch2);
                                                        prix_min=Controle_Float(ch1);
                                                        prix_max=Controle_Float(ch2);}while((prix_min>prix_max)||(Controle_Float(ch1)==-1)||(Controle_Float(ch2)==-1));
                                                        while(1)
                                                        {
                                                            if ((tab[tableau[i]].Prix<prix_min)||(tab[tableau[i]].Prix>prix_max))
                                                            {
                                                                Supprimer_int(tableau,&k,i);
                                                            }
                                                            else
                                                                i++;
                                                            if (i==k)
                                                                break;
                                                        }
                                                        break;
                                                    }
                                                case 3 :
                                                    {
                                                        int epoque,i=0;
                                                        char ch[9];
                                                        do
                                                        {   SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_RED|BACKGROUND_BLUE|BACKGROUND_GREEN|BACKGROUND_INTENSITY) ;
                                                            printf("Entrer l'Annee\n");
                                                            SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_BLUE|BACKGROUND_RED|BACKGROUND_BLUE|BACKGROUND_GREEN|BACKGROUND_INTENSITY) ;
                                                        scanf("%s",ch);
                                                        epoque=Controle_Integer(ch);}while(Controle_Integer(ch)==-1);
                                                        while(1)
                                                        {
                                                            if (tab[tableau[i]].Epoque!=epoque)
                                                                Supprimer_int(tableau,&k,i);
                                                            else
                                                                i++;
                                                            if (i==k)
                                                                break;
                                                        }
                                                        break;
                                                    }
                                                case 4 :
                                                    {
                                                        int i=0;
                                                        char type[10];
                                                         SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_RED|BACKGROUND_BLUE|BACKGROUND_GREEN|BACKGROUND_INTENSITY) ;
                                                        printf("Entrer le Type de l'article a filtrer\n");
                                                        SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_BLUE|BACKGROUND_RED|BACKGROUND_BLUE|BACKGROUND_GREEN|BACKGROUND_INTENSITY) ;
                                                        scanf("%s",type);
                                                        while(1)
                                                        {
                                                            if (strcmp(tab[tableau[i]].Type,type)!=0)
                                                                Supprimer_int(tableau,&k,i);
                                                            else
                                                                i++;
                                                            if (i==k)
                                                                break;
                                                        }
                                                        break;
                                                    }
                                            }
                                        }
                                        kelma : break;
                                    }
                                case 7 :
                                    {
                                        k=0;
                                            printf("\a") ;
                                            Beep(13, 282) ;
                                         SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_RED|BACKGROUND_BLUE|BACKGROUND_GREEN|BACKGROUND_INTENSITY) ;
                                        printf("Il n'ya aucun article recherche\n");
                                        break;
                                    }
                                default : printf("Entree invalide\n");
                            }
                        }
                        EndWhile : break;
                    }

                case 4 :
                    {
                        int choice,sous_choice;
                        char code[5],spo[2];
                        while (1)
                        {   SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_BLUE|FOREGROUND_RED|FOREGROUND_INTENSITY|BACKGROUND_RED|BACKGROUND_BLUE|BACKGROUND_GREEN|BACKGROUND_INTENSITY) ;
                            printf("1 : Modifier un article\n2 : Modifier les articles recherches\n0 : Retourner\n");
                            SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_BLUE|BACKGROUND_RED|BACKGROUND_BLUE|BACKGROUND_GREEN|BACKGROUND_INTENSITY) ;
                            do
                            {scanf("%s",spo);
                            choice=Controle_Integer(spo);}while(Controle_Integer(spo)==-1);
                            switch(choice)
                            {
                                case(0) :
                                    goto khrouj;
                                case(1) :
                                {
                                    int i;
                                    char bab[2];
                                    SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_RED|BACKGROUND_BLUE|BACKGROUND_GREEN|BACKGROUND_INTENSITY) ;
                                    printf("Saisir le Code de l'article a modifier\n");
                                    SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_BLUE|BACKGROUND_RED|BACKGROUND_BLUE|BACKGROUND_GREEN|BACKGROUND_INTENSITY) ;
                                    scanf("%s",code);
                                    i=Recherche(tab,n,code);
                                    if (i==-1)
                                       {
                                           printf("\a") ;
                                         Beep(13, 282) ;
                                        SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_RED|BACKGROUND_BLUE|BACKGROUND_GREEN|BACKGROUND_INTENSITY) ;
                                        printf("Article introuvable\n");}
                                    while(i!=-1)
                                    {
                                    SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_BLUE|FOREGROUND_RED|FOREGROUND_INTENSITY|BACKGROUND_RED|BACKGROUND_BLUE|BACKGROUND_GREEN|BACKGROUND_INTENSITY) ;
                                    printf("1 : Modifier le Type\n2 : Modifier l'Epoque\n3 : Modifier la Description\n4 : Modifier la Hauteur\n5 : Modifier la largeur\n6 : Modifier le Prix\n7 : L'article est vendu\n0 : Retouner\n");
                                    SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_BLUE|BACKGROUND_RED|BACKGROUND_BLUE|BACKGROUND_GREEN|BACKGROUND_INTENSITY) ;
                                    do
                                    {scanf("%s",bab);
                                    sous_choice=Controle_Integer(bab);}while(Controle_Integer(bab)==-1);
                                        switch(sous_choice)
                                        {
                                            case(0) :
                                                goto cbon;
                                            case(1) :
                                                {char type[10];
                                                 SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_RED|BACKGROUND_BLUE|BACKGROUND_GREEN|BACKGROUND_INTENSITY) ;
                                                printf("Entrer le nouveau Type\n");
                                                SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_BLUE|BACKGROUND_RED|BACKGROUND_BLUE|BACKGROUND_GREEN|BACKGROUND_INTENSITY) ;
                                                scanf("%s",type);
                                                strcpy(tab[i].Type,type);
                                                break;}
                                            case(2) :
                                                {int epoque1;
                                                char ch[9];
                                                do
                                                {    SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_RED|BACKGROUND_BLUE|BACKGROUND_GREEN|BACKGROUND_INTENSITY) ;
                                                    printf("Entrer l'Annee\n");
                                                    SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_BLUE|BACKGROUND_RED|BACKGROUND_BLUE|BACKGROUND_GREEN|BACKGROUND_INTENSITY) ;
                                                scanf("%s",ch);
                                                epoque1=Controle_Integer(ch);}while(Controle_Integer(ch)==-1);
                                                tab[i].Epoque = epoque1;
                                                break ;}
                                            case(3) :
                                                {char description[100];
                                                 SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_RED|BACKGROUND_BLUE|BACKGROUND_GREEN|BACKGROUND_INTENSITY) ;
                                                printf("Entrer la nouvelle Description\n");
                                                fflush(stdin);
                                                SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_BLUE|BACKGROUND_RED|BACKGROUND_BLUE|BACKGROUND_GREEN|BACKGROUND_INTENSITY) ;
                                                gets(description);
                                                strcpy(tab[i].Description,description);
                                                break;}
                                            case(4) :
                                                {float hauteur;
                                                char ch[9];
                                                do
                                                {    SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_RED|BACKGROUND_BLUE|BACKGROUND_GREEN|BACKGROUND_INTENSITY) ;
                                                    printf("Entrer la nouvelle Hauteur\n");
                                                    SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_BLUE|BACKGROUND_RED|BACKGROUND_BLUE|BACKGROUND_GREEN|BACKGROUND_INTENSITY) ;
                                                scanf("%s",ch);
                                                hauteur=Controle_Float(ch);}while((Controle_Float(ch)==-1)||(hauteur==0));
                                                tab[i].Dimension.hauteur=hauteur;
                                                break;}
                                            case(5) :
                                                {float largeur;
                                                char ch[9];
                                                do
                                                {   SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_RED|BACKGROUND_BLUE|BACKGROUND_GREEN|BACKGROUND_INTENSITY) ;
                                                    printf("Entrer la nouvelle Largeur\n");
                                                    SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_BLUE|BACKGROUND_RED|BACKGROUND_BLUE|BACKGROUND_GREEN|BACKGROUND_INTENSITY) ;
                                                scanf("%s",ch);
                                                largeur=Controle_Float(ch);}while((Controle_Float(ch)==-1)||(largeur==0));
                                                tab[i].Dimension.Largeur=largeur;
                                                break;}
                                            case(6) :
                                                {
                                                float prix;
                                                char ch[9];
                                                do
                                                {    SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_RED|BACKGROUND_BLUE|BACKGROUND_GREEN|BACKGROUND_INTENSITY) ;
                                                    printf("Entrer le nouveau Prix\n");
                                                    SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_BLUE|BACKGROUND_RED|BACKGROUND_BLUE|BACKGROUND_GREEN|BACKGROUND_INTENSITY) ;
                                                scanf("%s",ch);
                                                prix=Controle_Float(ch);}while((prix==0)||(Controle_Float(ch)==-1));
                                                tab[i].Prix=prix;
                                                break;
                                                }
                                            case(7) :
                                                {if (strcmp(tab[i].Vendu,"oui")==0)
                                                     {SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_RED|BACKGROUND_BLUE|BACKGROUND_GREEN|BACKGROUND_INTENSITY) ;
                                                    printf("Article deja vendu\n");}
                                                else
                                                    strcpy(tab[i].Vendu,"oui");
                                                break;}
                                            default :{SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_RED) ;
                                                 printf("Entree Invalide\n");}
                                        }
                                    }
                                    cbon : break;
                                }
                                case(2) :
                                {
                                    int cd,i;
                                    char cdo[2];
                                    while(1)
                                    {   SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_BLUE|FOREGROUND_RED|FOREGROUND_INTENSITY|BACKGROUND_RED|BACKGROUND_BLUE|BACKGROUND_GREEN|BACKGROUND_INTENSITY) ;
                                        printf("1 : Modifier le Prix\n2 : Vendre les articles\n0 : Retourner\n");
                                        SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_BLUE|BACKGROUND_RED|BACKGROUND_BLUE|BACKGROUND_GREEN|BACKGROUND_INTENSITY) ;
                                        do
                                        {scanf("%s",cdo);
                                        cd=Controle_Integer(cdo);}while(Controle_Integer(cdo)==-1);
                                        switch(cd)
                                        {
                                        case(0) :
                                            goto khanga;
                                        case(1) :
                                            {float prix;
                                            char ch[9];
                                            do
                                            {    SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_RED|BACKGROUND_BLUE|BACKGROUND_GREEN|BACKGROUND_INTENSITY) ;
                                                printf("Entrer le nouveau prix\n");
                                                SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_BLUE|BACKGROUND_RED|BACKGROUND_BLUE|BACKGROUND_GREEN|BACKGROUND_INTENSITY) ;
                                            scanf("%s",ch);
                                            prix=Controle_Float(ch);}while((Controle_Float(ch)==-1)||(prix==0));
                                            for (i=0;i<k;i++)
                                                tab[tableau[i]].Prix=prix;
                                            break;}
                                        case(2) :
                                            {for (i=0;i<k;i++)
                                                strcpy(tab[tableau[i]].Vendu,"oui");
                                            break;
                                            }
                                        default :{   printf("\a") ;
                                                  Beep(13, 282) ;
                                             SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_RED) ;
                                             printf("Entree Invalide\n");}
                                        }
                                    }
                                khanga : break;
                               }
                            default : {   printf("\a") ;
                                         Beep(13, 282) ;
                                SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_RED) ;
                                printf("Entree Invalide\n");}
                        }
                    }
                    khrouj : break;
                    }
                case 5 :
                    {
                        char varo[2];
                        while (1)
                        {
                        SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_BLUE|FOREGROUND_RED|BACKGROUND_BLUE|BACKGROUND_GREEN|BACKGROUND_RED|BACKGROUND_INTENSITY) ;
                        printf("1 : Supprimer tous les articles\n2 : Supprimer les articles recherche\n3 : Supprimer un seul article\n0 : retourner\n");
                        do
                        {scanf("%s",varo);
                        var=Controle_Integer(varo);}while(Controle_Integer(varo)==-1);
                        switch(var)
                        {
                            case(1) :
                            {
                                while(n!=0)
                                    Supprimer(tab,&n,0);
                                k=0;
                                    printf("\a") ;
                                   Beep(13, 282) ;
                                SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_RED|BACKGROUND_BLUE|BACKGROUND_GREEN|BACKGROUND_INTENSITY);
                                printf("Stock Vide\n");
                                break;
                            }
                            case(2) :
                            {
                                if (k==0)
                                    {
                                        printf("\a") ;
                                       Beep(13, 282) ;
                                     SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_RED|BACKGROUND_BLUE|BACKGROUND_GREEN|BACKGROUND_INTENSITY) ;
                                    printf("Il n'y a aucun article\n");}
                                else
                                {
                                    for (i=0;i<k;i++)
                                    {
                                        Supprimer(tab,&n,tableau[i]);
                                    }
                                    k=0;
                                     SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_RED|BACKGROUND_BLUE|BACKGROUND_GREEN|BACKGROUND_INTENSITY) ;
                                    printf("Votre stock est desormais de taille %i\n",n);
                                }
                                break;
                            }
                            case(0) : goto Okhroj;
                            case(3) :
                                {
                                char code[5],vary[2];
                                int j,m,l,indice;
                                do{
                                     SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_RED|BACKGROUND_BLUE|BACKGROUND_GREEN|BACKGROUND_INTENSITY) ;
                                    printf("Entrer le Code de l'article a supprimer\n");
                                    SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_BLUE|BACKGROUND_RED|BACKGROUND_BLUE|BACKGROUND_GREEN|BACKGROUND_INTENSITY) ;
                                    scanf("%s",code);
                                    j=Recherche(tab,n,code);
                                    if (j==-1)
                                         {     printf("\a") ;
                                                Beep(13, 282) ;
                                             SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_RED|BACKGROUND_BLUE|BACKGROUND_GREEN|BACKGROUND_INTENSITY) ;
                                        printf("Article introuvable\n");}
                                    else
                                    {
                                        if (k!=0)
                                            {l=Recherche(tab,n,code);
                                            indice=Recherche_int(tableau,k,l);
                                            Supprimer_int(tableau,&k,indice);}
                                        Supprimer(tab,&n,j);
                                    }
                                    SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_RED|BACKGROUND_BLUE|BACKGROUND_GREEN|BACKGROUND_INTENSITY);                                    do
                                    {printf("Voulez-vous supprimer un autre article?\nEntrer 1 pour Oui Et 0 pour Non\n");
                                    SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_BLUE|BACKGROUND_RED|BACKGROUND_BLUE|BACKGROUND_GREEN|BACKGROUND_INTENSITY) ;
                                    scanf("%s",vary);
                                    m=Controle_Integer(vary);}while((Controle_Integer(vary)==-1)||((m!=0)&&(m!=1)));
                                    }while(m!=0);
                                 SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_RED|BACKGROUND_BLUE|BACKGROUND_GREEN|BACKGROUND_INTENSITY) ;
                                printf("Votre stock est desormais de taille %i\n",n);
                                break;
                                }
                        }
                        }
                        Okhroj : break;
                        default : {   printf("\a") ;
                                 Beep(13, 282) ;
                            SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_RED) ;
                            printf("Entrer invalide\n");
                            break;}
                }
                case 6 :
                {
                     SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_RED|BACKGROUND_BLUE|BACKGROUND_GREEN|BACKGROUND_INTENSITY) ;
                    printf("Le chiffre d'affaire est :\t%0.2fDT\n",Chiffre_Affaire(tab,n));
                    break;
                }
    }
    }
    return 0;
}
