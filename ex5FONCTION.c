#include <stdio.h>
#include <math.h>
int  factorielle(int a){
 if(a==0||a==1){
 return 1;     
 }
 int f=1;
 int i;
 for(i=2;i<=a;i++){
     f= f*i;
 }
 return f;
}
 int n;
 int f;
int main() {
    printf("donner un nomber :\n");
    scanf("%d",&n);
  
  f= factorielle(n);
  printf("la factorielle de %d est  : %d ",n,f);
return 0;
}