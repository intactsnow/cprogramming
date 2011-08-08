#include <stdio.h>

#define LEN 100
#define ITR 15

void inventory(const char *n, char *r)
{
    int m[10] = { 0 };
    int i = 0, t = 0;
    
    int len = strlen(n);
    for ( i = 0; i < len; i++ )
        m[n[i]-'0']++;

    memset(r, 0, LEN);
    for ( i = 0; i < 10; i++ )
    {
        if ( len <= 0 )
            break;
        if ( m[i] == 0 )
            continue;
        sprintf(r+t, "%d%d", m[i], i);
        t = strlen(r);
        len -= m[i];
    }
}

int main()
{
    char n[ITR][LEN];
    int m[10] = { 0 };
    int j = 0, k = 0;
    int i = 0, t = 0;
    
    while ( scanf("%s", n[0]), strcmp(n[0], "-1") )
    {
        int none = 1;
        for ( j = 0; j < ITR; j++ )
        {
            if ( !none )
                break;
            inventory(n[j], n[j+1]);
            if ( strcmp(n[j], n[j+1]) == 0 )
            {
                if ( j == 0 )
                    printf("%s is self-inventorying \n", n[0]);
                else
                    printf("%s is self-inventorying after %d steps \n", n[0], j);
                none = 0;
                break;
            }
            for ( k = 2; k <= j + 1; k++ )
                if ( strcmp(n[j+1-k], n[j+1]) == 0 )
                {
                    printf("%s enters an inventory loop of length %d \n", n[0], k);
                    none = 0;
                    break;
                }
        }
        if ( none )
            printf("%s can not be classified after 15 iterations\n", n[0]);

        memset(n, 0, LEN*ITR);
    }
    exit(0);
}
