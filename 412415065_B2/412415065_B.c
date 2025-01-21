#include<stdio.h>
#include<string.h>

int num[505];
char string[505][505];

int main()
{
    int t, len, segments = 1, mark;
    int zero_flag = 0, sort_flag = 0;
    scanf("%d", &t);
    for(int i=0;i<t;i++)
    {
        scanf("%s", string[i]);
        len = strlen(string[i]);
        for(int j=0 ;j < len-1 ;j++)
        {   
            //找排序好的
            if(string[i][j]=='0' && string[i][j+1]=='1')
            {
                sort_flag = 1;
                break;
            }
        }
        //sort_flag = 0;
        for(int j=0;j<len-1;j++)
        {
            if(string[i][j]!=string[i][j+1])
            {
                segments++;
            }
        }
        if(sort_flag)
        {
            segments--;
        }
        num[i] = segments;
        segments = 1;
        sort_flag=0;
    }
    for(int i=0;i<t;i++)
    {
        printf("%d\n", num[i]);
    }
    return 0;
}