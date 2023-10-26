//
// Created by 26711 on 2023/10/16.
//
{
    int n = 0;
    scanf("%d", &n);
    getchar();
    int len10 = 0;
    int p = 0;
    for (int i = 0; i < n; i++)
    {
        char ten[18]={0};
        scanf("%s", &ten[0]);
        len10 = strlen(ten);
        char ter1[20] = {0};
        int t=1;
        int tenn = 0;
        for (int j = 0; j < len10; j++)
        {
            if (j==0&&ten[j]!='-'&&(!isdigit(ten[j])))
            {
                t=0;
                printf("Radix Error\n");
                break;
            }
            if((!isdigit(ten[j]))||ten[j]=='-')
            {
                t=0;
                printf("Radix Error\n");
                break;
            }
        }
        if (ten[0] == '-'&&t==1)
        {
            tenn = 0 - atoi(ten);
            int p = 0;
            do {
                ter1[p] = tenn % 3 + 48;
                tenn = tenn / 3;
                p++;
            } while (tenn);
            ter1[p] = '0';
            for (int t = 0; t < p; t++)
            {
                if (ter1[t] == '2')
                {
                    ter1[t] = 'Z';
                    ter1[t + 1]++;
                }
                else if (ter1[t] == '3')
                {
                    ter1[t] = '0';
                    ter1[t + 1]++;
                }
            }
            if (ter1[p] == '0')
            {
                p--;
            }
            for (int q = p; q >= 0; q--)
            {
                if (ter1[q] == 'Z')
                {
                    ter1[q] = '1';
                }
                else if (ter1[q] == '1')
                {
                    ter1[q] = 'Z';
                }
            }
            for (int h = 0;h<p/2;h++)
            {
                ter1[h]=ter1[h]^ter1[p-h];
                ter1[p-h]=ter1[h]^ter1[p-h];
                ter1[h]=ter1[h]^ter1[p-h];
            }

            printf("%s\n",ter1);
        }
        else if(ten[0] != '-'&&t==1)
        {
            tenn = atoi(ten);
            p = 0;
            do {
                ter1[p] = tenn % 3 + 48;
                tenn = tenn / 3;
                p++;
            } while (tenn);
            ter1[p] = '0';
            for (int t = 0; t < p; t++)
            {
                if (ter1[t] == '2')
                {
                    ter1[t] = 'Z';
                    ter1[t + 1]++;
                }
                else if (ter1[t] == '3')
                {
                    ter1[t] = '0';
                    ter1[t + 1]++;
                }
            }
            if (ter1[p] == '0')
            {
                p--;
            }
            for (int h = 0;h<p/2;h++)
            {
                ter1[h]=ter1[h]^ter1[p-h];
                ter1[p-h]=ter1[h]^ter1[p-h];
                ter1[h]=ter1[h]^ter1[p-h];
            }
            printf("%s\n",ter1);
        }
    }
    return 0;
}