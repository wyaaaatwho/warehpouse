int n= 0;
scanf("%d",&n);
getchar ();
char array[n];
for(int i=0;i<n;i++)
{
scanf("%c",&array[i]);
}
for(int j=0;j<=(n/2+1);j++)
{
if(array[j]=='?')
{
array[j]=array[n-1-j];
}
else
array[n-1-j]=array[j];
}
for(int a=0;a<n;a++)
{
printf("%c",array[a]);
}

