#include <stdio.h>
#include <math.h>

#define N 1001

int input[N][2] = { 0 };
int output[N*9][2] = { 0 };
int n = 0;
int width = 0, height = 0;

int cmp(const void *a, const void *b)
{
    int aa[2], bb[2];
    memcpy(aa, a, sizeof(int)*2);
    memcpy(bb, b, sizeof(int)*2);
    return aa[1] - bb[1];
}

int get_val(int index)
{
    int low = 0, high = n - 1;
    int mid = 0;
    while ( low <= high )
    {
        mid = ( low + high ) / 2;
        if ( input[mid][1] <= index )
            low = mid + 1;
        else
            high = mid - 1;
    }
    return input[high][0];
}

int max_abs(int index)
{
    int max = 0;
    int row = index / width;
    int col = index % width;
    int i = 0, j = 0;
    int p = 0, q = 0;
    for ( i = row - 1; i <= row + 1; i++ )
        for ( j = col - 1; j <= col + 1; j++ )
        {
            if ( i < 0 || i >= height || j < 0 || j >= width )
                continue;
            p = i * width + j;
            if ( p == index )
                continue;
            q = abs( get_val(p) - get_val(index) );
            if ( q > max )
                max = q;
        }
    return max;
}

int main()
{
    int pixel = 0, length = 0;
    int total = 0, count = 0;
    int i = 0, j = 0, k = 0;
    int r = 0, c = 0, p = 0;
    
    while ( scanf("%d", &width), width )
    {
        n = 0;
        total = 0;
        memset(input, 0, sizeof(int)*N*2);
        while ( scanf("%d %d", &input[n][0], &length), input[n][0], length )
        {
            input[n][1] = total;
            total += length;
            n++;
        }
        
        height = total / width;
        count = 0;
        for ( i = 0; i <= n; i++ )
        {
            r = input[i][1] / width;
            c = input[i][1] % width;
            for ( j = r-1; j <= r+1; j++ )
                for ( k = c-1; k <= c+1; k++ )
                {
                    if ( j < 0 || j >= height || k < 0 || k >= width )
                        continue;
                    p = j * width + k;
                    output[count][0] = max_abs(p);
                    output[count][1] = p;
                    count++;
                }
        }
        
        qsort(output, count, sizeof(int)*2, cmp);
        
        printf("%d\n", width);
        for ( i = 0, j = 0; i < count; i++ )
        {
            if ( output[i][0] == output[j][0] )
                continue;
            printf("%d %d\n", output[j][0], output[i][1] - output[j][1]);
            j = i;
        }
        printf("%d %d\n", output[j][0], total - output[j][1]);
        printf("0 0\n");
    }
    
    printf("0\n");
    exit(0);
}
