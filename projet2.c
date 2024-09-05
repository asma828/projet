#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct contact {
    char nom[30];
    char numero[20];
    char email[30];
};
int main();
    int n_contact=0;
    char contact,nv[30];
struct contact contact1[100];
void ajoutercontacts(){
     printf("Entrer le nom :");  
            scanf(" %[^\n]s",&contact1[n_contact].nom);
            printf("Entrer le numero: ");
            scanf(" %[^\n]s",&contact1[n_contact].numero);
            printf(" entre l'adresse email :");
            scanf(" %[^\n]s",&contact1[n_contact].email);
            printf ("contact ajouter avec succes\n");
             n_contact++;
}
void affichercontacts(){
   if (n_contact == 0) {
        printf("Aucun contact à afficher.\n");
        return;
    }
    
    for(int i =0;i<n_contact;i++){
     printf("\nNom: %s ",contact1[i].nom);
    printf("\nTéléphone: %s",contact1[i].numero);
    printf("\nEmail: %s",contact1[i].email);
        
   }
    
}
void recherchecontacts(){
    char nom_r[30];
    int trouve=0;
   printf("donner un nom de contact :");
   scanf(" %[^\n]s",&nom_r);
   for(int i=0;i<n_contact;i++){
   if(strcmp(contact1[i].nom,nom_r)==0){
    printf("la contact est trouve");
    printf("\nNom: %s ",contact1[i].nom);
    printf("\nTéléphone: %s",contact1[i].numero);
    printf("\nEmail: %s",contact1[i].email);
    trouve=1;
   }
   }
   if(trouve==0)
   {
       printf("\ncontact non trouver\n");
   }
   
  
}
void modifiercontact(){
    char nom_m[30];
 printf("donner un nom de contact"); 
 scanf(" %[^\n]s",&nom_m);
 for (int i=0; i<n_contact; i++){
   if(strcmp(contact1[i].nom,nom_m)==0){
    printf("Modifiez les informations du contact %s:\n", contact1[i].nom);
     printf("entre le nouveau nom :\n");
     scanf(" %[^\n]s",contact1[i].nom);
     printf("Entrez le nouveau numéro de téléphone :\n");
     scanf(" %[^\n]s",contact1[i].numero);
     printf("Entrez la nouvelle adresse e-mail :\n");
     scanf(" %[^\n]s",contact1[i].email);
     printf("Contact modifié avec succès.\n");
      return;
     
}}}
void supprimercontacts(){
    char nom_a[30];
printf("entrer un contact a supprimer :"); 
 scanf(" %[^\n]s",&nom_a);
 for (int i = 0; i < n_contact; i++) {
        if (strcmp(contact1[i].nom, nom_a) == 0) {
            for (int j = i; j < n_contact - 1; j++) {
                contact1[j] = contact1[j + 1];
            }
            n_contact--;
            printf("Contact supprimé avec succès.\n");
            main();
}
 }
      printf("Contact non trouvé.\n"); 
            main();
}
void affichermenu() {
    printf("menu:\n");
    printf("1. Ajouter un contact\n");
    printf("2. Afficher tous les contacts\n");
    printf("3. Rechercher un contact\n");
    printf("4. Modifier un contact\n");
    printf("5. Supprimer un contact\n");}
int main(){
    int ch=0;
    
   while(ch!=5){
      affichermenu();
      printf("entre une choix :");
      scanf("%d",&ch);
       switch (ch) {
            case 1:{ajoutercontacts();
                break;}
            case 2:{affichercontacts();break;}
            case 3:{
                recherchecontacts();
                break;}
            case 4:{
               modifiercontact();
                break;}
            case 5:{
                supprimercontacts();
                break;}
                
            }
       
   }
    return 0;
    
}