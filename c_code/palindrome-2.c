//
// Created by 26711 on 2023/10/20.
//
int n=0;
scanf("%d",&n);
getchar();
char str[200005]={0};
char ment[2]={'0','0'};
scanf("%s",&str[0]);
for(int i =0;i<n/2;i++)
{
if(str[i]!='?'&&str[n-1-i]!='?')
{
;
}
else if(str[i]=='?'&&str[n-i-1]!='?')
{
str[i]=str[n-i-1];
}
else if(str[i]!='?'&&str[n-i-1]=='?')
{
str[n-i-1]=str[i];
}
else if(str[i]==str[n-i-1]&&str[i]=='?')
{
n=n+2;
for(int j=n-3;j>n-i-3;j--)
{
str[j+2]=str[j];
}
str[n-i-1]=ment[1];
str[n-i-2]=ment[0];
for(int k=n-4-i;k>=i+1;k--)
{
str[k+1]=str[k];
}
str[i]=ment[1];
str[i+1]=ment[0];
ment[0]++;
if(ment[0]>'9')
{
ment[0]='0';
ment[1]++;
}
}
}
printf("%s",str);
return 0;