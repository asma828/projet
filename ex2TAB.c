#include <stdio.h>

int main() {
    int n,i;
    printf (" nombre d'éléments d'un tableau:");
    scanf ("%d",&n);
    int T[n];
    for(i=0;i<n;i++) {
        printf("saisair les elements de:");
        scanf("%d", &T[i]);
    }
     for (i = 0; i < n; i++) {
         printf("%d ", T[i]);
     }
     return 0;
}