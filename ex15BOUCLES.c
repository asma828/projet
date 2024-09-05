  
  
    int n;
    float i,f;
    printf("donner un nomber :");
    scanf("%d",&n);
    f=1;
    if(n>0){
      for(i=2;i<=n;i++){
          f=f*i;
      }
      printf("le factorielle de %d est :%.2f",n,f);
    }
    else if(n==0)
    printf("le factorielle est : 1");
    else
    printf("saiser un nomber positive");
return 0;