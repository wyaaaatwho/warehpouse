int n=0;
scanf("%d",&n);
long long fact=0;
long long a=0;
int temp[n];
for(int i=1;i<=n;i++)
{
temp[i-1]=1;
for(int j=1;j<=i;j++)
{
temp[i-1]=(temp[i-1]%10007)*j;
}
fact=((temp[i-1]%10007)%10007)+fact;
}
int b= fact%10007;
printf("%lld",b);
return 0;