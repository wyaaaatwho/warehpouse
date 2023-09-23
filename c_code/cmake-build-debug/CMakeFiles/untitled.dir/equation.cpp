int p_1=0,q_1=0;
float x1=0.0;
scanf("%d %d",&p_1,&q_1);
float q,p;
q=q_1;
p=p_1;
int b=1.0/3;
float del=sqrt((q/2)*(q/2)+(p/3)*(p/3)*(p/3));
x1 = pow((del-(q/2)),(1/3))+pow((0-del-(q/2)),(1/3));
float p1=pow((del-(q/2)),b);
float p2=pow((0-del-(q/2)),b);
printf("%.3f",x1);

