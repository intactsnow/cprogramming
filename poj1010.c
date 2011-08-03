#include <stdio.h>

#define N 128

int stamp[N] = { 0 }, cstmr[N] = { 0 };
int ans[N][4] = { { 0, 0 } }, ans_len[N] = { 0 }, ans_type[N] = { 0 }, ans_max[N] = { 0 }, ans_tie[N] = { 0 };
int cur[4], cur_len;
int total_stamp = 0, total_cstmr = 0;
int max_req = 0;

int cmp(const void *a, const void *b)
{
    return *((int *)a) - *((int *)b);
}

void dfs(int stamp_num, int stamp_val, int pre_stamp)
{
    if ( stamp_val > max_req )
        return;
    if ( stamp_num > 0 )
    {
        int types = 1;
        int max_val = stamp[cur[0]];
        int min_num = stamp_num;
        int i = 0, j = 0;
        for ( i = 1; i < stamp_num; i++ )
        {
            if ( cur[i] != cur[i-1] )
                types++;
            if ( max_val < stamp[cur[i]] )
                max_val = stamp[cur[i]];
        }
        for ( i = 0; i < total_cstmr; i++ )
        {
            if ( stamp_val == cstmr[i] )
            {
                if ( types > ans_type[i] || ans_type[i] == 0 )
                {
                    ans_type[i] = types;
                    ans_len[i] = min_num;
                    ans_max[i] = max_val;
                    ans_tie[i] = 0;
                    for ( j = 0; j < min_num; j++ )
                        ans[i][j] = cur[j];
                }
                else if ( types == ans_type[i] )
                {
                    if ( min_num < ans_len[i] )
                    {
                        ans_type[i] = types;
                        ans_len[i] = min_num;
                        ans_max[i] = max_val;
                        ans_tie[i] = 0;
                        for ( j = 0; j < min_num; j++ )
                            ans[i][j] = cur[j];
                    }
                    else if ( min_num == ans_len[i] )
                    {
                        if ( max_val > ans_max[i] )
                        {
                            ans_type[i] = types;
                            ans_len[i] = min_num;
                            ans_max[i] = max_val;
                            ans_tie[i] = 0;
                            for ( j = 0; j < min_num; j++ )
                                ans[i][j] = cur[j];
                        }
                        else if ( max_val == ans_max[i] )
                            ans_tie[i] = 1;
                    }
                }
            }
        }
    }
    if ( stamp_num < 4 )
    {
        int i = pre_stamp;
        for ( ; i < total_stamp; i++ )
        {
            cur[stamp_num] = i;
            dfs(stamp_num+1, stamp_val+stamp[i], i);
        }
    }
}

int main()
{
    int num = 0;
    int i = 0, j = 0;
    while ( scanf("%d", &num) == 1 )
    {
        if ( num == 0 )
        {
            while ( scanf("%d", &cstmr[total_cstmr]), cstmr[total_cstmr] )
            {
                if ( max_req < cstmr[total_cstmr] )
                    max_req = cstmr[total_cstmr];
                total_cstmr++;
            }

            qsort(stamp, total_stamp, sizeof(stamp[0]), cmp);
            dfs(0, 0, 0);
            for ( i = 0; i < total_cstmr; i++ )
            {
                if ( ans_len[i] == 0 )
                    printf("%d ---- none\n", cstmr[i]);
                else if ( ans_tie[i] == 1 )
                    printf("%d (%d): tie\n", cstmr[i], ans_type[i]);
                else
                {
                    printf("%d (%d):", cstmr[i], ans_type[i]);
                    for ( j = 0; j < ans_len[i]; j++ )
                        printf(" %d", stamp[ans[i][j]]);
                    printf("\n");
                }
            }
            
            memset(stamp, 0, sizeof(int)*N);
            memset(cstmr, 0, sizeof(int)*N);
            memset(ans, 0, sizeof(int)*N*4);
            memset(ans_type, 0, sizeof(int)*N);
            memset(ans_len, 0, sizeof(int)*N);
            memset(ans_max, 0, sizeof(int)*N);
            memset(ans_tie, 0, sizeof(int)*N);
            total_stamp = total_cstmr = 0;
            max_req = 0;
            continue;
        }
        stamp[total_stamp++] = num;
    }
    exit(0);
}
