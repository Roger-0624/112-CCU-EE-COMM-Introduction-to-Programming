#include <stdio.h>
#include <stdlib.h>
#include<string.h>

int main()
{
    int t, pos;

    char *sptr = malloc(sizeof(char)*1005);
    char *cptr = malloc(sizeof(char)*1005);

    scanf("%d", &t);
    
    for(int i=1;i<=t;i++)
    {
        
        scanf("%s", sptr);
        //printf("%c", *sptr);
        scanf("%d", &pos);
        scanf("%s", cptr);

        for(int i=0;i<strlen(cptr);i++)
        {
            switch(*(cptr+i))
            {
                case '>':
                pos=pos+1;
                break;

                case '<':
                pos=pos-1;
                break;

                case '+':
                *(sptr+pos)=*(sptr+pos)+1;
                break;

                case '-':
                *(sptr+pos)=*(sptr+pos)-1;
                break;

                case '.':
                putchar(*(sptr+pos));
                break;
            }
        }
        printf("\n");
     }
    return 0;
}