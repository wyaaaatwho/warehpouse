//
// Created by 26711 on 2023/10/15.
//
int n=0;
scanf("%d",&n);
int array[1000]={0};
int i=0;
do{
array[i]=n%2;
n=n/2;
i++;
}while(n);
for(int a=i-1;a>=0;a--)
{
printf("%d",array[a]);
}