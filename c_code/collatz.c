//
// Created by 26711 on 2023/10/8.
//
#include <stdio.h>
#include<stdlib.h>
#include <math.h>
#include<assert.h>
#include <stdio.h>
    int n=0;
    int count=0;
    int temp=0;
    scanf("%d",&n);
    while(n!=1)
    {
        if(n>=temp)
            temp=n;
        else;
        if(n%2==0)
        {
            n=n/2;
            count++;
        }
        else
        {
            n=n*3+1;
            count++;
        }

    }
    printf("%d %d",count,temp);
