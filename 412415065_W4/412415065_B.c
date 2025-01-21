#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, ans, marble;
    scanf("%d", &n);
    marble=n;
    ans=n;
    while(marble>=3)
    {
        ans=ans+marble/3;
        marble=marble/3+marble%3;
    }
    printf("%d", ans);
    return 0;
}