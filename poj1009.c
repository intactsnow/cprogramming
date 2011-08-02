#include <stdio.h>
#include <math.h>

#define N 1001

int input[N][2] = { 0 };
int n = 0;

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

int main()
{
    int width = 0, height = 0;
    int pixel = 0, length = 0;
    int total = 0;
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
        for ( i = 0; i <= n; i++ )
        {
            int max = 0;
            r = input[i][1] / width;
            c = input[i][1] % width;
            for ( j = r-1; j <= r+1; j++ )
                for ( k = c-1; k <= c+1; k++ )
                {
                    if ( j < 0 || j >= height || k < 0 || k >= width )
                        continue;
                    p = j * width + k;
                    int tmp = abs( get_val(p) - input[i][0] );
                    if ( tmp > max )
                        max = tmp;
                }
            printf("%d %d\n", max, input[i][1]);
        }
//        printf("%d\n", n);
//        for ( j = 0; j < i; j++ )
//            printf("%d, %d\n", input[j][0], input[j][1]);
    }
    
    exit(0);
}
