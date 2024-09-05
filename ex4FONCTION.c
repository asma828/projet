#include <stdio.h>
#include <math.h>
int  minimum(int a,int b){
 if (a<b){
 return a;
}else{
return b;
    
}
}
 int n1,n2;
 int m;
int main() {
    printf("donner la premier nomber :\n");
    scanf("%d",&n1);
    printf("donner la deuxieme nomber :\n");
    scanf("%d",&n2);
  
  m= minimum(n1,n2);
  printf("la  minimum de %d et %d est  : %d ",n1,n2,m);
return 0;
}