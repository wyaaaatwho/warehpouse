
{
    int n=0,k=0;char u;
    scanf("%d",&n);
    u=getchar();
    char a[n+1];char c;
    for(int i=0;i<=n-1;i++)
    {
        a[i]=getchar();
    }
    scanf("%d",&k);
    for(int j=0;j<=(k/2)-1;j++)
    {
        c=a[j];
        a[j]=a[k-1-j];
        a[k-1-j]=c;
    }
    for(int t=k+1;t<=((k+n+1)/2);t++)
    {
        c=a[t-1];
        a[t-1]=a[n+k-t];
        a[n+k-t]=c;
    }
    for(int g=0;g<=n-1;g++)
    {printf("%c",a[g]);}
    return 0;
}
