#include <stdio.h>
#include<stdlib.h>
#include <math.h>
        int main()
        {
            int p_1=0,q_1=0;
            float x1=0.;
            scanf("%d %d",&p_1,&q_1);
            float q,p;
            q=q_1;
            p=p_1;
            float del=sqrt(pow(q/2,2)+pow(p/3,3));
            x1 = cbrt(del-q/2)+cbrt(-del-q/2);
            printf("%.3f",x1);
            return 0;
        }