#include <stdio.h>

#define S 6

int main()
{
    int packet[S+1] = { 0 };
    int parcel = 0, rest = 0;
    int i = 0;
    while ( scanf("%d %d %d %d %d %d", &packet[1], &packet[2], &packet[3], &packet[4], &packet[5], &packet[6]) == 6 )
    {
        if ( packet[1] == 0 && packet[2] == 0 && packet[3] == 0 && packet[4] == 0 && packet[5] == 0 && packet[6] == 0 )
            break;

        parcel = packet[6] + packet[5] + packet[4] + ( packet[3] + 3 ) / 4 ;
        rest = packet[4] * 5 + ( ( 3 - packet[3] % 4 ) * 2 + 1 ) % 7;
        if ( packet[2] > rest )
            parcel += ( packet[2] - rest + 8 ) / 9;
        rest = 36 * ( parcel - packet[6] ) - 25 * packet[5] - 16 * packet[4] - 9 * packet[3] - 4 * packet[2];
        if ( packet[1] > rest )
            parcel += ( packet[1] - rest + 35 ) / 36;
        printf("%d\n", parcel);
    }
    exit(0);
}
