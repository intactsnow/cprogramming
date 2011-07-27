#include <stdio.h>

int main()
{
    int pp = 28*33*6;
    int ee = 23*33*19;
    int ii = 23*28*2;
    int pei = 23*28*33;
    
    int p = 0, e = 0, i = 0, d = 0;
    int n = 0;
    
    while ( scanf("%d %d %d %d", &p, &e, &i, &d) == 4 )
    {
        if ( p == -1 && e == -1 && i == -1 && d == -1 )
            break;
        n++;
        int days = pp * p + ee * e + ii * i;
        while ( days > d )
            days -= pei;
        days += pei;
        printf("Case %d: the next triple peak occurs in %d days.\n", n, days-d);
    }

    exit(0);
}
