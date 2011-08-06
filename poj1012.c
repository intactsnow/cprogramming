#include <stdio.h>

#define N 14

int main()
{
    int k = 0, m = 0;
    int kk = 0;
    int n = 0;
    int result[N] = { 0 };
    while ( scanf("%d", &k), k )
    {
        if ( result[k] )
        {
            printf("%d\n", result[k]);
            continue;
        }
        for ( m = k; ; )
        {
            kk = k + k;
            n = m;
            while ( kk > k )
            {
                if ( ( n %= kk )  < k )
                    break;
                kk--;
                n += m;
            }
            if ( kk > k )
            {
                if ( ( n = m % kk ) < k )
                    m += k - n;
                else
                    m++;
                continue;
            }
            result[k] = m + 1;
            printf("%d\n", result[k]);
            break;
        }
    }
    exit(0);
}
