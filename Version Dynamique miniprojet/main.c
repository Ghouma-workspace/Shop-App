#include <stdio.h>
#include <stdlib.h>
#include"magasin.h"

int main()
{
   cellule*magasin = NULL ;
   cellule*element = NULL ;
    int choix ;
    int dec ;
    char code[5] ;
    while(1)
    {
        printf("********MENU********\n");
        printf("| 1 : insererTETE  |\n") ;
        printf("| 2 : afficher     |\n") ;
        printf("| 3 : supprimer    |\n") ;
        printf("| 4 : recherche    |\n") ;
        printf("| 0 : quitter      |\n") ;
        printf("********************\n");
        printf("donner le choix\n") ;
        scanf("%i", &choix) ;
        switch(choix)
        {
         case 0 : exit(0);
         case 1 :
         {

             do{magasin = insererTete(magasin);
                printf(" voulez vous ajouter ? \t 1 oui \2 non\n ") ;
                scanf("%d" , &dec) ;
                }while(dec == 1);
                break ;
        }
        case 2 :
            {
                if (magasin == NULL)
                    printf(" le magasin est actuellement vide\n") ;
                else
                    afficher(magasin) ;

                break ;
            }

        case 3 :
            {
                magasin=supprimerTete(magasin) ;
                break;
            }

        case 4 :
            {
                printf(" entrer  le code d 'article que vous cherchez : \n") ;
                scanf("%s" , code) ;
                element = rechercher(magasin , code) ;
                if(element == NULL)
                {
                    printf(" l element nexiste pas\n ") ;

                }
                else
                {
                    element->suivant = NULL ;
                    afficher(element) ;
                }
                break ;
            }
    }
    }

    return 0;
}
