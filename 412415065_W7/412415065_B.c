#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include<math.h>

char s[1500005];
int byte[1500005*6];    //記憶體不用錢
int k=0;
int len_s;

void stobase64(char s[])
{
    len_s=strlen(s);
    for (int i=0;i<len_s;i++) 
    {
        char c=s[i];
        if(s[i]=='=')
        {
            byte[k++]=0;
            byte[k++]=0;
            continue;
        }
        else if(s[i]=='+')
            {
                c=62;
            }
        else if(s[i]=='/')
            {
                c=63;
            }
        else if(s[i]<='9' && s[i]>='0')
        {
            c+=4;
        }

        else if(s[i]<='Z' && s[i]>='A')
            {
                c-=65;
            }
        else if(s[i]<='z' && s[i]>='a')
            {
                c-=71;
            }
            //printf("%c", c);
            for(int j=5;j>=0;j--)
            {
                byte[k++]=(c>>j)&1;
            }     
    }
}

int main()
{
    scanf("%s", s);
    stobase64(s);
    int ascii=0,  num=0;

    for(int i=0;i<=len_s*6;i+=8)
    {
        ascii=0;
        for(int j=0;j<=7;j++)
        {
            ascii+=byte[num++]*pow(2,7-j);
        }
        //printf("%d ", ascii);
        if(ascii)
        {
            printf("%c", ascii);
        }
        
    }
    return 0;
}
 