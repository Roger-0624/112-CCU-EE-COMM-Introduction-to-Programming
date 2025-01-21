#include <stdio.h>
#include <math.h>

int main() {
    long long x, y, r;
    scanf("%lld %lld %lld ", &x, &y, &r);

    long long a, b;
    scanf("%lld %lld", &a, &b);

    if (llabs(x - a) * llabs(x - a) + llabs(y - b) * llabs(y - b) <= r * r)
        printf("Yes\n");
    else 
        printf("No\n");
    
    return 0;
}