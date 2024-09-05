#include <stdio.h>

int main() {
  int i,n;
    int T[5];
    printf("donner le nomber des elements :");
    scanf("%d",&n);
    for (i=0;i<n;i++){
        printf("T[%d]= ",i);
        scanf("%d",&T[i]);
    }
     printf("Les éléments pairs du tableau sont:\n");
    for (i = 0; i < n; i++) {
        if (T[i] % 2 == 0) {
            printf("%d ", T[i]);
        }
    }
    printf("\n");
    return 0;
}