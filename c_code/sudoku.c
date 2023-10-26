//
// Created by 26711 on 2023/10/22.
//
    int boo = 1;
    int suk[9][9];
    int array[9];
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            scanf("%d", &suk[i][j]);
        }
    }
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            for (int k = 8; k > j; k--) {
                if (suk[i][j] == suk[i][k]) {
                    boo = 0;
                    break;
                }
            }
        }
    }
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            for (int k = 8; k > j; k--) {
                if (suk[j][i] == suk[k][i]) {
                    boo = 0;
                    break;
                }
            }
        }
    }
    int a = 0, b = 0, b0 = 0;
    for (int k = 0; k < 9; k++) {
        a = k - (k % 3);
        b = k * 3 - 3 * a;
        b0 = b;
        for (int i = 0; i < 9; i++)
        {
            array[i] = suk[a][b];
            b++;
            if (b % 3 == 0)
            {
                a++;
                b = b0;
            }
        }
        for (int j = 0; j < 9; j++) {
            for (int p = 8; p > j; p--) {
                if (array[j] == array[p]) {
                    boo = 0;
                    break;
                }
            }
        }
    }

    if(boo==1)
    {
        printf("YES");
    }
    else if(boo==0)
    {
        printf("NO");
    }
