#include<stdio.h>
#include<math.h>

void binary(int lo, int hi, int question, int position[], int k, int time[])
{
    int mid_point = (lo + hi)/2;
    if(time[mid_point] == question)
    {
        printf("%d\n", position[mid_point]);
        return;
    }
    if(time[mid_point] > question)
    {
        if(time[mid_point-1] < question)
        {
            int delta_x = position[mid_point] - position[mid_point-1];
            int delta_t = time[mid_point] - time[mid_point - 1];
            double speed = (double)delta_x/delta_t;
            double ans = speed * (question-time[mid_point-1]) + position[mid_point-1]; 
            ans = floor(ans);
            printf("%.0lf\n", ans);
            return;
        }
        return binary(lo, mid_point-1, question, position, k, time);
    }
    if(time[mid_point] < question)
    {
        if(time[mid_point+1] > question)
        {
            int delta_x = position[mid_point+1] - position[mid_point];
            int delta_t = time[mid_point+1] - time[mid_point];
            double speed = (double)delta_x/delta_t;
            double ans = speed * (question-time[mid_point]) + position[mid_point]; 
            ans = floor(ans);
            printf("%.0lf\n", ans);
            return;
        }
        return binary(mid_point+1, hi, question, position, k, time);
    }
}
int main()
{
    int n, k, q;
    scanf("%d %d %d", &n, &k, &q);
    int position[k+1], time[k+1], question[q];
    position[0] = 0;
    time[0] = 0;
    for(int i=1;i<k+1;i++)
    {
        scanf("%d", &position[i]);
    }
    for(int i=1;i<k+1;i++)
    {
        scanf("%d", &time[i]);
    }
    for(int i = 0; i<q;i++)
    {
        scanf("%d", &question[i]);
    }
    for(int i = 0; i<q;i++)
    {
        binary(0, k+1, question[i], position, k, time);
    }
    return 0;
}