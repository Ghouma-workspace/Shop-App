#ifndef MAGASIN_DYNAMIQUE_H_INCLUDED
#define MAGASIN_DYNAMIQUE_H_INCLUDED


typedef struct
{
    float hauteur;
    float Largeur;
}Dim;


typedef struct
{
   char  Code[5];
    char Type[10];
    int Epoque;
    char Description[100];
    Dim Dimension;
    float Prix;
    char Vendu[3];
}article ;

typedef struct cellule
{
    article a ;
    struct cellule* suivant ;
}cellule ;


article fiche();
cellule* creation () ;
cellule*insererTete(cellule* tete ) ;
void affiche(article a);
void afficher(cellule* tete) ;
cellule* supprimerTete(cellule* tete) ;
cellule* rechercher(cellule*tete, char  code[5]) ;


#endif // MAGASIN_DYNAMIQUE_H_INCLUDED
