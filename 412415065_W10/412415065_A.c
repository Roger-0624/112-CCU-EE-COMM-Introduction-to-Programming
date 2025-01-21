#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main()
{
    long long x1, y1, x2, y2, x3, y3, area;
    scanf("%lld %lld %lld %lld %lld %lld", &x1, &y1, &x2, &y2, &x3, &y3);
    area=((x1*y2+ x2*y3+x3*y1)-(y1*x2+y2*x3+y3*x1));
    if(area<0)
    {
        area=0-area;
    }
    if(area%2==1)
    {
        area=area/2+1;
    }
    else
    {
        area=area/2;
    }
    printf("%lld", area);
    return 0;
}