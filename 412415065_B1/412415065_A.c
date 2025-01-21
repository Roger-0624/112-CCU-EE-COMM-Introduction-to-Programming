#include<stdio.h>
#include<stdlib.h>

long long int ways[200005];

int main()
{
    int t, n, k, q;
    scanf("%d", &t);
    ways[0]=0;
    for(int i=1;i<200005;i++)
    {
        ways[i]=ways[i-1]+i;
    }
    for(int i=1;i<=t;i++)
    {
        scanf("%d %d %d", &n, &k, &q);
        int a[n];
        int count=0;
        long long sum=0;
        for(int j=0;j<n;j++)
        {
            scanf("%d", &a[j]);
            if(a[j]<=q)
            {
                count++;
            }
            else
            {
                if(count>=k) 
                {
                    //printf("count%d way%d\n", count, ways[count-k+1]);
                    sum=sum+ways[count-k+1];
                }
                count=0;
            }
            if(j==n-1 && count>=k)
            {
                //printf("count%d way%d\n", count, ways[count-k+1]);
                sum=sum+ways[count-k+1];
            }
        }
        printf("%lld\n", sum);
    }
    return 0;
}
