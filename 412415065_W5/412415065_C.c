#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, q;

    scanf("%d %d", &n, &q);
    int **nptr = (int**)malloc(n*sizeof(int*));
    int *row = (int*)malloc(n*sizeof(int)); 
    for(int j=0;j<n;j++)
    {
        scanf("%d", row+j);
        *(nptr + j) = (int *)malloc(*(row+j)*sizeof(int));
        for (int i = 0; i < *(row+j); i++) 
        {  
            scanf("%d", *(nptr+j) + i);
        }
    }

    int x, y;

    for(int i=1;i<=q;i++)
    {
        scanf("%d %d", &x, &y);
        if(y>=*(row+x)|| y<0)
        {
            printf("-1\n");
        }
        else
        {
            printf("%d\n", *(*(nptr+x)+y));
        }
    }
    return 0;
}