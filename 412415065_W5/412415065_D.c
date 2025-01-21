#include <stdio.h>
#include <stdlib.h>
#include<string.h>

int main()
{
    
    char *str = malloc(sizeof(char)*100005);
    char *key = malloc(sizeof(char)*100005);
    scanf("%s", str);
    scanf("%s", key);
    int point;

    for(int i=1;i<=strlen(str);i++)
    {
        
        point=(i-1)%strlen(key);

        if(*(str+i-1)<='Z')
        {
            if(*(key+point)>90)
            {
                *(key+point)=*(key+point)-32;
            }

            if(*(str+i-1)+*(key+point)-'A'>'Z')
            {
                *(str+i-1)=*(str+i-1)+*(key+point)-'A'- 26;
            }
            else
            {
                *(str+i-1)=*(str+i-1)+*(key+point)-'A';
            }
        }
        else 
        {
            if(*(key+point)<97)
            {
                *(key+point)=*(key+point)+32;
            }

            if(*(str+i-1)+*(key+point)-'a'>'z')
            {
                *(str+i-1)=*(str+i-1)+*(key+point)-'a'-26;
            }
            else
            {
                *(str+i-1)=*(str+i-1)+*(key+point)-'a';
            }
        }
        printf("%c", *(str+i-1));
    }
    return 0;
}