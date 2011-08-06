#include <stdio.h>

#define MAX_V 60001
#define N 7

int f[MAX_V];
int V = MAX_V / 2;

void ZeroOnePack(int cost/*, int weight*/)
{
    int i = 0;
    for ( i = V; i >= cost; i-- )
        f[i] = f[i] > ( f[i-cost] + cost/*(weight)*/ ) ? f[i] : ( f[i-cost] + cost/*(weight)*/ );
}

void CompletePack(int cost/*, int weight*/)
{
    int i = 0;
    for ( i = cost; i <= V; i++ )
        f[i] = f[i] > ( f[i-cost] + cost/*(weight)*/ ) ? f[i] : ( f[i-cost] + cost/*(weight)*/ );
}

void MultiplePack(int cost/*, int weight*/, int amount)
{
    if ( cost * amount >= V )
        CompletePack(cost/*, weight*/);
    else
    {
        int k = 1;
        while ( k < amount )
        {
            ZeroOnePack(k*cost/*, k*weight*/);
            amount -= k;
            k *= 2;
        }
        ZeroOnePack(amount*cost/*, amount*weight*/);
    }
}

int main()
{
    int marble[N] = { 0 };
    int i = 0, j = 0;
    for ( j = 1; ; j++ )
    {
        marble[0] = 0;
        V = 0;
        for ( i = 1; i < N; i++ )
            if ( scanf("%d", &marble[i]), marble[i] != 0 )
                marble[0] = 1;
        if ( !marble[0] )
            break;
            
        printf("Collection #%d:\n", j);
        for ( i = 1; i < N; i++ )
            V += marble[i] * i;
        if ( V % 2 )
        {
            printf("Can't be divided.\n\n");
            continue;
        }
        V /= 2;
        f[0] = 0;
        for ( i = 1; i <= V; i++ )
            f[i] = -1;
        for ( i = 1; i < N; i++ )
            MultiplePack(i/*, i*/, marble[i]);
        if ( f[V] == V )
            printf("Can be divided.\n\n");
        else
            printf("Can't be divided.\n\n");
    }
    
    exit(0);
}
