#include <stdio.h>
#include <stdlib.h>

int n;

int partition(int arr[], int lo, int hi, int op) 
{   
    int pivot;
    int i = lo - 1, j = hi + 1;
    if(op==1)
    {
        pivot = arr[(lo + hi) / 2];
    }
    else
    {
        pivot = arr[lo +rand()%(hi-lo+1)];
    }
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
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

// 快速排序
void quickSort(int arr[], int lo, int hi, int op) 
{
    if (hi>=0 && lo < hi) {
        int pivot = partition(arr, lo, hi, op);
            for (int i = 0; i < n ; i++) 
            {
               printf("%d ", arr[i]);
            }
            printf("\n");  
        quickSort(arr, lo, pivot, op);
        quickSort(arr, pivot+1, hi, op);
    }
}

int main() {
    int  op, seed=0;
    scanf("%d %d", &n, &op);
    int arr[n];
    if(op==2)
    {
        scanf("%d", &seed);
        srand(seed);
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    quickSort(arr, 0, n - 1, op);
    return 0;
}
