#include <stdio.h>
#include <stdlib.h>

#define MAX_LEN 55

int part[MAX_LEN];
int temp[MAX_LEN];
int min_stick_len;

int dfs(int len_for_stick, int cur_max_part, int remain_sticks, int total_len_left)
{
    if ( remain_sticks == 0 )
        return 1;
        
    if ( len_for_stick == 0 )
        return dfs( min_stick_len, min_stick_len, remain_sticks - 1, total_len_left);
        
    if ( min_stick_len >= MAX_LEN )
        min_stick_len = MAX_LEN - 1;
        
    if ( cur_max_part > len_for_stick )
        cur_max_part = len_for_stick;
    while ( temp[cur_max_part] == 0 && cur_max_part > 0 )
        cur_max_part--;
    if ( cur_max_part == 0 )
        return 0;
        
    if ( len_for_stick == min_stick_len )
    {
        temp[cur_max_part]--;
        if ( dfs(len_for_stick - cur_max_part, cur_max_part, remain_sticks, total_len_left) )
            return 1;
        temp[cur_max_part]++;
        return 0;
    }
    
    if ( cur_max_part <= len_for_stick )
    {
        for ( ; cur_max_part > 0 && total_len_left >= len_for_stick; total_len_left -= temp[cur_max_part] * cur_max_part, cur_max_part-- )
        {
            if ( temp[cur_max_part] > 0 )
            {
                temp[cur_max_part]--;
                if ( dfs(len_for_stick - cur_max_part, cur_max_part, remain_sticks, total_len_left) )
                    return 1;
                temp[cur_max_part]++;
            }
        }
        return 0;
    }
}

int main()
{
    int num_of_part = 0;
    int len_of_part = 0;
    int total_len   = 0;
    int max_part    = 0;
    
    while ( scanf("%d", &num_of_part) == 1 )
    {
        if ( num_of_part == 0 )
            break;

        memset(part, 0, MAX_LEN * sizeof(int));
        total_len = max_part = 0;
        
        while ( num_of_part-- )
        {
            scanf("%d", &len_of_part);
            total_len += len_of_part;
            if ( len_of_part > max_part )
                max_part = len_of_part;
            part[len_of_part]++;
        }
        
        for ( min_stick_len = max_part; min_stick_len <= total_len; min_stick_len++ )
        {
            if ( total_len % min_stick_len == 0 )
            {
                memcpy(temp, part, MAX_LEN * sizeof(int));
                if ( dfs(min_stick_len, min_stick_len, total_len/min_stick_len, total_len) )
                    break;
            }
        }
        printf("%d\n", min_stick_len);
    }
    exit(0);
}

//#include <stdio.h>
//#include <stdlib.h>
//
//#define N 55
//
//int stick[N],t[N],a;
//
//// 深搜（ 还需的长度, 之后的最长长度, 倒数第几根, 剩余棍子总长）;
////返回 1 为深搜失败, 0 为成功.
//int dfs( int len, int k, int rem, int left) {
//    if( rem==0 )   return 0;
//    if( len==0 )   return dfs(a,a,rem-1,left);
//   	if( k>=N )     k=N-1;
//    if( k>len )    k=len;
//    if( t[k]==0 )
//        while( k>0 && t[--k]==0 );
//    if( k==0 )	return 1;
//    if( len==a ) {
//        t[k]--;
//        if( dfs(len-k,k,rem,left)==0 ) return 0;
//        t[k]++;
//        return 1;
//    }
//    if( k<=len ) {
//        for( ; k>0 && left>=len ; left-= t[k]*k,k--)
//			if( t[k]>0 ) {
//				t[k]--;
//                if( dfs(len-k,k,rem,left)==0 ) return 0;
//				t[k]++;
//			}
//		return 1;
//    }/* Core above */
//}
//
//int main()
//{
//    int i,k,n,sum;
//    while( scanf("%d",&n), n ) {
//        memset( stick, 0, N*sizeof(int) );
//        for( sum=k=0; n--; ) {
//            scanf("%d",&i);
//            stick[i]++;
//            if( i>k ) k=i;
//            sum +=i;
//        }
//		for( a=k; a<=sum; a++ )
//            if( sum%a==0 ) {
//                for( i=0; i<N; i++)
//                    t[i]=stick[i];
//				if( dfs(a,a,sum/a,sum)==0 )
//                    break;
//            }
//		printf("%d\n",a);
//    }
//    system("PAUSE");
//    return 0;
//}
