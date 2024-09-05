    #include <stdio.h>

int main() { 
    int i,n;
    int T1[5];
    int T2[5];
    int v,nv;
    printf("donner le nomber des elements :");
    scanf("%d",&n);
    for (i=0;i<n;i++){
        printf("T1[%d]= ",i);
        scanf("%d",&T1[i]);
    }
    for(i=0;i<n;i++){
    T2[i]=T1[i];
    }
    printf("Tableau original:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", T1[i]);
    }
    printf("Tableau copie:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", T2[i]);
    }
    return 0;
}