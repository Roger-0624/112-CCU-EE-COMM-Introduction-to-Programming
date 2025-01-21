#include<stdio.h>
#include<stdlib.h>

int partition(long long int arr[], int lo, int hi) 
{
    long long int pivot = arr[(lo + hi) / 2];
    int i = lo - 1, j = hi + 1;
    while (1) 
    {
        do
        {
            i++;
        }  
        while (arr[i] < pivot);
        do     
        {
            j--;
        } 
        while (arr[j] > pivot);
        if (i >= j) 
        {
            return j;
        }
        //swap(arr, i, j);
        long long int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}
void quickSort (long long int arr[], int lo, int hi) 
{
    if (lo >= 0 && hi >= 0 && lo < hi) 
    {
        long long int pivot = partition (arr, lo, hi);
        quickSort(arr, lo, pivot); // 注意 pivot 有包含在内
        quickSort (arr, pivot + 1, hi);     
    }
}

int main()
{
    int n, m, count=1;
    scanf("%d %d", &n, &m);
    long long int a[n], b[m], h[n-1];
    for(int i=0; i<n; i++)
    {
        scanf("%lld", &a[i]);
        if(i-1>=0)
        {
            h[i-1]=a[i-1]-a[i];
        }
    }
    for(int i = 0 ; i < m ; i++)
    {
        scanf("%lld", &b[i]);
    }
    quickSort(b,0, m-1);
    int j=0, i=0;
    for(i=0; i<n-1 && j<m ;j++)
    {
        //printf("GGGGG");
        if(b[j]>=h[i])
        {
            i++;
            count++;
            //printf("\nHHHHHH\n");
        }
    }
    i++;
    printf("%d", count);
    return 0;
}