#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

char s[1000005];
int byte[1000005*8];    //記憶體不用錢
int len_s;

void stringtobinary(char s[])
{
    int k=0;
    len_s=strlen(s);
    for (int i=0;i<len_s;i++) 
    {
        char c=s[i];
        for(int j=7;j>=0;j--)
        {
            byte[k++]=(c>>j)&1;
        }
    }
}   

int main()
{
    gets(s);
    stringtobinary(s);
    int len_byte=len_s*8;
    int count=0;
        if(len_byte%6!=0)   //padding
        {
            for(int i=len_byte;1;i++)
            {
                if(i%6==0)
                {
                    break;
                }
                byte[i]=0;
                len_byte++;
                count++;
            }
        }

    int k=0, base64=0;
    for(int i=0;i<len_byte/6;i++)
    {
        base64=0;
        for(int j=0;j<6;j++)
        {
            base64=byte[k++]*pow(2,5-j)+base64;
        }
        //printf("%d", base64);

        //base64轉ascii
        if(base64>63 || base64<0) //非以上 直接略過
        {
            continue;
        }
        else if(base64<=25)  //大寫
        {
            base64+=65;
        }
        else if(base64<=51) //小寫
        {
            base64+=71;
        }
        else if(base64<=61) //數字
        {
            base64-=4;
        }
        else if(base64==62)   //+
        {
            base64=43;
        }
        else if(base64==63)    //'/'
        {
            base64=47;
        }
        printf("%c", base64);
        
        
    }
    if(count==4)
    {
        printf("==");
    }
    else if(count==2)
    {
        printf("=");
    }
    // printf("\n");
    // for(int i=0;i<len_byte;i++)
    // {
    //     printf("%d", byte[i]);
    // }
    // printf("\n%d", count);
    return 0;
}