#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

typedef struct{
    char n[35];
    char m[35];
    int p;
}book;

book books[105];

typedef struct{    //大寫書名
    char name[35];
}big;

big bigbooks[105];
int len[105];

int main()
{
    int t;
    scanf("%d", &t);
    
    for(int i=0;i<t;i++)
    {
        scanf("%s %s %d ", books[i].n, books[i].m, &books[i].p);
        len[i]=strlen(books[i].m);
        for(int j=0;j<len[i];j++)
        {
            bigbooks[i].name[j] = toupper(books[i].n[j]);
        }
        bigbooks[i].name[len[i]]='\0';
        //printf("%s\n", books[i].m);
    }
    char input[35];
    int digit_flag=0, NULL_flag=0, k=1;
    while(scanf("%s", input)!=EOF)
    {
        digit_flag=0, NULL_flag=0;
        int len_input=strlen(input);
        for(int j=0;j<len_input;j++)
            {
                if(isdigit(input[j])!=0)//數字
                {
                    digit_flag=1;
                }
                else if(digit_flag==1)  //格式有誤
                {
                    NULL_flag=1;
                    break;
                }
            }
        if(NULL_flag)
            {
                printf("case %d:\nNULL\n", k++);
                continue;
            }
        NULL_flag=1;
        int case_flag=1;
        for(int i=0;i<t;i++)  //搜尋全部
        {
                if(digit_flag)
                {
                    if(strncmp(input, books[i].m, len_input)==0)
                    {
                        if(case_flag)
                        {
                            printf("case %d:\n%s\n%s\n%d\n", k++, books[i].n, books[i].m, books[i].p);
                        }
                        else
                        {
                            printf("%s\n%s\n%d\n", books[i].n, books[i].m, books[i].p);
                        }
                        case_flag=0;
                        NULL_flag=0;
                    }
                }
                else    //字串
                {
                    char biginput[35];//大寫input
                    for(int j=0;j<len_input;j++)
                    {
                        biginput[j]=toupper(input[j]);
                    }
                    biginput[len_input] = '\0';
                    //printf("%s ", biginput);
                    //printf("%s ", bigbooks[i].name);

                    if(strncmp(biginput, bigbooks[i].name, len_input)==0)
                    {
                        if(case_flag)
                        {
                            printf("case %d:\n%s\n%s\n%d\n", k++, books[i].n, books[i].m, books[i].p);
                        }
                        else
                        {
                            printf("%s\n%s\n%d\n", books[i].n, books[i].m, books[i].p);
                        }
                        case_flag=0;
                        NULL_flag=0;
                    }
                }
        }
        if(NULL_flag)
            {
                printf("case %d:\nNULL\n", k++);
            }
    }
    return 0;
}