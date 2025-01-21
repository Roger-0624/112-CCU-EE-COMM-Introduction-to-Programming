#include <stdio.h>
#include <stdlib.h>

int main()
{
    int t, n, k, even, odd1, odd3, flag=0;
    scanf("%d", &t);
    for(int i=1;i<=t;i++)
    {
        even=0, odd1=0, odd3=0, flag=0;

        scanf("%d%d", &n, &k);

        int a[n], r[n];
        int max=0;

        for(int j=0;j<n;j++)
        {
            scanf("%d", &a[j]);
            r[j]=a[j]%k;
            if(r[j]==0||k==1)   //餘數=0或是k=1
            {
                flag=1;
            }
            if(k==4)
            {
                if(r[j]==2)
                {
                    even++;
                }
                else if(r[j]==1)
                {
                    odd1++;
                }
                else
                {
                    odd3++;
                }
            }
            else        //k=2,3,5
            {
                if(max <= r[j] )
                {
                    max=r[j];
                }
            }
        }
        if(flag)
        {
            printf("0\n");
        }
        else
        {
           if(k==4)
            {
                if(even>=2)//2偶
                    {
                        printf("0\n");
                    }
                    else if((even==1&&odd1>=1)||odd3>=1)//1偶+餘1奇||餘3奇
                    {
                        printf("1\n");
                    }
                    else if((even==1&&n==1)||(odd3==0&&odd1>=2))//僅1偶 || 2個餘1奇
                    {
                        printf("2\n");    
                    }
                    else                        //(odd3==0&&odd1==1)//僅1餘1奇
                    {
                        printf("3\n");
                    }
            }
            else   //k=2,3,5
            {
                printf("%d\n", k-max);
            }
        }
    }
    return 0;
}
