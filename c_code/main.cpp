#include <stdio.h>
#include <stdbool.h>
int main()
{
    int n=0,m=0;
    char map[100][100];
    int x0=0,y0=0;
    scanf("%d%d%d%d",&n,&m,&x0,&y0);
    int ans=0;
    getchar();
    int vec[4][2]={{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            scanf("%c",&map[i][j]);
        }
        getchar();
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(map[i][j]=='#')
            {
                ans++;
            }
        }
    }
    int ansx[100];
    int ansy[100];
    int rest[100][2];
    ansx[0]=x0-1;
    ansy[0]=y0-1;
    rest[0][0]=x0;
    rest[0][1]=y0;
    bool vis[100][100]={0};
    vis[ansx[0]][ansy[0]]=1;
    for(int i=1;i<ans;i++)
    {
        for(int k=0;k<4;k++)
        {
            ansx[i]=ansx[i-1]+vec[k][0];
            ansy[i]=ansy[i-1]+vec[k][1];
            if(ansx[i]>=0&&ansx[i]<=n&&ansy[i]>=0&&ansy[i]<=m)
            {
                if(vis[ansx[i]][ansy[i]]==0&&map[ansx[i]][ansy[i]]=='#')
                {
                    rest[i][0]=ansx[i]+1;
                    rest[i][1]=ansy[i]+1;
                    vis[ansx[i]][ansy[i]]=1;
                    break;
                }
            }
        }
    }
    printf("%d\n",ans);
    for(int i=0;i<ans;i++)
    {
        printf("%d %d\n",rest[i][0],rest[i][1]);
    }
    return 0;
}
