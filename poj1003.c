#include <stdio.h>

int main()
{
    float c = 0;
    int n = 0;
    float length = 0;
    
    while ( scanf("%f", &c) == 1 )
    {
        if ( c == 0.00 )
            break;
        length = 0.0;
        n = 0;
        while ( length <= c )
        {
            n++;
            length += 1.0 / ( n + 1 );
        }
        printf("%d card(s)\n", n);
    }
    
    system("PAUSE");
    exit(0);
}
