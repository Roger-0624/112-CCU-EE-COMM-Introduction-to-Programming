#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char n[1000005];
int ans[1000005];

int main()
{
    int remove_num=0, k=0, flag=0, flag_mapie=0;
    scanf("%s", n);

    for(int i=0;i<=1000005;i++)
    {
        if(n[i]=='\0')
        {
            break;
        }

        if(i>=2)
        {
                if( n[i-2]=='m' && n[i-1]=='a' && n[i]=='p' &&n[i+1]=='i' &&n[i+2]=='e')
                {
                        remove_num++;
                        ans[k]=i+1;
                        //printf("ans%d\n", ans[k]);
                        flag=1;  

                        if(flag_mapie==1)
                        {
                            flag_mapie=0;
                            remove_num--;
                            k=k-1;
                            ans[k]=i+1;
                            //printf("k%d ans%d\n",k, ans[k]);
                        } 
                        k++; 
                        continue;
                }
                    if(flag==1)
                        {
                            i=i+2;
                            flag=0;
                            continue;
                        }
                        //printf("%d ", i);
                if(n[i-1]=='p' && n[i]=='i' && n[i+1]=='e')
                {   
                    
                    remove_num++;
                    ans[k]=i+1;
                    //printf("k%d ans%d\n",k ,ans[k]);
                    k++;
                }
                else if(n[i-1]=='m' && n[i]=='a' && n[i+1]=='p')
                {
                    remove_num++;
                    ans[k]=i+1;
                    k++;
                    flag_mapie=1;
                }
        }
        else
        {
            if(n[i-1]=='m' && n[i]=='a' && n[i+1]=='p')
                {
                    remove_num++;
                    ans[k]=i+1;
                    //printf("map%d", ans[k]);
                    k++;
                    flag_mapie=1;
                }
            else if(n[i-1]=='p' && n[i]=='i' && n[i+1]=='e')
                {
                    remove_num++;
                    ans[k]=i+1;
                    k++;
                }
        }
    }
    printf("%d\n", remove_num);
    for(int i=0;i<remove_num;i++)
    {
        printf("%d ", ans[i]);
    }
    return 0;
}