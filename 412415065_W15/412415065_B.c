#include<stdio.h>

typedef struct 
{
    int arrive_time, give_time;
}Mouse;


int main()
{
    int n;
    scanf("%d", &n);
    long long now = 0, ans = 0, segment_time = 0;
    Mouse *mouse = (Mouse *)malloc(n * sizeof(Mouse)); 
    for(int i=0;i<n;i++)
    {
        scanf("%d %d", &mouse[i].arrive_time, &mouse[i].give_time);
        if(now <= mouse[i].arrive_time)     //沒等到
        {
            now = mouse[i].arrive_time;
        }
        segment_time = now - mouse[i].arrive_time;      //這隻老鼠等的時間
        ans = ans + segment_time;                       
        now = now + mouse[i].give_time;         //+點交的時間
        segment_time = 0;
    }
    printf("%lld", ans);
    free(mouse);
    return 0;
}