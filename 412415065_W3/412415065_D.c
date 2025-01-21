#include <stdio.h>
#include <stdlib.h>

int level[1005][1005]={0};  //當前等級
int s[1005][1005]={0};          //最大等級


int main()
{
    int n, r, t, flag=0;
    scanf("%d", &n);
    scanf("%d", &r);
    for(int i=1;i<=n;i++)
    {
        scanf("%d", &t);
        for(int j=1;j<=r;j++)
        {
            scanf("%d", &s[t][j]);  //最大等級上限
        }
    }

    int q1, q2, q3, u, q4;

    while(1)
    {
        scanf("%d", &q1);
        if(q1==1)   //開始
        {    
            scanf("%d", &q2);

            if(q2%2==1)     //查看等級
            {
                scanf("%d %d", &q3, &q4);

                if(s[q2/2][1]>0)    //若等級上限>0(即有此樹)
                {   
                    //printf("q %d\n", q2);
                    // if(s[q2/2][q3]<=level[q2/2][q3])    //已超過最大等級上限
                    // {
                    //     printf("%d\n", s[q2/2][q3]);
                    // }

                    // else    
                    // {
                    // }
                    printf("%d\n", level[q2/2][q3]);
                }
                else    // 沒樹
                {
                    printf("-1\n");
                }
            }

            else    //提升等級
            {
                scanf("%d %d %d", &q3, &u, &q4);
                if(s[q2/2][1]>0)    //若等級上限>1(即有此樹)
                    {   
                        level[q2/2][q3]=level[q2/2][q3]+u;
                        // if(level[q2/2][q3]==s[q2/2][q3])
                        // {
                        //     printf("-1\n");
                        // }
                        if(level[q2/2][q3]>s[q2/2][q3])
                        {
                            level[q2/2][q3]=s[q2/2][q3];
                        }
                    }
                
                else    // 沒樹
                {
                    printf("-1\n");
                }
                // printf("q %d\n", &q1);
            }
        }
        else        //結束
        {
            for(int i=0;i<=1004;i++)
            {
                for(int j=0;j<=1004;j++)
                {
                    if(s[i][j]>level[i][j])
                    {
                        flag=1;
                        break;
                    }
                }
            }

            if(flag)
            {   
                // printf("q %d\n", &q1);
                printf("Not ready");
            }
            else
            {
                printf("Ready perfectly");
            }
            break;
        }
    }   
    return 0;
}
