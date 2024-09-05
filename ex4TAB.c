#include <stdio.h>

int main() {
    int max;
    int i,n;
    int T[5];
    printf("donner le nomber des elements de tableux :");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        printf("T[%d] = ",i);
        scanf("%d",&T[i]);
    }
    max=T[0];
    for(i=1;i<n;i++){
        if(max<T[i])
        max=T[i];
    }
    printf("le maximan des elements de tableux est %d",max);
    return 0;
}