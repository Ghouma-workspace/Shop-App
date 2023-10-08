#include<stdio.h>
#include"magasin.h"
#include<string.h>
#include<stdlib.h>
#include <windows.h>
#include <tchar.h>


article fiche(article T[],int n)
{
    char ch[9];
    article mbl;
    int x;
    SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_RED|BACKGROUND_BLUE|BACKGROUND_GREEN|BACKGROUND_INTENSITY) ;
    printf("Entrer Le Code De l'article\n");
    SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_BLUE|BACKGROUND_RED|BACKGROUND_BLUE|BACKGROUND_GREEN|BACKGROUND_INTENSITY) ;
    scanf("%s",mbl.Code);
    x=strlen(mbl.Code);
    while((x!=4)||(Recherche(T,n,mbl.Code)!=-1))
    {
        if(x!=4)
        {
           printf("\a") ;
          Beep(13, 282) ;
        SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_RED) ;
        printf("Code invalide veuillez reessayer\n");}
        else
        {
               printf("\a") ;
              Beep(13, 282) ;
             SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_RED) ;
             printf("Code existant veuillez reessayer\n");
        }
        SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_BLUE|BACKGROUND_RED|BACKGROUND_BLUE|BACKGROUND_GREEN|BACKGROUND_INTENSITY) ;
        scanf("%s",mbl.Code);
        x=strlen(mbl.Code) ;

    }
    SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_GREEN) ;
    printf("Code recu avec succees\n") ;
    while (1)
    {
        printf("Entrer Le Type Du article\n");
        printf("Le type de l'article doit etre meuble ou decor ou couvert ou tableau ou instrument\n");
        SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_BLUE|BACKGROUND_RED|BACKGROUND_BLUE|BACKGROUND_GREEN|BACKGROUND_INTENSITY) ;
        scanf("%10s",mbl.Type);
        if ((strcmp(mbl.Type,"meuble")==0) || (strcmp(mbl.Type,"decor")==0) || (strcmp(mbl.Type,"couvert")==0) || (strcmp(mbl.Type,"tableau")==0) || (strcmp(mbl.Type,"instrument")==0))
            {   SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_GREEN) ;
                printf("Type recu avec success\n ") ;
                 break;}
       else
       {
              printf("\a") ;
            Beep(13, 282) ;
            SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_RED) ;
            printf("Erreur , veuillez entrer un type valide\n") ;
       }
    }
    do
    {
        printf("Entrer l'annee de la fabrication\n");
        SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_BLUE|BACKGROUND_RED|BACKGROUND_BLUE|BACKGROUND_GREEN|BACKGROUND_INTENSITY) ;
        scanf("%s",ch);
        mbl.Epoque=Controle_Integer(ch);
        if(((mbl.Epoque>2021)||(mbl.Epoque<0))||(Controle_Integer(ch)==-1))
        {
               printf("\a") ;
             Beep(13, 282) ;
            SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_RED) ;
            printf("Erreur, l'epoque ou l'anne de fabrication entree est invalide veuillez resseayer\n") ;
        }
    }while(((mbl.Epoque>2021)&&(mbl.Epoque<0))||(Controle_Integer(ch)==-1));
    SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_GREEN) ;
    printf("L'epoque entre est bien recue\n") ;
    printf("Decrire l'article\n");
    fflush(stdin);
    SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_BLUE|BACKGROUND_RED|BACKGROUND_BLUE|BACKGROUND_GREEN|BACKGROUND_INTENSITY) ;
    gets(mbl.Description);
    SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_GREEN) ;
    printf("Description recu avec succes\n");
    do
    {
        printf("Entrer La Hauteur De l'article\n");
        SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_BLUE|BACKGROUND_RED|BACKGROUND_BLUE|BACKGROUND_GREEN|BACKGROUND_INTENSITY) ;
        scanf("%s",ch);
        mbl.Dimension.hauteur=Controle_Float(ch);
        if((mbl.Dimension.hauteur==0)||(Controle_Float(ch)==-1))
           {
                 printf("\a") ;
               Beep(13, 282) ;
              SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_RED) ;
              printf("erreur , l'hauteur entre est invalide veuillez resseayer\n") ;
           }
    }while((mbl.Dimension.hauteur==0)||(Controle_Float(ch)==-1));
    SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_GREEN) ;
    printf("L'hauteur de votre article est bien recu\n") ;
    do
    {
        printf("Entrer La Largeur De l'article\n");
        SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_BLUE|BACKGROUND_RED|BACKGROUND_BLUE|BACKGROUND_GREEN|BACKGROUND_INTENSITY) ;
        scanf("%s",ch);
        mbl.Dimension.Largeur=Controle_Float(ch);
        if((mbl.Dimension.Largeur==0)||(Controle_Float(ch)==-1))
        {
              printf("\a") ;
             Beep(13, 282) ;
            SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_RED) ;
            printf("Erreur la dimension entree est invalide b=veuillez resseayer\n") ;
        }
    }while((mbl.Dimension.Largeur==0)||(Controle_Float(ch)==-1));
    SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_GREEN) ;
    printf("Largeur bien recu\n") ;
    do
    {
        printf("Donner Le Prix\n");
        SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_BLUE|BACKGROUND_RED|BACKGROUND_BLUE|BACKGROUND_GREEN|BACKGROUND_INTENSITY) ;
        scanf("%s",ch);
        mbl.Prix=Controle_Float(ch);
        if((mbl.Prix==0)||(Controle_Float(ch)==-1))
        {
              printf("\a") ;
             Beep(13, 282) ;
           SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_RED) ;
           printf("Le prix entre est invalide veuillez resseayer\n") ;
        }

    }while((mbl.Prix==0)||(Controle_Float(ch)==-1));
    SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_GREEN) ;
    printf("Le prix de votre article est bien recu\n ") ;
    while (1)
    {
        printf("L'article est-il vendu?\n");
        SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_BLUE|BACKGROUND_RED|BACKGROUND_BLUE|BACKGROUND_GREEN|BACKGROUND_INTENSITY) ;
        scanf("%s",mbl.Vendu);
        if ((strcmp(mbl.Vendu,"oui")!=0)&&(strcmp(mbl.Vendu,"non")!=0))
            {     printf("\a") ;
                 Beep(13, 282) ;
                SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_RED) ;
              printf("Reponse invalide, resseayez\n") ;  }
        else
             {


             SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_GREEN) ;
             printf("Reponse enregistre avec succes\n");
             break ;}
    }
    return mbl;
}


