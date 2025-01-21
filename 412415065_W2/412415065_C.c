#include <stdio.h>
#include <stdlib.h>
#include<math.h>

int main()
{
    int n;
    scanf("%d", &n);
    for(int i=1;i<n+1;i++)
    {
        for(int j=1;j<2*n;j++)
        {
           if(i+j==n+1||j-i==n-1||i==n)
           {
               printf("*");
           }
           else if((i+j<=n)||abs(j-i)<=n-1)
           {
               printf(" ");
           }
           //printf("(%d,%d)", i, j);
        }
        printf("\n");
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<n;j++)
        {
            printf(" ");
        }
        printf("*\n");
    }
    //printf("\n");
    return 0;
}
