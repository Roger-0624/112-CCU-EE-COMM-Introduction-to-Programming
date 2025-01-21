#include <stdio.h>
#include <stdlib.h>

int a[1005];

int GCD(int a, int b)
{
    if(b==0)    //找到了!
    {
        return a;
    }
    return GCD(b, a%b);     //沒找到-->遞迴
}

int main()
{
    int n, r;
    scanf("%d", &n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d", &a[i]);
    }

    if(n==1)
    {
        printf("%d", a[1]);
        return 0;
    }
    
    for(int i=1;i<n;i++)
    {
        a[i+1]=GCD(a[i], a[i+1]);
    }
    printf("%d", a[n]);

    return 0;
}

