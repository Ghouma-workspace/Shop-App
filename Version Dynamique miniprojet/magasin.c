#include <stdlib.h>
#include<stdio.h>
#include<string.h>
#include"magasin.h"


article fiche()
{
    article mbl;
    printf("Entrer Le Code De l'article\n");

    scanf("%s",mbl.Code);
    while(strlen(mbl.Code)!= 4)
    {
        printf("code invalide veuillez ressayer\n") ;
        scanf("%s",mbl.Code) ;
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
    printf("Entrer L'hauteur De l'article\n");
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


cellule* creation ()
{
    cellule*nouv = (cellule*)malloc(sizeof(cellule)) ;
    nouv->suivant=NULL ;
    nouv->a=fiche() ;
    return nouv ;
}


void affiche(article a)
{

    printf(" Le Code est %s\n Le Type est %s\n L'Epoque est %i\n La Description est %s\n Les Dismensions Sont (%0.2f,%0.2f)\n Le Prix est %0.2f\n Vendu? %3s\n",a.Code,a.Type,a.Epoque,a.Description,a.Dimension.hauteur,a.Dimension.Largeur,a.Prix,a.Vendu);


}



cellule* insererTete(cellule* tete)
{
    cellule*nouv = creation() ;
    nouv->suivant=tete ;
    return nouv ;
}


void afficher(cellule* tete)
{
    cellule* p = tete ;
    while(p != NULL)
    {
       affiche(p->a) ;
       p= p->suivant ;
    }
}




cellule*supprimerTete(cellule*tete)
{
    cellule* p ;
    if(tete!= NULL)
    {
        p=tete ;
        tete=p->suivant ;
        free(p) ;
    }
    return tete ;
}


cellule*rechercher(cellule* tete, char code[5])
{
    cellule*parcours = tete ;
    while(parcours!= NULL)
    {
        if(strcmp(parcours->a.Code , code)== 0)
        {
            return parcours ;
        }

      parcours= parcours->suivant ;
    }
    return NULL ;
    }
