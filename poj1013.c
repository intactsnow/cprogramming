#include <stdio.h>

#define W 3
#define D 7
#define M 12

int main()
{
    int n = 0;
    char weighing[W*2+1][W+1][D];
    int coin[M] = { 0 };
    int i = 0, j = 0, k = 0, p = 0;
    int str_len = 0;
    int heavy = 0, light = 0;

    scanf("%d", &n);
    while ( n-- )
    {
        memset(coin, 0, sizeof(int)*M);
        for ( i = 0; i < W; i++ )
        {
            for ( j = 0; j < W; j++ )
                scanf("%s", weighing[i][j]);
            str_len = strlen(weighing[i][0]);
            if ( strcmp(weighing[i][2], "up") == 0 )
            {
                for ( k = 0; k < str_len; k++ )
                    if ( coin[weighing[i][0][k]-'A'] != 4 )
                        coin[weighing[i][0][k]-'A']++;
                for ( k = 0; k < str_len; k++ )
                    if ( coin[weighing[i][1][k]-'A'] != 4 )
                        coin[weighing[i][1][k]-'A']--;
            }
            else if ( strcmp(weighing[i][2], "down") == 0 )
            {
                for ( k = 0; k < str_len; k++ )
                    if ( coin[weighing[i][0][k]-'A'] != 4 )
                        coin[weighing[i][0][k]-'A']--;
                for ( k = 0; k < str_len; k++ )
                    if ( coin[weighing[i][1][k]-'A'] != 4 )
                        coin[weighing[i][1][k]-'A']++;
            }
            else
                for ( k = 0; k < str_len; k++ )
                {
                    coin[weighing[i][0][k]-'A'] = 4;
                    coin[weighing[i][1][k]-'A'] = 4;
                }
        }
        /*
        for ( i = 0; i < M; i++ )
            printf("%d ", coin[i]);
        printf("\n");
        */
        heavy = light = 0;
        for ( i = 0; i < M; i++ )
        {
            if ( coin[i] == 4 )
                coin[i] = 0;
            if ( coin[heavy] < coin[i] )
                heavy = i;
            if ( coin[light] > coin[i] )
                light = i;
        }
        if ( coin[heavy] + coin[light] > 0 )
            printf("%c is the counterfeit coin and it is heavy.\n", 'A'+heavy);
        else
            printf("%c is the counterfeit coin and it is light.\n", 'A'+light);
    }
    exit(0);
}
