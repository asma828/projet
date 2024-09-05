#include <stdio.h>
int somme(int a,int b){
    return a+b;
}
      
 int n1,n2;
 int s;
int main() {
    printf("donner la premier nomber :\n");
    scanf("%d",&n1);
    printf("donner la deuxieme nomber :\n");
    scanf("%d",&n2);
  
  s=somme(n1,n2);
  printf("la somme de %d et %d est  : %d ",n1,n2,s);
  return 0;
}