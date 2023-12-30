//
// Created by 26711 on 2023/10/8.
//
int n=0;
long double x;
scanf("%Lf %d",&x,&n);
double temp1;
double r=4.0;
long double sum;
for (int i = 0; i <= n; i++)
{
temp1=(pow(-1, i)*pow(x,2*i+1))/(2*i+1);
sum=sum+temp1;
}
printf("%.10Lf",sum*r);