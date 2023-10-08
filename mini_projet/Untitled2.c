
#include<stdio.h>
#include"magasin.h"
#include<stdlib.h>
#include<string.h>

int main()
{
    article tab[20];
    int n,i,var,k=0;

    char code_recherche[12] ;
    char code_affiche[12] ;
    /*article mbl;
    mbl=fiche();
    affiche(mbl);
    n=4;
    archive(tab,n);
    printf("Entrer le Code de l'article a recherche\n");
    scanf("%i",&code_recherche);
    printf("le Code de l'article cherche est : %i\n",Recherche(tab,n,code_recherche));
    n=Supprimer(tab,n);
    Modifier(tab,n);*/
    n=0;
    int choix,cd;
    int tableau[50];
    FILE *f;
    f=fopen("Miniprojet.txt","rt");
    if (f==NULL)
        printf("Le fichier n'existe pas\n");
    else
    {
        while(!feof(f))
        {
            fscanf(f,"%12s%s%i%s%f%f%f%3s\n",tab[n].Code,tab[n].Type,&tab[n].Epoque,tab[n].Description,&tab[n].Dimension.hauteur,&tab[n].Dimension.Largeur,&tab[n].Prix,tab[n].Vendu);
            n++;
        }
    }
    fclose(f);
    while (1)
    {
        printf("************MENU************\n");
        printf("\t1 : Saisir\n\t2 : Afficher\n\t3 : Recherche\n\t4 : Modifier\n\t5 :Supprimer\n\t6 : Calculer chiffre daffaire\n\t0 : Quitter\n");
        printf("****************************\n");
        scanf("%i",&choix);
        switch(choix)
    {


                case 0 :
                    f=fopen("Miniprojet.txt","wt");
                    //printf("N=%d\n",N);
                    for (i=0;i<n;i++)
                    {
                        fprintf(f,"%12s %s %i %s %0.2f %0.2f %0.2f %3s\n",tab[i].Code,tab[i].Type,tab[i].Epoque,tab[i].Description,tab[i].Dimension.hauteur,tab[i].Dimension.Largeur,tab[i].Prix,tab[i].Vendu);
                    }
                    fclose(f);
                    exit(0);
                case 1 :
                    {
                        do
                        {
                            tab[n]=fiche();
                            n++;
                            printf("Voulez-vous ajouter un autre article?\ntaper 1 pour OUI et 0 pour NON\n");
                            scanf("%i",&cd);
                        }while((n<20)&&(cd==1));
                        break;
                    }
                case 2 :

                        while (1)
                        {
                        printf("1 : afficher les donnees de tous les articles\n2 : afficher les articles recherche\n3 : afficher les donnees d'un seul article\n0 : retourner\n");
                        scanf("%i",&var);
                        if (var==1)
                        {
                            for (i=0;i<n;i++)
                                affiche(tab[i]);
                        }
                        else if (var==2)
                        {
                            if (k==0)
                                printf("Il n'y a aucun article\n");
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
                        else if (var == 3)
                        {
                            do
                            {   printf(" entrer le code de l'article que vous voulez afficher\n") ;
                                scanf("%12s", code_affiche) ;
                                i=Recherche(tab,n,code_affiche);
                                if (i==-1)
                                    printf("Article introuvable\n");
                                else
                                    affiche(tab[i]);
                                var=0;
                                printf("Pour afficher les donnees d'un autre article entrer son Code sinon entrer 0\n");
                                scanf("%i",&var);
                            }while(var!=0);
                        }
                        }
                        break;

                case 3 :
                    {
                      /*  printf("Entrer le Code de l'article a recherche\n");
                        scanf("%i",&code_recherche);
                        if (Recherche(tab,n,code_recherche)==-1)
                            printf("Article introuvable\n");
                        else
                            printf("L'article recherche est d'indice %i",Recherche(tab,n,code_recherche));
                        break; */
                        int sous_choix_recherche,s,j;
                        while (1)
                        {
                            printf("1 : Recherche selon le Code\n2 : Recherche selon le Prix\n3 : Recherche selon L'Epoque\n4 : Recherche selon le Type\n5 : Encore filtrer\n0 : Retourner\n");
                            scanf("%i",&sous_choix_recherche);
                            switch (sous_choix_recherche)
                            {
                                case 0 : goto EndWhile;
                                case 1 :
                                {
                                    do
                                    {
                                        printf(" Entrez le code de l'article que vous cherchez\n") ;
                                        scanf("%12s", code_recherche);
                                        s=Recherche(tab,4,code_recherche) ;
                                        if(s== -1)
                                            printf("Article introuvable, verifiez le code entre\n") ;
                                    }while(s==-1);
                                    printf("L'article recherche est d'indice %i",s);
                                    break;


                                case 2 :
                                    {
                                        int prix_min,prix_max;
                                        printf("Entrez le prix minimum des articles que vous voulez trouver\n");
                                        scanf("%i",&prix_min);
                                        printf("Entrez le prix maximum des articles que vous voulez trouver\n");
                                        scanf("%i",&prix_max);
                                        j=0;
                                        for (i=0;i<n;i++)
                                        {
                                            if ((tab[i].Prix>=prix_min)&&(tab[i].Prix<=prix_max))
                                            {
                                                printf("L'article recherche est d'indice %i\n",i);
                                                tableau[j]=i;
                                                j++;
                                            }
                                        }
                                        k=j;
                                        if (k==0)
                                            printf("Article introuvable\n");
                                        break;
                                    }
                                case 3 :
                                    {
                                        int epoque;
                                        printf("Entrer l'Annee\n");
                                        scanf("%i",&epoque);
                                        i=0;
                                        j=Recherche_Epoque(tab,n,epoque,-1);
                                        while(j!=-1)
                                        {
                                            printf("L'article recherche est d'indice %i\n",j);
                                            tableau[i]=j;
                                            j=Recherche_Epoque(tab,n,epoque,j);
                                            i++;
                                        }
                                        k=i;
                                        if (i==0)
                                            printf("Il n'y a aucun article\n");
                                        break;
                                    }
                                case 4 :
                                    {
                                        char type[10];
                                        printf("Entrer le Type de l'article\n");
                                        scanf("%s",type);
                                        j=Recherche_Type(tab,n,type,-1);
                                        i=0;
                                        while(j!=-1)
                                        {
                                            printf("L'Article Recherche est d'indice %i\n",j);
                                            tableau[i]=j;
                                            j=Recherche_Type(tab,n,type,j);
                                            i++;
                                        }
                                        k=i;
                                        if (i==0)
                                            printf("Il n'y a aucun article\n");
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
                        char code[12] ;
                        while (1)
                        {
                            printf("1 : Modifier un article\n2 : Modifier les articles recherches\n0 : Retourner\n");
                            scanf("%i",&choice);
                            switch(choice)
                            {
                                case(0) :
                                    goto khrouj;
                                case(1) :
                                {
                                    int i;
                                    printf("Saisir le Code de l'article a modifier\n");
                                    scanf("%12s",code);
                                    i=Recherche(tab,n,code);
                                    while(i!=-1)
                                    {
                                    printf("1 : Modifier le Type\n2 : Modifier l'epoque\n3 : Modifier la Description\n4 : Modifier la Hauteur\n5 : Modifier la largeur\n6 : Modifier le Prix\n7 : L'article est vendu\n0 : Retouner\n");
                                    scanf("%i",&sous_choice);
                                        switch(sous_choice)
                                        {
                                            case(0) :
                                                goto cbon;
                                            case(1) :
                                                {char type[10];
                                                printf("Entrer le nouveau Type\n");
                                                scanf("%s",type);
                                                strcpy(tab[i].Type,type);
                                                break;}
                                            case(2) :
                                                {int epoque1 ;
                                                printf("entrer la nouvelle epoque \n") ;
                                                scanf("%i",&epoque1) ;
                                                tab[i].Epoque = epoque1;
                                                break ;}
                                            case(3) :
                                                {char description[100];
                                                printf("Entrer la nouvelle Description\n");
                                                fflush(stdin);
                                                gets(description);
                                                strcpy(tab[i].Description,description);
                                                break;}
                                            case(4) :
                                                {float hauteur;
                                                printf("Entrer la nouvelle Hauteur\n");
                                                scanf("%f",&hauteur);
                                                tab[i].Dimension.hauteur=hauteur;
                                                break;}
                                            case(5) :
                                                {float largeur;
                                                printf("Entrer la nouvelle Largeur\n");
                                                scanf("%f",&largeur);
                                                tab[i].Dimension.Largeur=largeur;
                                                break;}
                                            case(6) :
                                                {float prix;
                                                printf("Entrer la nouvelle Prix\n");
                                                scanf("%f",&prix);
                                                tab[i].Prix=prix;
                                                break;}
                                            case(7) :
                                                {if (strcmp(tab[i].Vendu,"oui")==0)
                                                    printf("Article deja vendu\n");
                                                else
                                                    strcpy(tab[i].Vendu,"oui");
                                                break;}
                                            default : printf("Entree Invalide\n");
                                        }
                                    }
                                    cbon : break;
                                }
                                case(2) :
                                {
                                    int cd,i;
                                    while(1)
                                    {
                                        printf("1 : Modifier le Prix\n2 : Vendre les articles\n0 : Retourner\n");
                                        scanf("%i",&cd);
                                        switch(cd)
                                        {
                                        case(0) :
                                            goto khanga;
                                        case(1) :
                                            {float prix;
                                            printf("Entrer le nouveau prix\n");
                                            scanf("%f",&prix);
                                            for (i=0;i<k;i++)
                                                tab[tableau[i]].Prix=prix;
                                            break;}
                                        case(2) :
                                            {for (i=0;i<k;i++)
                                                strcpy(tab[tableau[i]].Vendu,"oui");
                                        }
                                    }
                                    khanga : break;
                            }}
                            default : printf("Entree Invalide");
                        }
                        khrouj : break;
                    }
                    break;
                    }
                case 5 :
                    {
                        while (1)
                        {
                        printf("1 : Supprimer tous les articles\n2 : Supprimer les articles recherche\n3 : Supprimer un seul article\n0 : retourner\n");
                        scanf("%i",&var);
                        switch(var)
                        {
                            case(1) :
                            {
                                while(n!=0)
                                    Supprimer(tab,&n,0);
                            }
                            case(2) :
                            {
                                if (k==0)
                                    printf("Il n'y a aucun article\n");
                                else
                                {
                                    for (i=0;i<k;i++)
                                    {
                                        Supprimer(tab,&n,tableau[i]);
                                    }
                                }
                            }
                            case(0) : goto Okhroj;
                            case(3) :
                                {
                                int j;
                                do{
                                    char code[12];
                                    printf("Entrer le Code de l'article a supprimer\n");
                                    scanf("%12s",code);
                                    j=Recherche(tab,n,code);
                                    if (j==-1)
                                        printf("Article introuvable\n");
                                    else
                                        Supprimer(tab,&n,j);
                                    var=0;
                                    printf("Pour supprimer un autre article entrer son Code sinon entrer 0\n");
                                    scanf("%i",&var);
                                }while(var!=0);
                                }
                        }
                        }
                    }
                    case(6):
                    {
                      float k ;
                      k= chiffre_daffaire(tab , n) ;
                      printf("votre chiffre daffaire est de lordre de : %f", k) ;
                    }





                        Okhroj : break;
                        default : printf("Entrer invalide\n");
                }
                    }

    }
    //free(tab);


 return 0 ;


}
