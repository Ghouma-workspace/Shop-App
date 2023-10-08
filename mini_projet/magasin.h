#ifndef MAGASIN_H_INCLUDED
#define MAGASIN_H_INCLUDED

typedef struct
{
    float hauteur;
    float Largeur;
}Dim;

typedef struct
{
    char Code[5];
    char Type[10];
    int Epoque;
    char Description[100];
    Dim Dimension;
    float Prix;
    char Vendu[3];
}article;



article fiche(article T[],int n);
void affiche(article mbl);
void archive(article T[],int n);
int Recherche(article T[],int n,char code[5]);
int Recherche_Epoque(article T[],int n,int epoque,int indice);
int Recherche_Type(article T[],int n,char type[10],int indice);
int Recherche_etat(article T[],int n,char etat[3],int indice);
void Supprimer(article T[],int *n,int indice);
void Modifier(article T[],int n);
void Encoding(char *text);
void Decoding(char *text);
float Chiffre_Affaire(article T[],int n);
void Supprimer_int(int T[],int *n,int indice);
int Recherche_int(int T[],int n,int indice);
int Controle_Integer(char ch[9]);
float Controle_Float(char ch[9]);
#endif // MAGASIN_H_INCLUDED
