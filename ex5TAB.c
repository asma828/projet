#include <stdio.h>

int main() {
    int min;
    int i,n;
    int T[5];
    printf("donner le nomber des elements de tableux :");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        printf("T[%d] = ",i);
        scanf("%d",&T[i]);
    }
    min=T[0];
    for(i=1;i<n;i++){
        if(min>T[i])
        min=T[i];
    }
    printf("le minium des elements de tableux est %d",min);
    return 0;
}