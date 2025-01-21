#include<stdio.h>
#include<stdlib.h>

long long int Max(long long int a,long long int b)
{
    if(a>=b)return a;
    else return b;
}

long long ans = 0;

void binary(long long int lo, long long int hi, long long int obj,long long int diagonal)
{
    long long int mid = (lo + hi)/ 2;
    long long int max = Max(mid, diagonal);
    long long int mid_result = diagonal * mid + max * max;
    if(lo>hi)
    {
        ans = ans + mid - diagonal;
        return;
    }
    else if(mid_result > obj)
    {
        return binary(lo, mid-1, obj, diagonal);
    }
    else
    {
        return binary(mid+1, hi, obj, diagonal);
    }
}

int main()
{
    long long int n, i, j;
    scanf("%lld %lld %lld", &n, &i, &j);
    long long int max = Max(i, j);
    long long int obj = i*j + max * max; 
    long long diagonal_result;
    long long int diagonal;
    for(diagonal=1;diagonal<=n;diagonal++)
    {
        diagonal_result=2*diagonal*diagonal;
        if(diagonal_result>obj)
        {
            break;
        }
        binary(diagonal, n, obj, diagonal);
    }
    diagonal = diagonal - 1;
    ans = ans * 2;
    ans = ans + diagonal;
    printf("%lld", ans);
    return 0;
}

