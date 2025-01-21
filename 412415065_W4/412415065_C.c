#include <stdio.h>
#include <stdlib.h>


int array[1005][1005];
int map[1005][1005];

int main()      //先填值 再print
{
    int m, n, k=0;
    scanf("%d %d", &m, &n);

    //printf("\n");
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            array[i][j]=1;
            //printf("(%d,%d)",i, j);
        }
        //printf("\n");
    }
    // (1,1)(1,2)(1,3)
    // (2,1)(2,2)(2,3)
    // (3,1)(3,2)(3,3)

    int i=1, j=1, t=0;
    while(t<=m*n)   //撞到牆壁或是輸過的地方 就轉彎
    {
        t++;
        while(array[i][j+1]!=0 && map[i][j+1]!=1)   //向右 右邊不是0(牆壁) 且 右邊沒被寫過
        {
            array[i][j]=++k;
            map[i][j]=1;
            j++;
        }
        

        while(array[i+1][j]!=0 && map[i+1][j]!=1)     //向下 下面不是0(牆壁) 且 下面沒被寫過
        {
            array[i][j]=++k;
            map[i][j]=1;
            i++;
            
        }

         while(array[i][j-1]!=0 && map[i][j-1]!=1)     //向左 左邊不是0(牆壁) 且 左邊沒被寫過
        {
            array[i][j]=++k;
            map[i][j]=1;
            j--;
        }

         while(array[i-1][j]!=0 && map[i-1][j]!=1)     //向上 上面不是0(牆壁) 且 上面沒被寫過
        {
            array[i][j]=++k;
            //printf("(%d,%d)=%d\n",i, j, array[i][j]);
            map[i][j]=1;
            i--;
        }
        
    }
    if( (map[i-1][j] || array[i-1][j]==0) && (map[i+1][j] || array[i+1][j]==0) && (map[i][j-1] || array[i][j-1]==0) && (map[i][j+1] || array[i][j+1]==0))   //四周為牆壁或是填過的數字
        {
            array[i][j]=m*n;
        }
    //最後一個不知道為甚麼打不出來啦... 用數學


    // if(m==n&&m%2==1)    //奇數邊長的正方形
    // {
    //     array[(m+1)/2][(n+1)/2]=m*n;
    // }
    // else if(m==n && m%2==0)     //偶數邊長的正方形
    // {
    //     array[m/2+1][n/2]=m*n;
    // }

    // else if(m!=n)   //長方形
    // {
    //     array[(m+1)/2][(n+1)/2+1]=m*n;
    // }

     for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            printf("%d ", array[i][j]);
        }
        printf("\n");
    } 
    return 0;   
}
    
    
    

