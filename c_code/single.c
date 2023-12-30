//
// Created by 26711 on 2023/10/8.
//
int n;
scanf("%d\n",&n);
int array1 [10000];
int array2 [10000];
int i1=0;
while(i1<n*2-1)
{
scanf("%d",&array1[i1]);
array2[array1[i1]]++;
i1++;
}
for(int i2=0;i2<n*2-1;i2++)
{
if(array2[array1[i2]]==1)
{
printf("%d",array1[i2]);
}
else;
}