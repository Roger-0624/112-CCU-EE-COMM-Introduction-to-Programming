#include<stdio.h>
#include<stdlib.h>

int n;

void binary(int a[], int n,int lo, int hi, int qry)
{
    int mid = (lo + hi)/2;
    if(qry<a[0])
    {
        printf("0\n");
        return;
    }
    if(qry>a[n-1])
    {
        printf("%d\n", n);
        return;
    }
    if(qry>a[mid] && qry < a[mid+1])
    {
        printf("%d\n", mid +1);
        return;
    }

    if(a[mid]<qry)
    {
        return binary(a, n, mid+1, hi, qry); 
    }
    else
    {
        return binary(a, n, lo, mid-1, qry);
    }

}

int main()
{
    int t;
    scanf("%d %d", &n, &t); 
    int a[n];
    for(int i=0; i<n;i++)
    {
        scanf("%d", &a[i]);
    }
    int qry;
    for(int i=0;i<t;i++)
    {
        scanf("%d", &qry);
        binary(a, n, 0, n-1, qry);
    }
    return 0;
}