#include <stdio.h>
int arrayMax (int n,int ages[]);
int ()
{  int b;
    scanf("%d",&b);
    int inputs[b];
    for(int j=0;j<=b-1;j++)
    {
        scanf("%d",&inputs[j]);
    }
    arrayMax (b,inputs);
    printf("%d",(sizeof(inputs)/sizeof(int)));
    return 666;
}
int arrayMax (int n,int ages[])
{
    int i=0;
    while(i<=(n-2))
    {
        if (ages[i]<=ages[i+1])
        {
            ;
        }
        else
        {
            ages[i+1]=ages[i];
        }
        i++;
    }
    printf("%d\n",ages[i]);
    printf("%d\n",i);
    printf("%d\n",n);
    return 0;
}
