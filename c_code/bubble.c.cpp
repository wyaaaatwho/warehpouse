//
// Created by 26711 on 2023/10/15.
//
int n;
scanf("%d", &n);

for (int i = 0; i < n; i++)
{
int len, tf = 0;
scanf("%d", &len);
int array[len];

for (int j = 0; j < len; j++)
{
scanf("%d", &array[j]);
}

for (int j = 0; j < len - 1; j++)
{
if (array[j] > array[len - 1])
{
tf = 1;
break;
}
}
if (tf)
{
printf("No\n");
} else
{
printf("Yes\n");
}
}
