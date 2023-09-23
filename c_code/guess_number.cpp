#include <stdio.h>
#include<stdlib.h>
#include<time.h>
int guess_number ()
{
    srand((unsigned)time(NULL));
    int a=rand()%101;
    int b = 101;
    printf("please input a number\n");
    while(a!=b)
    {
        scanf("%d",&b);
        if (a==b)
        {
            printf("your're right!\n");
        }
        if(a>b)
        {
            printf("too small\n");
        }
        if(a<b)
        {
            printf("too big\n");
        }
    }
}
