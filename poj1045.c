#include <stdio.h>
#include <math.h>

int main()
{
    float vs = 0.0, r = 0.0, c = 0.0;
    int n = 0;
    float w = 0.0, vr = 0.0, t = 0.0;
    scanf("%f %f %f %d", &vs, &r, &c, &n);
    while ( n-- )
    {
        scanf("%f", &w);
        t = c*r*w;
        vr = t*vs / sqrt(1+t*t);
        printf("%.3f\n", vr);
    }
//    system("PAUSE");
    exit(0);
}
