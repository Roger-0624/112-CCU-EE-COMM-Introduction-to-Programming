#include<stdio.h>
#include <stdlib.h>
#include<math.h>

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    double R[n][m], G[n][m], B[n][m]; 
    double gray[n+2][m+2];
    double ans[n][m];
    double guass[3][3]=
    {
        {0.045, 0.122, 0.045},
        {0.122, 0.332, 0.122},
        {0.045, 0.122, 0.045}
    };
    
    for(int i=0;i<=n-1;i++)
    {
        for(int j=0;j<=m-1;j++)
        {
            scanf("%lf", &R[i][j]);
        }
    }
    for(int i=0;i<=n-1;i++)
    {
        for(int j=0;j<=m-1;j++)
        {
            scanf("%lf", &G[i][j]);
        }
    }
    for(int i=0;i<=n-1;i++)
    {
        for(int j=0;j<=m-1;j++)
        {
            scanf("%lf", &B[i][j]);
            gray[i+1][j+1] =round(0.299 * R[i][j] +0.587 * G[i][j] + 0.114 * B[i][j]);
        }
    }
    double sum=0;
    int x=0, y=0;
    for(int i=1;i<=n;i++) //要怎麼內積啦==
    {
        for(int j=1;j<=m;j++)
        {
            for(int gi=-1;gi<=1;gi++)
            {
                for(int gj=-1;gj<=1;gj++)
                {
                    sum=gray[i+gi][j+gj]*guass[gi+1][gj+1]+sum;
                }
            }
            ans[x][y]=round(sum);
            sum=0;
            y++;
            if(y>=m)
            {
                y=0;
                x++;
            }
            if(x>=n && y>=m)
            {
                break;
            }
        }
    }
    
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            printf("%d ", (int) ans[i][j]);
        }
        printf("\n");
    }
    return 0;
}
    

