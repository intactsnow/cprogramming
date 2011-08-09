#include <stdio.h>

#define MAX_N 10
#define MAX_L (16*10)

int s = 0, p = 0;
int n[MAX_N+1] = { 0 };
int rows[MAX_L+1] = { 0 };

int dfs(int num)
{
    if ( num == p )
        return 1;
    int i = 0, j = 0;
    int min_rows = MAX_L, cur_col = -1;
    int ok = 1;
    for ( i = 0; i < s; i++ )
        if ( rows[i] < min_rows )
        {
            min_rows = rows[i];
            cur_col = i;
        }
    for ( i = MAX_N; i > 0; i-- )
    {
        if ( n[i] > 0 && min_rows+i-1 < s && cur_col+i-1 < s )
        {
            ok = 1;
            for ( j = cur_col; j < cur_col+i; j++ )
                if ( rows[j] > min_rows )
                {
                    ok = 0;
                    break;
                }
            if ( ok )
            {
                for ( j = cur_col; j < cur_col+i; j++ )
                    rows[j] += i;
                n[i]--;
                if ( dfs(num+1) )
                    return 1;
                n[i]++;
                for ( j = cur_col; j < cur_col+i; j++ )
                    rows[j] -= i;
            }
        }
    }
    return 0;
}

int main()
{
    int t = 0;
    int i = 0;
    int sum = 0;
    scanf("%d", &t);
    while ( t-- )
    {
        scanf("%d %d", &s, &p);
        
        sum = 0;
        memset(n, 0, sizeof(int)*(MAX_N+1));
        memset(rows, 0, sizeof(int)*(MAX_L+1));
        
        for ( i = 0; i < p; i++ )
        {
            scanf("%d", &n[0]);
            sum += n[0] * n[0];
            n[n[0]]++;
        }
        
        if ( sum != s*s )
            printf("HUTUTU!\n");
        else if ( dfs(0) )
            printf("KHOOOOB!\n");
        else
            printf("HUTUTU!\n");
    }
    system("PAUSE");
    exit(0);
}
