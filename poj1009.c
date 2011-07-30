#include <stdio.h>

int main()
{
    int width = 0;
    int pixel = 0, length = 0;
    int i = 0, j = 0;
    
    while ( scanf("%d", &width) == 1 )
    {
        if ( width == 0 )
            break;
        while ( scanf("%d %d", &pixel, length) == 2 )
        {
            if ( pixel == 0 && length == 0 )
                break;

        }
    }
    exit(0);
}
