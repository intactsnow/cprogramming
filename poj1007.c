#include <stdio.h>

#define MAX_N 51
#define MAX_M 101

int unsortedness(char *s, int len)
{
    int i = 0;
    int c[4] = {0};
    int cnt = 0;
    for ( i = len - 1; i >= 0; i-- )
    {
        switch(s[i])
        {
            case 'A':
                c[1]++;
                c[2]++;
                c[3]++;
                break;
            case 'C':
                c[2]++;
                c[3]++;
                cnt += c[1];
                break;
            case 'G':
                c[3]++;
                cnt += c[2];
                break;
            case 'T':
                cnt += c[3];
                break;
        }
    }
    return cnt;
}

int main()
{
    int n = 0, m = 0;
    char str[MAX_M][MAX_N];
    int sort[MAX_M], ptr[MAX_M];
    int i = 0, j = 0;
    int tmp = 0;
    
    while ( scanf("%d %d", &n, &m) == 2 )
    {
        for ( i = 0; i < m; i++ )
        {
            scanf("%s", str[i]);
            sort[i] = unsortedness(str[i], n);
            ptr[i] = i;
        }
        for ( i = 0; i < m - 1; i++ )
        {
            for ( j = i + 1; j < m; j++ )
            {
                if ( sort[ptr[i]] > sort[ptr[j]] )
                {
                    tmp = ptr[i];
                    ptr[i] = ptr[j];
                    ptr[j] = tmp;
                }
            }
        }
        for ( i = 0; i < m; i++ )
            printf("%s\n", str[ptr[i]]);
    }
    exit(0);
}
