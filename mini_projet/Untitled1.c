#include<stdio.h>
#include"magasin.h"
#include<string.h>

article fiche()
{
    article mbl;
    printf("Entrer Le Code De l'article\n");
    scanf("%i",&mbl.Code);
    //while (1)
    //{
        printf("Entrer Le Type Du article\n");
        scanf("%10s",mbl.type);
    //    if ((mbl.type=='meuble') || (mbl.type=='decor') || (mbl.type=='couvert') || (mbl.type=='tableau') || (mbl.type=='instrument'))
     //   {break;}
    //}
    while (1)
    {
        printf("Entrer l'annee de la fabrication\n");
        scanf("%i",&mbl.Epoque);
        if ((mbl.Epoque<2021)&&(mbl.Epoque>0))
            {break;}
    }
    printf("Decrire l'article\n");
    scanf("%s",mbl.Description);
    printf("Entrer La Longueur De l'article\n");
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
    printf("Le Code est %i\n Le Type est %s\n L'Epoque est %i\n La Description est %s\n Les Dismensions Sont (%f,%f)\n Le Prix est %f\n Vendu? %3s",mbl.Code,mbl.type,mbl.Epoque,mbl.Description,mbl.Dimension.hauteur,mbl.Dimension.Largeur,mbl.Prix,mbl.Vendu);
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

int Recherche(article T[],int n,int code)
{
    int j;
    for (j=0;j<n;j++)
    {
        if (T[j].Code==code)
            return j;
    }
    return -1;
}

void Supprimer(int* T,int n, int b)

{
    int i ;
    int nbr ;
    article Y[] ; /* sous liste delements*/
    int c ;
    int ecart ;
    int j = 0  ;
    int nb ;

    char etat1[3] ;
    int rang ;   /* ordre delement donne dans une sous liste */
    char type1[10] ;
    int epoque1 ;
    int sous_reponsesupen ;
    int sous_reponsesupch ;
    char reponse [20] ;
    switch (b)
    {
/* un element unique a supprimer */
      case(0) :
          {
              printf("entrer le type  d'identifiant d'article a supprimer \n") ;
              scanf("%s" , reponse) ;
              if(strcmp(reponse , Float) == 0 )
              {
                  printf(" entrer dans ce cas le prix de l' article \n") ;
                  scanf("%f", prix1) ;
                  i = 0 :

                  while( i < n )
                  {

                    if (T[i].prix != prix1)
                    {
                        i = i+1 ;
                    }
                    else
                    {
                        for(c= i ; c< n ; c++)
                        {
                           T[c]== T[c+1] ;
                        }
                        printf(" le stock a ete bien mis a jour , il est desormais de quantite : %i " , n-1) ;
                        break ;
                    }
                    }
                    if(i == n )
                    {
                        printf(" le prix  entre est invalide , aucun element  coreespondant au prix  entre a ete trouve  ") ;
                    }
              }
              if (strcmp(reponse , Entier) == 0 )
              {
                  printf(" voulez vous supprimer l ' article selon  le code ou l' epoque ? \n ") ;
                  scanf("%i " , sous_reponsesupen ) ;
                  switch ( sous_reponsesupen)
                  {
                    case 0 :
                    {
                      printf(" entrez dans ce cas le code de l'artcile a supprimer  \n ") ;
                      scanf("%i " , code1) ;
                      i = 0 ;
                      c= 0 ;

                      while( i < n )
                      {

                        if (T[i].Code!= code1)
                        {
                         i = i+1 ;
                        }
                        else
                        {

                          for (c= i ; c < n ; c++)
                          {
                              T[c]== T[c+1] ;
                          }

                          printf(" le stock a ete bien mis a jour , il est desormais de quantite : %i " , n-1) ;
                          break ;
                        }
                       }
                       if(i == n )
                       {
                        printf(" le code   entre est invalide , aucun element coreespondant a ce code a ete trouve ") ;
                        }
                    }
                    case 1 :
                    {
                      printf(" entrer dans ce cas l'epoque et le rang dinsertion de l'article a supprimer  \n ") ;
                      scanf("% i %i " , epoque1 , rang) ;
                      while(i < n )
                      {
                          if(T[i].Epoque !=  epoque1)
                          {
                              i=i+1 ;
                          }
                          else
                          {
                              Y[j]= T[i] ;
                              i= i+1 ;
                              j= j+1 ;


                          }
                      }
                      if((i == n )&&(j == 0))
                      {
                          printf(" epoque invalide , aucun  element coresspondant a cette epoque trouve ") ;
                      }
                      else
                      {
                         for(c= rang ; c < j ; c++)
                         {
                             Y[c]= Y[c+1] ;
                         }
                         printf(" l'element  de lepoque %i  numero %i  a ete supprime avec succes " , epoque1 , rang ) ;
                      }

                      }

                    }
                    if(strcmp(reponse , string )== 0)
                    {
                        printf(" voulez vous supprimer  l'article selon  son type ou son etat ? ");
                        scanf("%i" , sous_reponsesupch) ;
                        switch (sous_reponsesupch)
                        {
                         case 0 :
                            {
                              printf(" entrez le type et le rang dinsertion  de l 'article que vous souhaitez supprimer ") ;
                              scanf("%10s" , type1);
                              while(i < n)
                              {
                                  if (strcmp(T[i].type, type1)== 0 )
                                  {
                                     Y[j] = T[i] ;
                                     j= j+1 ;
                                     i=i+1 ;
                                  }
                                  else
                                  {
                                      i=i+1 ;
                                  }
                                  }
                                  if((i== n )&&(j == 0))
                                  {
                                      printf(" type invalide , element non trouve ") ;
                                  }
                                  else
                                  {
                                     for(c = rang ; c < j ; c++)
                                     {
                                         Y[c]=Y[c+1] ;
                                     }
                                     printf(" l'element de type %s et qui est classe %i eme dans sa liste a ete supprime avec success : " , type1 , rang ) ;
                                  }

                              }
                              case 1 :
                                  {
                                      printf(" entrer letat de votre article et son rang dinsertion  ") ;
                                      scanf(" %3s " , etat1 ) ;
                                      while(i < n)
                                      {
                                        if (strcmp(T[i].Vendu, etat1)== 0 )
                                        {
                                          Y[j] = T[i] ;
                                          j= j+1 ;
                                          i=i+1 ;
                                        }
                                        else
                                        {
                                          i=i+1 ;
                                        }
                                       }
                                     if((i== n )&&(j == 0))
                                     {
                                      printf(" etat invalide , element non trouve ") ;
                                     }
                                    else
                                    {
                                      for(c = rang ; c < j ; c++)
                                      {
                                         Y[c]=Y[c+1] ;
                                      }
                                     printf(" l'element  qui est classe %i eme dans sa liste detats  a ete supprime avec success : "  , rang ) ;
                                  }
                                  }

                                 }
  /* tous les elements*/                               }

            case(1) :
                    {
                        while ( nb< n )
                        {


                        for(i = 0 ; i<n ; i++)
                        {
                            T[i]= T[i+1] ;
                        }
                        nb=nb+1 ;
                        }
                        }
/* tous les elements dune sous liste definie */
            case (2)  :
                   {
                       printf(" veuillez choisir un critere  de cette liste : (  0 : type ,  1 : epoque , 2 : etat  ") ;
                       scanf(" %i" , sous_choix ) ;
                       switch(sous_choix)
                       {
                         case 0 :
                         {
                           printf(" entrer  le type des articles que  vous voulez supprimer ")  ;
                           scanf("%10s", type1) ;
                           while(i < n)
                              {
                                  if (strcmp(T[i].type, type1)== 0 )
                                  {
                                     Y[j] = T[i] ;
                                     j= j+1 ;
                                     i=i+1 ;
                                  }
                                  else

                                  {
                                      i=i+1 ;
                                  }
                                  }
                                  if((i== n )&&(j == 0))
                                  {
                                      printf(" type invalide ") ;
                                  }
                                  else
                                  {  while(nb< n)
                                     {

                                       for(c = 0 ; c < j ; c++)
                                       {
                                         Y[c]=Y[c+1] ;
                                         nb= nb+1 ;
                                        }
                                     }
                                     printf(" tous les elements de type %10s  ont ete supprime avec success : " , type1  ) ;
                                  }

                         }
                        case 1 :
                         {    printf(" entrer l'epoque des articles que vous voulez supprimer ") ;
                              scanf("%i" , epoque1) ;
                              while(i < n )
                              {
                               if(T[i].Epoque !=  epoque1)
                               {
                                i=i+1 ;
                               }
                              else
                              {
                              Y[j]= T[i] ;
                              i= i+1 ;
                              j= j+1 ;


                              }
                             }
                            if((i == n )&&(j == 0))
                            {
                              printf(" epoque invalide ,  ") ;
                            }
                           else
                           { while(nb< n)
                             {

                               for(c= 0 ; c < j ; c++)
                               {
                                Y[c]= Y[c+1] ;
                                nb= nb+1 ;
                               }
                             }
                            printf("  tous les elements  de lepoque %i  ont ete supprime avec succes " , epoque1  ) ;
                          }
                          }
                    case 2 :
                    { printf(" entrer  l'etat des articles que vous voulez supprimer ") ;
                      scanf("%3s" , etat1) ;
                      while(i < n)
                              {
                                  if (strcmp(T[i].Etat, etat1)== 0 )
                                  {
                                     Y[j] = T[i] ;
                                     j= j+1 ;
                                     i=i+1 ;
                                  }
                                  else

                                  {
                                      i=i+1 ;
                                  }
                                  }
                                  if((i== n )&&(j == 0))
                                  {
                                      printf(" type invalide ") ;
                                  }
                                  else
                                  {  while(nb< n)
                                     {

                                       for(c = 0 ; c < j ; c++)
                                       {
                                         Y[c]=Y[c+1] ;
                                         nb= nb+1 ;
                                        }
                                     }
                                     printf(" tous les elements d'etat %3s  ont ete supprime avec success : " , epoque1  ) ;
                                  }
                                  }

                                  }
/* groupe fixe delements */
                        case 3 :
                        {
                            printf(" entrer le nombre delements que vous voulez supprimer ") ;
                            scanf("%i " , nbr) ;
                            printf(" veuillez choisir un critere  de cette liste : (  0 : type ,  1 : epoque , 2 : etat  ") ;
                            scanf(" %i" , sous_choix ) ;
                           switch(sous_choix)
                           {
                            case 0 :
                            {
                             printf(" entrer  le type des articles que  vous voulez supprimer ")  ;
                             scanf("%10s", type1) ;
                             while(i < n)
                              {
                                  if (strcmp(T[i].type, type1)== 0 )
                                  {
                                     Y[j] = T[i] ;
                                     j= j+1 ;
                                     i=i+1 ;
                                  }
                                  else

                                  {
                                      i=i+1 ;
                                  }
                                  }
                                  if((i== n )&&(j == 0))
                                  {
                                      printf(" type invalide ") ;
                                  }
                                  else
                                  printf(" entrer l'ecart entre les elements a supprimer ") ;
                                  scanf("%i" , ecart  ) ;

                                  {  while(nb< nbr)
                                     {

                                       for(c = 0 ; c < j ; c++)
                                       {
                                         Y[c]=Y[c+ ecart] ;
                                         nb= nb+1 ;
                                        }
                                     }
                                     printf("  les %i elements de type %10s  ont ete supprime avec success : " , nbr ,  type1  ) ;
                                  }

                         }
                        case 1 :
                         {    printf(" entrer l'epoque des articles que vous voulez supprimer ") ;
                              scanf("%i" , epoque1) ;
                              while(i < n )
                              {
                               if(T[i].Epoque !=  epoque1)
                               {
                                i=i+1 ;
                               }
                              else
                              {
                              Y[j]= T[i] ;
                              i= i+1 ;
                              j= j+1 ;


                              }
                             }
                            if((i == n )&&(j == 0))
                            {
                              printf(" epoque invalide ,  ") ;
                            }
                           else
                           { printf(" entrer l'ecart de suppression entre les elements ") ;
                             scanf("%i" , ecart) ;
                             while(nb< nbr)
                             {

                               for(c= 0 ; c < j ; c++)
                               {
                                Y[c]= Y[c+ ecart] ;
                                nb= nb+1 ;
                               }
                             }
                            printf("  tous les elements  de lepoque %i  ont ete supprime avec succes " , epoque1  ) ;
                          }
                          }
                    case 2 :
                    { printf(" entrer  l'etat des articles que vous voulez supprimer ") ;
                      scanf("%3s" , etat1) ;
                      while(i < n)
                              {
                                  if (strcmp(T[i].Etat, etat1)== 0 )
                                  {
                                     Y[j] = T[i] ;
                                     j= j+1 ;
                                     i=i+1 ;
                                  }
                                  else

                                  {
                                      i=i+1 ;
                                  }
                                  }
                                  if((i== n )&&(j == 0))
                                  {
                                      printf(" type invalide ") ;
                                  }
                                  else
                                  {  printf(" entrer l'ecart entre les elments a supprimer ") ;
                                     scanf("%i" , ecart) ;
                                     while(nb< nbr)
                                     {

                                       for(c = 0 ; c < j ; c++)
                                       {
                                         Y[c]=Y[c+ ecart] ;
                                         nb= nb+1 ;
                                        }
                                     }
