#include <stdio.h>
#include <math.h>
int main() {
    // Write C code here
    int n,i,P;
    printf("calculer la puissance :\n");
    printf("donner un nomber :");
    scanf("%d",&n);
    while(n<=0) {
    printf("ce nomber est negative\n");
    printf("entre un nomber positive\n");
    scanf("%d",&n);
    }

    
    
    P=pow(n,2);
    printf("la puissance est %d",P);



    return 0;
}