void affiche(article mbl)
{
     SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_RED|BACKGROUND_BLUE|BACKGROUND_GREEN|BACKGROUND_INTENSITY) ;
    printf(" Le Code est %s\n Le Type est %s\n L'Epoque est %i\n La Description est %s\n Les Dismensions Sont (%0.2f,%0.2f)\n Le Prix est %0.2f\n Vendu? %3s\n",mbl.Code,mbl.Type,mbl.Epoque,mbl.Description,mbl.Dimension.hauteur,mbl.Dimension.Largeur,mbl.Prix,mbl.Vendu);
}

void archive(article T[],int n)
{
    int i;
    /*printf("Entrer le nombre des articles\n");
    scanf("%i",&n);
    T=(int *)malloc(sizeof(int)*n);*/
    for (i=0;i<n;i++)
    {
        T[i]=fiche(T,n);
    }
}

int Recherche(article T[],int n,char code[5])
{
    int j;
    for (j=0;j<n;j++)
    {
        if (strcmp(T[j].Code,code)==0)
            return j;
    }
    return -1;
}

int Recherche_int(int T[],int n,int indice)
{
    int j;
    for (j=0;j<n;j++)
    {
        if (T[j]==indice)
            return j;
    }
    return -1;
}

int Recherche_Epoque(article T[],int n,int epoque,int indice)
{
    int j;
    for (j=indice+1;j<n;j++)
    {
        if (T[j].Epoque==epoque)
            return j;
    }
    return -1;
}

int Recherche_Type(article T[],int n,char type[10],int indice)
{
    int j;
    for (j=indice+1;j<n;j++)
    {
        if (strcmp(T[j].Type,type)==0)
            return j;
    }
    return -1;
}

int Recherche_etat(article T[],int n,char etat[3],int indice)
{
    int j;
    for (j=indice+1;j<n;j++)
    {
        if (strcmp(T[j].Vendu,etat)==0)
            return j;
    }
    return -1;
}

void Supprimer(article T[],int *n,int indice)
{
    int i;
    for (i=indice;i<(*n)-1;i++)
    {
        T[i]=T[i+1];
    }
    (*n)--;
}

void Supprimer_int(int *T,int *n,int indice)
{
    int i;
    for (i=indice;i<(*n)-1;i++)
    {
        T[i]=T[i+1];
    }
    (*n)--;
}

void Modifier(article T[],int n)
{
    int j;
    char code[4];
     SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_RED|BACKGROUND_BLUE|BACKGROUND_GREEN|BACKGROUND_INTENSITY) ;
    printf("Entrer le Code de l'article a modifier\n");
    SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_BLUE|BACKGROUND_RED|BACKGROUND_BLUE|BACKGROUND_GREEN|BACKGROUND_INTENSITY) ;
    scanf("%4s",code);
    while(strlen(code)!=4)
    {
          printf("\a") ;
          Beep(13, 282) ;
        printf("Erreur, Code entre invalide, Resseayez\n") ;
        SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_BLUE|BACKGROUND_RED|BACKGROUND_BLUE|BACKGROUND_GREEN|BACKGROUND_INTENSITY) ;
        scanf("%4s", code) ;
    }
    j=Recherche(T,n,code);
    strcpy(T[j].Code, code);
}

 void Encoding(char *text)
 {
     int r,i;
     r=strlen(text);
     for (i=0;i<r;i++)
     {
         if (text[i]==32)
            text[i]='~';
     }
 }

 void Decoding(char *text)
 {
     int r,i;
     r=strlen(text);
     for (i=0;i<r;i++)
     {
         if (text[i]==126)
            text[i]=' ';
     }
 }

float Chiffre_Affaire(article T[],int n)
 {
     int i;
     float s=0;
     for (i=0;i<n;i++)
     {
         if (strcmp(T[i].Vendu,"oui")==0)
            s+=T[i].Prix;
     }
     return s;
 }

int Controle_Integer(char ch[9])
 {
     int y;
     int i;
     y=strlen(ch);
     for (i=0;i<y;i++)
     {
         if ((48>ch[i])||(ch[i]>57))
            return -1;
     }
            return atoi(ch);
 }

float Controle_Float(char ch[9])
 {
     int y;
     int i;
     y=strlen(ch);
     for (i=0;i<y;i++)
     {
         if (((48>ch[i])||(ch[i]>57))&&(ch[i]!=46))
            return -1;
     }
     return atof(ch);
 }
