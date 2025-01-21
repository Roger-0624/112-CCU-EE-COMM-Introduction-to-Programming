#include<stdio.h>

int main()
{
    int x = 0, y = 0; //n = 30, m = 50, flag=0;
    printf("? %d %d\n", x, y);
    fflush(stdout);
    //for(int i=0;i<n+m+1;i++)
    while(1)
    {
        int ret;
        // if(x<n && y <m)
        // {
        //     ret = 1;
        //     flag = 1;
        // }
        // if(x == n && y <m)
        // {
        //     ret = 2;
        //     flag = 1;
        // }
        // if(x < n && y == m)
        // {
        //     ret = 3;
        //     flag = 1;
        // }
        // if(x == n && y == m)
        // {
        //     ret = 4;
        //     flag = 1;
        // }
        // if(!flag)
        // {
        //     ret = 5;
        //     flag = 0;
        // }
        scanf("%d", &ret);
        if(ret == 1)
        {
            //printf("%d\n", ret);
             x++;
             y++;
            //scanf("%d %d", &x, &y);
            printf("? %d %d\n", x, y);
            fflush(stdout);
        }
        else if(ret == 2)
        {
            //printf("%d\n", ret);
            y++;
            //scanf("%d %d", &x, &y);
            printf("? %d %d\n", x, y);
            fflush(stdout);
        }
        else if(ret == 3)
        {
            //printf("%d\n", ret);
            x++;
            //scanf("%d %d", &x, &y);
            printf("? %d %d\n", x, y);
            fflush(stdout);
        }
        else if(ret == 4)
        {
            printf("! %d %d", x, y);
            fflush(stdout);
            break;
        }
        else    //ret == 5
        {
            //printf("%d\n", ret);
            x--;
            y--;
            //scanf("%d %d", &x, &y);
            printf("? %d %d\n", x, y);
            fflush(stdout);
        } 
    }
}