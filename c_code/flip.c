int n = 0;
scanf("%d",&n);
int array [n]={0};
int t=1,f=0;
for(int i=1;i<=n;i++)
{
for(int j=0;j<=n-1;j++)
{
if((j+1)%i==0)
{
if(array[j]==t)
array[j]=f;
else
array[j]=t;
}
else array[j]=array[j];
}
}
for(int a=0;a<n;a++)
{
if(array[a]==t)
printf("%d ",a+1);
}
return 0;