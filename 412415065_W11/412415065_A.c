#include<stdio.h>
#include<stdlib.h>

void bubblesort(int a[], int n)
{
    for(int i=n;i>=0;i--)
    {
        for(int j=0;j<i-1;j++)
        {
            if(a[j]>a[j+1])
            {
                int temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
}


int main()
{
    int n, op;
    scanf("%d %d", &n, &op);
    int a[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d", &a[i]);
    }
    //printf("Yes");
    bubblesort(a, n);
    //printf("No");
    if(op==1)
    {
        for(int i=0;i<n;i++)
        {
            printf("%d ", a[i]);
        }
    }    
    else
    {
        for(int i=n-1;i>=0;i--)
        {
            printf("%d ", a[i]);
        }
    }
    return 0;
}