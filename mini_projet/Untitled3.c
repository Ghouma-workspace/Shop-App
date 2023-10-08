#include<stdio.h>
#include"magasin.h"
#include<string.h>
#include<string.h>

article fiche()
{
    article mbl;
    printf("Entrer Le Code De l'article\n");

    scanf("%12s",mbl.Code);
    while(strlen(mbl.Code)!= 12)
    {
        printf("code invalide veuillez ressayer\n") ;
        scanf("%12s",mbl.Code) ;
    }
    while (1)
    {
        printf("Entrer Le Type Du article\n");
        printf("Le type de l'article doit etre meuble ou decor ou couvert ou tableau ou instrument\n");
        scanf("%10s",mbl.Type);
        if ((strcmp(mbl.Type,"meuble")==0) || (strcmp(mbl.Type,"decor")==0) || (strcmp(mbl.Type,"couvert")==0) || (strcmp(mbl.Type,"tableau")==0) || (strcmp(mbl.Type,"instrument")==0))
            {break;}
    }
    while (1)
    {
        printf("Entrer l'annee de la fabrication\n");
        scanf("%i",&mbl.Epoque);
        if ((mbl.Epoque<2021)&&(mbl.Epoque>0))
            {break;}
    }
    printf("Decrire l'article\n");
    fflush(stdin);
    gets(mbl.Description);
    printf("Entrer La Longueur De l'article\n");
    fflush(stdin);
    scanf("%f",&mbl.Dimension.hauteur);
    printf("Entrer La Largeur De l'article\n");
    scanf("%f",&mbl.Dimension.Largeur);
    while (1)
    {
        printf("Donner Le Prix\n");
        scanf("%f",&mbl.Prix);
        if (mbl.Prix>0)
            break;
    }
    while (1)
    {
        printf("L'article est-il vendu?\n");
        scanf("%s",mbl.Vendu);
        if ((strcmp(mbl.Vendu,"oui")==0)||(strcmp(mbl.Vendu,"non")==0))
            {break;}
    }
    return mbl;
}


void affiche(article mbl)
{
    printf(" Le Code est %12s\n Le Type est %s\n L'Epoque est %i\n La Description est %s\n Les Dismensions Sont (%0.2f,%0.2f)\n Le Prix est %0.2f\n Vendu? %3s\n",mbl.Code,mbl.Type,mbl.Epoque,mbl.Description,mbl.Dimension.hauteur,mbl.Dimension.Largeur,mbl.Prix,mbl.Vendu);
}

void archive(article T[],int n)
{
    int i;
    /*printf("Entrer le nombre des articles\n");
    scanf("%i",&n);
    T=(int *)malloc(sizeof(int)*n);*/
    for (i=0;i<n;i++)
    {
        T[i]=fiche();
    }
}

int Recherche(article T[],int n,char code[12])
{
    int j;
    for (j=0;j<n;j++)
    {
        if (strcmp(T[j].Code,code)== 0)
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

void Supprimer(article T[],int *n,int indice)
{
    int i;
    for (i=indice;i<*n;i++)
    {
        T[i]=T[i+1];
    }
    *n--;
    printf("Votre stock est desormais de taille %i",*n);
}

void Modifier(article T[],int n)
{
    int j;
    char code[12];
    printf("Entrer le Code de l'article a modifier\n");
    scanf("%12s",code);
    while(strlen(code)!= 12)
    {
        printf("erreur , code entre invalide , resseayez") ;
        scanf("%12s", code) ;
    }
    j=Recherche(T,n,code);
    strcpy(T[j].Code, code);
}


float chiffre_daffaire(article T[], int n)
{
    float s = 0 ;
    int  i ;
    for(i= 0 ; i<n ; i++)
    {
        if(strcmp(T[i].Vendu,"oui")== 0)
            s= s+ T[i].Prix ;
    }
    return s ;
}
