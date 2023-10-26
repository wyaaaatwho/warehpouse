    int N=1;int i=0;
    scanf("%d",&N);
    int t[10000]={1};
    int array[10000]={0};
    int len[10000];
    char str[10000][16];
    for(i=0;i<N;i++)
    {
        scanf("%s",&str[i][0]);
        len[i]=strlen(str[i]);
    }

    for(int a=0;a<N;a++)
    {
        for(int b=0;b<len[a];b++)
        {
            if (str[a][b] == '1')
            {
                array[a] = array[a] + pow(3, len[a] - 1 - b);
                t[a] = 1;
            }
            else if (str[a][b] == 'Z')
            {
                array[a] = (array[a] - pow(3, len[a] - 1 - b));
                t[a] = 1;
            }
            else if (str[a][b] == '0')
            {
                array[a] = array[a];
                t[a] = 1;
            } else
            {
                array[a] = array[a];
                t[a] = 0;
                break;
            }
        }
    }
    for(int c=0;c<N;c++)
    {
        if(t[c]==1)
        {
            printf("%d\n",array[c]);
        }
        else
        {
            printf("Radix Error\n");
        }
    }
