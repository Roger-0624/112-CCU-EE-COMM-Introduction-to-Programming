#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct
{
    int x, y;
    int distance;   
}Node;

char maze[1005][1005];

int way[4][2] = {
    {-1 ,0},    //上 
    {1, 0},     //下
    {0, -1},    //左
    {0,1}      //右    
};

int walkTheMaze(int origin_x, int origin_y, int n)
{
    Node *queue = (Node *)malloc(n*n*sizeof(Node));
    int front = 0, rear = 0;
    //走過的路
    int **visted = (int **)malloc(n *sizeof(int*));
    for(int i = 0; i < n; i++)
    {
        visted[i] = (int *)malloc(n*sizeof(int));
        for(int j = 0; j < n; j++)
        {
            visted[i][j] = 0;
        }
    }
    queue[rear++] = (Node){origin_x, origin_y, 0};
    visted[origin_x][origin_y] = 1; //走過的路填1

    while(front < rear)     //front > rear(無路可走)
    {
        Node current = queue[front++];
        if(current.x == 0 || current.y ==0 || current.x == n-1 || current.y == n-1) //如果在邊界的話
        {
            for(int i = 0; i < n; i++)
            {
                free(visted[i]);
            }
            free(visted);
            free(queue);
            return current.distance;
        }
        //上下左右
        for(int i = 0; i < 4; i++)
        {
            int new_x = current.x + way[i][0];  
            int new_y = current.y + way[i][1];
            //不在邊界 也沒走過的話
            if(new_x >= 0 && new_y >= 0 && new_x < n && new_y < n && maze[new_x][new_y] == '.' && !visted[new_x][new_y])
            {
                queue[rear++] = (Node){new_x, new_y, current.distance+1};
                visted[new_x][new_y] = 1;
            }
        }
    }
    //沒有出口的話
    for(int i = 0; i < n ; i++)
    {
        free(visted[i]);
    }
    free(visted);
    free(queue);
    return -1;
    
}

int main()
{
    int n, origin_x, origin_y, distance;
    scanf("%d", &n);
    Node *node = (Node*)malloc(n*n*sizeof(Node));
    for(int i=0;i<n;i++)
    {
        scanf("%s", maze[i]);
    }
    scanf("%d %d", &origin_x, &origin_y);
    distance = walkTheMaze(origin_x, origin_y, n);
    printf("%d", distance);
}