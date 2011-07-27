#include <stdio.h>

int main()
{
    float PI = 3.14;
    int N = 0;
    float X = 0.0, Y = 0.0;
    int year = 0;
    int i = 0;
    
    scanf("%d", &N);
    for ( i = 1; i <= N; i++ )
    {
        scanf("%f %f", &X, &Y);
        year = (int)(1.0 / 2.0 * PI * ( X * X + Y * Y ) / 50.0);
        printf("Property %d: This property will begin eroding in year %d.\n", i, year+1);
    }
    printf("END OF OUTPUT.\n");
    
    system("PAUSE");
    exit(0);
}
