#include <stdio.h>

int main() {
        int i;
    int T [5];
    int n,m,s;
    printf("donner le nomber des elements :");
    scanf("%d",&n);
    for (i=0;i<n;i++){
        printf("T[%d]= ",i);
        scanf("%d",&T[i]);
    }
    s=0;
    for(i=0;i<n;i++){
        s=s+T[i];
        m=s/n;
    }
printf("la moyenne des nombers est:%d",m);
    return 0;
}