#include <stdio.h>
#include <string.h>
#include <stdlib.h>
  struct personne{
        char nom[40];
        char prenom[40];
        int age;
    };
int main(){
    int i;
    int n;
struct personne personnes[40];
    printf("donner le nomber de personne shoutiez vous entre :");
    scanf("%d",&n);
   for(i=0;i<n;i++){
   printf("entre le nom :");
   scanf("%s",personnes[i].nom);
    printf("entre le prenom :");
   scanf("%s",personnes[i].prenom);
    printf("entre l'age :");
   scanf("%d",&personnes[i].age);
 }

for(i=0;i<n;i++){
    printf(" LE nom est : %s",personnes[i].nom);
    printf(" le prenom est : %s",personnes[i].prenom);
    printf(" l'age est : %d",personnes[i].age);
    printf("\n");
}

 
    return 0;

}