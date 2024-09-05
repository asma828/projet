#include <stdio.h>
int multiplication(int a,int b){
    return a*b;
}
      
 int n1,n2;
 int m;
int main() {
    printf("donner la premier nomber :\n");
    scanf("%d",&n1);
    printf("donner la deuxieme nomber :\n");
    scanf("%d",&n2);
  
  m=multiplication(n1,n2);
  printf("la multiplication de %d et %d est  : %d ",n1,n2,m);
  return 0;
}