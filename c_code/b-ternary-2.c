
{
    int N=1;int i=0;
    scanf("%d",&N);
    char array3[10000][18]={0};
    int t[10000]={0};
    char array10[10000][18];
    int array10n[10000];
    int len10[10000];
    int len3[10000]={0};
    char mid;
    char arrayb3[10000][18];
    int zhengfu[10000]={0};
    for(i=0;i<N;i++)
    {
        scanf("%s", &array10[i][0]);
        array10n[i] = atoi(array10[i]);
        for(int k1=0;k1<strlen(array10[i]);k1++)
        {
            if(k1>0&&array10[i][k1-1]=='0')
            {
                t[i]=0;
                break;
            }
            if(k1==1&&array10[i][k1-1]=='-'&&array10[i][k1]=='0')
            {
                t[i]=0;
                break;
            }
            if(k1==0&&(array10[i][k1]=='1'||array10[i][k1]=='2'||array10[i][k1]=='3'||array10[i][k1]=='4'||array10[i][k1]=='5'||array10[i][k1]=='6'||array10[i][k1]=='7'||array10[i][k1]=='8'||array10[i][k1]=='9'||array10[i][k1]=='-'))
            {
                t[i]=1;
            }
            else if(isdigit(array10[i][k1])!=0)
            {
                t[i]=1;
            }
            else
            {
                t[i]=0;
                break;
            }
        }
        if(atoi(array10[i])<0&&t[i]==1)
        {len10[i] = strlen(array10[i])-1;
            zhengfu[i]=1;}
        else if(atoi(array10[i])>=0&&t[i]==1)
        {len10[i] = strlen(array10[i]);
            zhengfu[i]=0;}
        array10n[i]=fabs(atoi(array10[i]));
    }
    for(int j=0;j<N;j++)
    {
        if(t[j]==1) {
            int a = 0;
            len3[j] = 0;
            while (array10n[j] >= 3) {
                array3[j][a] = (array10n[j] % 3) + 48;
                array10n[j] = (array10n[j] - (array10n[j] % 3)) / 3;
                a++;
                len3[j]++;
            }
            array3[j][a] = array10n[j] + 48;
            len3[j]++;
            array3[j][a + 1] = '0';
            array3[j][a + 2] - '0';
            for (int h = 0; h <= len3[j]; h++) {
                if (array3[j][h] == '2') {
                    array3[j][h] = 'Z';
                    array3[j][h + 1] = array3[j][h + 1] + 1;
                } else if (array3[j][h] == '3') {
                    array3[j][h] = '0';
                    array3[j][h + 1] = array3[j][h + 1] + 1;
                }
            }
            if (array3[j][len3[j]] != '0') {
                for (int k = 0; k <= len3[j]; k++) {
                    arrayb3[j][k] = array3[j][len3[j] - k];
                }
                len3[j]++;
            } else {
                for (int k = 0; k < len3[j]; k++) {
                    arrayb3[j][k] = array3[j][len3[j] - k - 1];
                }
            }
        }
    }
    for(int k=0;k<N;k++)
    {
        if(t[k]==1)
        {
            if(zhengfu[k]==1)
            {
                for(int l=0;l<len3[k];l++)
                {
                    if(arrayb3[k][l]=='1')
                    {
                        arrayb3[k][l]='Z';
                    }
                    else if(arrayb3[k][l]=='Z')
                    {
                        arrayb3[k][l]='1';
                    }
                }
                printf("%s\n",arrayb3[k]);
            }
            else
                printf("%s\n",arrayb3[k]);
        }
        else if(t[k]==0)
            printf("Radix Error\n");
    }
    return 0;
}