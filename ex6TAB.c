#include <stdio.h>

int main() {

    int T[5];
    int i;
    int n,M;
    printf("donner le nomber des elements :");
    scanf("%d",&n);
    for (i=0;i<n;i++){
        printf("T[%d]= ",i);
        scanf("%d",&T[i]);
    }
    M=1;
    for(i=0;i<n;i++){
        M=M * T[i];
    }
printf("la multiplication des nombers est:%d",M);*/
    return 0;
}