int amount=0;
int a1=0,a2=0,a3=0,a4=0,a5=0;
scanf("%d",&amount);
a1=(amount-(amount%50)/50);
amount=amount-a1;
a2=(amount-(amount%20)/20);
amount=amount-a2;
a3=(amount-(amount%10)/10);
amount=amount-a3;
a4=(amount-(amount%5)/5);
amount=amount-a4;
a5=amount;
printf("%d\n%d\n%d\n%d\n%d\n",a1,a2,a3,a4,a5);

