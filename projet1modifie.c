#include <stdio.h>
#include <string.h>

int main() {
    char titre[100][50];
    char auteur[100][50];
    int n=0;
    int prix[100];
    int quantite[100];
    int choix;
    char cherchetitre[100];
    int trouver=0;
    char titreenrecherche[5];
    int travail = 1;
/*stoker*/
  do{
      printf("menu\n");
      printf("1 Ajouter un livre au stock. \n 2 Afficher tous les livres disponibles. \n 3 Rechercher un livre par son titre. \n 4 Mettre à jour la quantité d'un livre. \n 5 Supprimer un livre du stock.  \n 6 Afficher le nombre total de livres en stock.\n");
      scanf("%d", &choix);
      switch(choix){
          case 1:
            printf("Entrer le titre:");  
            scanf("%s",titre[n]);
            printf("Entrer l'auteur: ");
            scanf("%s",auteur[n]);
            printf(" entre le prix :");
            scanf("%d",&prix[n]);
            printf(" La quantite :");  
            scanf("%d",&quantite[n]);
            printf ("livre ajouter avec succes\n");
            n++;
            break;
        
           case 2:
                for (int i=0; i<n ; i++){
                    printf("titre:%s\n",titre[i]);
                    printf("auteur:%s\n",auteur[i]);
                    printf("prix:%d\n",prix[i]);
                    printf("quantite:%d\n",quantite[i]);
                    }
                break;
            case 3:
             printf("Entrez le titre à rechercher: ");
             scanf("%s",&cherchetitre);
               for (int i=0; i<n ; i++){
                    if (strcmp(titre[i],cherchetitre) == 0) {
                    printf("Livre trouvé:\n");
                    printf("Titre: %s\n", titre[i]);
                    printf("Auteur: %s\n", auteur[i]);
                    printf("Prix: %d\n", prix[i]);
                    printf("Quantité: %d\n", quantite[i]);
                    printf("\n");
                        trouver = 1;
                    break;
                }
               }
                 if (!trouver) {
                    printf("Titre non trouvé.\n");
                }
                break;
                
                
            
            break;
            case 4:
            printf("entre le titre d'un livre : ");
            scanf("%s",&titre);
            
            for (int i=0; i<n ; i++){
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
            int trouver = 0;
            printf("donner un titre de livre :");
            scanf("%s",&cherchetitre);
            for (int i=0; i<n ; i++){
                if(strcmp(titre[i],cherchetitre)==0){
                    for (int j=i; j<n-1;j++){
                       strcpy(titre[j],titre[j+1]);
                       strcpy(auteur[j],auteur[j+1]);
                       prix[j]=prix[j+1];
                       quantite[j]=quantite[j+1];
                       
                    }
                    printf("livre supprimer \n");
                    trouver = 1;
                    break;
                }
            }
            n--;
            if(! trouver){
                printf("titre non trouver\n");
            }
            
            break;
            case 6:
                printf("Nombre total de livres en stock : %d\n", n);
           
            break;
            
            default:
                printf("Choix non valide. Veuillez entrer un nombre entre 1 et 6.\n");
                break;
        
               } 
               
                } while(travail);
             return 0;
             
            }