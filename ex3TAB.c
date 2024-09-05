#include <stdio.h>

int main() {
    int i,n,s;
    int T[n];
    s=0;
    printf("donner le nombre d'éléments :");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        printf("T[%d] = ",i);
        scanf("%d",&T[i]);
    }
    for(i=0;i<n;i++){
        s=s+T[i];
    }
    printf("la somme des elements de tableux est %d",s);
    return 0;
}