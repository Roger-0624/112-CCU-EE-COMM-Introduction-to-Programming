#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char l[105], m[105], r[105];
int t[105];

int Max(int a, int b, int c)
{
    int max=a;
    if(max<=b)
    {
        max=b;
    }
    if(max<=c)
    {
        max=c;
    }
    return max;
}

int main()
{
    scanf("%s %s %s", l, m, r);

    int len_l, len_m, len_r, max;

    len_l=strlen(l);
    len_m=strlen(m);
    len_r=strlen(r);

    max=Max(len_l, len_m, len_r);

    for(int i=0;i<105;i++)  //初始化
    {
        if(i>=len_l)
        {
            l[i]='0';
        }
        if(i>=len_m)
        {
            m[i]='0';
        }
        if(i>=len_r)
        {
            r[i]='0';
        }
        t[i]=0;
    }


    
    //printf("%d\n\n", max);
    
    // if(len_l>=len_m && len_l>=len_r)  //l最多位
    // {
    //     max=len_l;
    // }
    // else if(len_m>=len_l && len_m>=len_r)    //m最多位
    // {
    //     max=len_m;
    // }
    // else                        // r最多位
    // {
    //     max=len_r;
    // }

    int j=0;
    for(int i=len_l-1;i>=0;i--) // l各項移到最右邊
    {
        l[104-j]=l[len_l-1-j];
        l[len_l-1-j]='0';
        //printf("j%d l[104-j]=%c \n", j, l[104-j]);
        j++;
    }
    j=0;
    for(int i=len_m-1;i>=0;i--) //m各項移到最右邊
    {
        m[104-j]=m[len_m-1-j];
        m[len_m-1-j]='0';
        //printf("j%d m[104-j]=%c \n", j, m[104-j]);
        j++;
    }
    j=0;
    for(int i=len_r-1;i>=0;i--) //r各項移到最右邊
    {
        r[104-j]=r[len_r-1-j];
        r[len_r-1-j]='0';
        //printf("j%d r[104-j]=%c \n", j, r[104-j]);
        j++;
    }
    j=0;

    for(int i=104;i>=0;i--)  
    {
        if(104-max==i)
        {
            break;
        }

        t[i]=t[i]+(int)(l[i]-'0')+(int)(m[i]-'0')+(int)(r[i]-'0');

        if(i!=104-max+1)
        {
            if(t[i]>=20)
            {
                t[i]=t[i]-20;
                t[i-1]=2;
                
            }
            else if(t[i]>=10)
            {
                t[i]=t[i]-10;
                t[i-1]=1;
            }
        }
        else    //最後一位
        { 
            if(t[i]>=20)
            {
                t[i]=t[i]-20;
                printf("2");
            }
            else if(t[i]>=10)
            {
                t[i]=t[i]-10;
                printf("1");
            }
        }
    }

    for(int i=105-max;i<=104;i++)
    {
        printf("%d", t[i]);   
    }
    return 0;
    //我之後一定乖乖翻轉再加 有夠麻煩==
}