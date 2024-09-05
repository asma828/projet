#include <stdio.h>
#include <math.h>
int  parite(int a){
 if(a%2==0){
 return 1;     
 }else{
     return 0;
 }

 }

 int n;
 int p;
int main() {
    printf("donner un nomber :\n");
    scanf("%d",&n);
    if (parite(n)) {
        printf("%d est pair.\n", n);
    } else {
        printf("%d est impair.\n", n);
    }
return 0;
}