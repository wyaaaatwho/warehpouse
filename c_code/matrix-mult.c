//
// Created by 26711 on 2023/10/22.
//
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>
    int m=0,n=0,p=0;
    scanf("%d%d%d",&m,&n,&p);
    int m1[105][105];
    int m2[105][105];
    int rst[105][105];
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            scanf("%d",&m1[i][j]);
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<p;j++)
        {
            scanf("%d",&m2[i][j]);
        }
    }
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<p;j++)
        {
            for(int k=0;k<n;k++)
            {
                rst[i][j]=rst[i][j]+m1[i][k]*m2[k][j];
            }
        }
    }
    for(int t=0;t<m;t++)
    {
        for(int q=0;q<p;q++)
        {
            printf("%d ",rst[t][q]);
        }
        printf("\n");
    }
