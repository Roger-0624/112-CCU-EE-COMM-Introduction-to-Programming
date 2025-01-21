#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, q;
    scanf("%d", &n);
    int *price = (int *)malloc(sizeof(int) * n);
    long long int *sum = (long long *)malloc(sizeof(long long) * (n + 1));
    int i;

    for (i = 0; i < n; i++)
    {
        scanf("%d", price + i);
    }
    
    scanf("%d", &q);
    int a, b;
    *sum = 0;
    for (i = 0; i <= n; i++)
    {
        *(sum + i) = *(sum + i - 1) + *(price + i - 1);
    }
    for (i = 1; i <= q; i++)
    {
        scanf("%d%d", &a, &b);
        printf("%lld\n", *(sum + b) - *(sum + a - 1));
    }
    return 0;
}