#include<stdio.h>
#include<stdlib.h>
long long time[500005];

void binary(long long int time[], long long int n,long long int lo, long long int hi, long long int m)
{
    long long int mid = (lo + hi)/2;
    if(lo>hi)
    {
        printf("%lld\n", lo);
        return;
    }
    long long int trips=m;
    for(int i=0;i<n;i++)
    {
        //ans = mid;
        trips = trips - (mid/time[i]);
        if(trips <= 0)
        {
            binary(time, n, lo, mid-1, m);
            break;
        }
    }
    if(trips>0)       
    {
        binary(time, n, mid+1, hi, m);
        //break;
    }
    
}

int main()
{
    long long int n, m;
    long long int t;
    scanf("%lld", &t);
    long long int maxtime=0;
    for(long long int i=1;i<=t;i++)
    {
        scanf("%lld %lld ", &n, &m);
        for(long long int j=0;j<n;j++)
        {
            scanf("%lld", &time[j]);
            if(maxtime<=time[j])
            {
                maxtime = time[j];
            }
        }
        binary(time, n, 0, 100000000000, m);
    }
    return 0;
}