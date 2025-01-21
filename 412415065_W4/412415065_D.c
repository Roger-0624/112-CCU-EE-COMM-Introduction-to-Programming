#include <stdio.h>
#include <stdlib.h>

int n, k;
int SAO[18];

void C8763(int count, int num)
{
    // printf("count %lld %lld\n", count, num);
    if(num>=10 || num<0) 
    {
        return;
    }

    SAO[count]=num;

    if(count==n)
    {
        for(int i=1;i<=n;i++)
        {
            printf("%d", SAO[i]);
        }
        printf("\n");
        return;
    }
    C8763(count+1, num+k);
    C8763(count+1, num-k);
}

int main()
{
    // int n, k;
    scanf("%d%d", &n, &k);
    for(int i=1;i<=9;i++)
    {
        C8763(1,i);
    }
    
    return 0;
}
