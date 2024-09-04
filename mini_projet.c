// Online C compiler to run C program online
#include <stdio.h>
#include <string.h>

void metterajour();
void suppression();
int main() {
     int i;
     char titre[100][50];
     char auteur[100][50];
     int n=3;
     int prix[100];
     int quantite[100];
  for ( i=0; i<n ; i++){
     printf("Entrer le titre:");  
     scanf("%s",&titre[i]);
     while(getchar() !='\n');
     printf("Entrer l'auteur: ");
     scanf("%s",&auteur[i]);
     while(getchar() !='\n');
     printf(" entre le prix ;");
     scanf("%d",&prix[i]);
     printf(" La quantite :");  
     scanf("%d",&quantite[i]);
     printf ("livre ajouter avec succes\n");
}
for ( i=0; i<n ; i++){
    printf("titre:%s\n",titre[i]);
    printf("auteur:%s\n",auteur[i]);
    printf("prix:%d\n",prix[i]);
    printf("quantite:%d\n",quantite[i]);
    
}
    int T;
for ( i=0; i<n ; i++){
    T=0;
    T=T+quantite[i];
}
}


metterajour();



void metterajour(){
    printf("donner un titre");
    scanf("%s",&titre[100][50]);
    char titreenrecherche[5];
    int nouvellequantite;
    for ( i=0; i<n ; i++){
    if(strcmp(titre[i],titreenrecherche)==0){
    printf("modifier la quantite de ce livre:");
    scanf("%s",&titreenrecherche);
    quantite[i]=nouvellequantite;
    printf("la quantite est change avec succes");
    }
}
    printf("un erreur");
}
suppression();
void suppression(){
    printf("donner un titre de livre");
    scanf("%s",titre[100][50]);
  
    int position;  
    for ( i=0; i<n ; i++){
    if(position >=n+1)
}
}