#include <stdio.h>
#include <stdlib.h>

int main()
{
   int n, q;
    scanf("%d", &n);
    int price[n];
    for(int i=0;i<=n-1;i++)
    {
        scanf("%d", &price[i]);
    }
    scanf("%d", &q);
    int a, b;
    long long sum[n+1];
    sum[0]=0;
    for(int i=0;i<=n;i++)
    {
        sum[i]=sum[i-1]+price[i-1];
    }
    for(int i=1;i<=q;i++)
    {
        scanf("%d%d", &a, &b);
        printf("%lld\n", sum[b]-sum[a-1]);
    }
    return 0;
}
