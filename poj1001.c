#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define R_WIDTH 6
#define N_WIDTH 2
#define MAX_N   25

int S_WIDTH = 0;
int INT_NUM = 0;
int INT_POW = 0;

void multiply(int *r, int *n, int *s)
{
    int i = 0, j = 0, k = 0;
    int carry = 0;
    long long tmp = 0;
    for ( i = INT_NUM - 1; i >= 0; i-- )
    {  
        tmp = 0;
        for ( j = i, k = INT_NUM-1; j < INT_NUM; j++, k-- )
            tmp += (long long)r[j] * (long long)n[k];
        tmp += (long long)carry;
        s[i]  = (int)(tmp % INT_POW);
        carry = (int)(tmp / INT_POW);
    }
}

int main()
{
    int S_WIDTH = ( R_WIDTH - 1 ) * MAX_N;
    int INT_NUM = S_WIDTH / sizeof(int) + 1;
    int INT_POW = (int)pow(10.0, (float)sizeof(int));

    int i = 0, j = 0;
    
    int ir[INT_NUM], is[INT_NUM], it[INT_NUM];
    char cr[R_WIDTH];
	int slength = INT_NUM * sizeof(int);
	char cs[slength];
	int r = 0;
    int n = 1;
    int point = 0;
    while ( scanf("%s %d", cr, &n) == 2 )
    {
        for ( i = 0; i < INT_NUM; i++ )
        {
            ir[i] = 0;
            is[i] = 0;
            it[i] = 0;
        }
        
        for ( i = R_WIDTH-1; i >= 0; i-- )
            if ( cr[i] == '.' )
                 break;
        point = R_WIDTH - 1 - i;
        point *= n;
		point = slength - point;
        for ( ; i > 0; i-- )
            cr[i] = cr[i-1];
        cr[i] = '0';
        
        r = atoi(cr);
        is[INT_NUM-1] = it[INT_NUM-1] = ir[INT_NUM-1] = r % INT_POW;
        is[INT_NUM-2] = it[INT_NUM-2] = ir[INT_NUM-2] = r / INT_POW;
        for ( i = 1; i < n; i++ )
        {
            multiply(it, ir, is);
            memcpy(it, is, sizeof(int)*INT_NUM);
        }
        
		char tmp[sizeof(int)];
		int off = 0;
		for ( i = 0; i < INT_NUM; i++ )
		{
			sprintf(tmp, "%04d", is[i]);
			memcpy(cs+off, tmp, sizeof(int));
			off += sizeof(int);
		}
		
		j = slength - 1;
		while ( cs[j] == '0' )
			j--;
		int last = ( j+1 < point ) ? point : j+1;
		i = 0;
		while ( cs[i] == '0' && i < point )
			i++;
		for ( ; i < last; i++ )
		{
			if ( i == point )
				printf(".");
			printf("%c", cs[i]);
		}
		printf("\n");
    }
    exit(0);
}
    
