//
// Created by 26711 on 2023/10/8.
//
int n=0;
scanf("%d",&n);
int array[n+1];
int h=0;
int sum=0;
for(int i=1;i<=n+1;i++)
{
scanf("%d",&array[i-1]);
}
for(int j=0;j<=n;j++)
{
if(sum>=j)
{
sum=sum+array[j];
}
else
{
h=h+(j-sum);
sum=j+array[j];
}
}
printf("%d",h);