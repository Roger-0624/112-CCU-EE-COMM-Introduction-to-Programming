#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, q, i;
    scanf("%d", &n);
    int price[n];
    for(i=0;i<=n-1;i++)
    {
        scanf("%d", &price[i]);
    }
    scanf("%d", &q);
    int a, b; 
    long long sum=0;
    for(int ii=1;ii<=q;ii++)
    {
        sum=0;
        scanf("%d%d", &a, &b);
        for(int j=a-1;j<=b-1;j++)
        {
            sum=sum+price[j];
        }
        printf("%lld\n", sum);
    }
    return 0;
}
