 #include <stdio.h>

int main() { 
 int i,n;
    int T[5];
    int v,nv;
    printf("donner le nomber des elements :");
    scanf("%d",&n);
    for (i=0;i<n;i++){
        printf("T[%d]= ",i);
        scanf("%d",&T[i]);
    }
    printf("donner la valeur a remplacer :");
    scanf("%d",&v);
    for (i=0;i<n;i++){
          printf("donner la nouvelle valeur :");
          scanf("%d",&nv);
        if(T[i]=v){
        T[i]=nv;
        }
        break;
    }
    printf("Tableau après remplacement:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", T[i]);
    }
    return 0;
}