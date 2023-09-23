
char month [10];
char weekday [10];
int day,year,hour,minute,second;
scanf("%s%d%d%s%d%d%d",&month,&day,&year,&weekday,&hour,&minute,&second);
printf("%c%c%c %c%c%c %02d %02d:%02d:%02d %04d",weekday[0],weekday[1],weekday[2],month[0],month[1],month[2],day,hour,minute,second,year);