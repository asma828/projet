#include <stdio.h>
#include <string.h>

int main() {
    int i,j;
    char titre[100][50];
    char auteur[100][50];
    int n=3;
    int prix[100];
    int quantite[100];
    int choix;
    char cherchetitre[100];
    int trouver=0;
    char titreenrecherche[5];
    int nouvellequantite;
/*stoker*/
  do{
      printf("menu\n");
      printf("1 Ajouter un livre au stock. \n 2 Afficher tous les livres disponibles. \n 3 Rechercher un livre par son titre. \n 4 Mettre à jour la quantité d'un livre. \n 5 Supprimer un livre du stock.  \n 6 Afficher le nombre total de livres en stock.\n");
      scanf("%d", &choix);
      switch(choix){
          case 1:
            printf("Entrer le titre:");  
            scanf("%s",&titre[i]);
            printf("Entrer l'auteur: ");
            scanf("%s",&auteur[i]);
            printf(" entre le prix :");
            scanf("%d",&prix[i]);
            printf(" La quantite :");  
            scanf("%d",&quantite[i]);
            printf ("livre ajouter avec succes\n");
            break;
        
           case 2:
                for ( i=0; i<n ; i++){
                    printf("titre:%s\n",titre[i]);
                    printf("auteur:%s\n",auteur[i]);
                    printf("prix:%d\n",prix[i]);
                    printf("quantite:%d\n",quantite[i]);
                    }
                break;
            case 3:
             printf("Entrez le titre à rechercher: ");
             scanf("%s",&cherchetitre);
               for ( i=0; i<n ; i++){
                    if (strcmp(titre[i],cherchetitre) == 0) {
                    printf("Livre trouvé:\n");
                    printf("Titre: %s\n", titre[i]);
                    printf("Auteur: %s\n", auteur[i]);
                    printf("Prix: %d\n", prix[i]);
                    printf("Quantité: %d\n", quantite[i]);
                    printf("\n");
                        trouver = 1;
                    break;
                }else{
                    printf("Livre non trouvé.\n");
                }
            }
            break;
            case 4:
            printf("entre le titre d'un livre : ");
            scanf("%s",&titre);
            
            for ( i=0; i<n ; i++){
                if(strcmp(titre[i],cherchetitre)==0){
                    printf("modifier la quantite de ce livre :");
                    scanf("%d",&quantite[i]);
                printf("la quantite est change avec succes \n");
            }else{
            
            
            printf("titre non trouve\n");
            }
            }
            break;
            case 5:
            printf("donner un titre de livre :");
            scanf("%s",&cherchetitre);
            for ( i=0; i<n ; i++){
                if(strcmp(titre[i],cherchetitre)==0){
                    for (int j=i; j<n-1;j++){
                       strcpy(titre[j],titre[j+1]);
                       strcpy(auteur[j],auteur[j+1]);
                       prix[j]=prix[j+1];
                       quantite[j]=quantite[j+1];
                       
                    }
                    n--;
                    printf("livre supprimer \n");
                    
                }
                break;
            }
            break;
            case 6:
            int T=0;
            for ( i=0; i<n ; i++){
            T=T+quantite[i];
            }
            }
            break;
            
                } while(choix!=7);
                return 0;
                 
             
            }