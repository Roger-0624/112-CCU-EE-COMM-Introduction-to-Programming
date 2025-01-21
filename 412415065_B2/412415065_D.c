#include<stdio.h>
#include<math.h>

long long int factorial(int num)
{
    long long int ans = 1;
    for(int i = 1; i<=num; i++)
    {
        ans = ans * i;
    }
    return ans;
}

long long int C(int a, int b, int c)
{
    int total = a + b + c;
    return factorial(total)/factorial(c)/factorial(total - c); 
}


int main()
{
    int a, b, c;
    long long ans;
    scanf("%d %d %d", &a, &b, &c);
    if(abs(a-b)>=2)
    {
        printf("0");
        return 0;
    }
    else
    {
        ans = C(a, b , c);
        if(a==b)
        {
            ans = ans * 2;
        }
    }
    printf("%lld", ans);
    return 0;
}