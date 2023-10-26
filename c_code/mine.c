//
// Created by 26711 on 2023/10/22.
//
int n=0;
scanf("%d",&n);
char str[100][100];
int a=0,b=0;
for(int i=0;i<n;i++)
{
scanf("%s",&str[i][0]);
}
char rest[100][100];
int count[100][100]={0};
int vec[8][2]={{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};
for(int i=0;i<n;i++)
{
for(int j=0;j<n;j++)
{
if (str[i][j]=='*')
{
rest[i][j]='*';
}
else
{
for(int k=0;k<8;k++)
{
int ni=0,nj=0;
ni=i+vec[k][0];
nj=j+vec[k][1];
if(ni<=n&&ni>=0&&nj<=n&&nj>=0)
{
if(str[ni][nj]=='*')
{
count[i][j]++;
}
}
}
rest[i][j]=count[i][j]+48;
}
}
}
for(int i=0;i<n;i++)
{
printf("%s\n",rest[i]);
}
return 0;