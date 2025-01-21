#include<stdio.h>
#include<stdlib.h>

typedef struct {
        int a;
        int ain;
        int aout;
        int b;
        int bin;
        int bout;
        }S;
S s[200005]; 

int main()
{
    // printf("hello");
    int n, q;
    scanf("%d %d", &n, &q);   
    for(int i=0; i<n; i++)
    {
        int inpa, inpain, inpaout, inpb, inpbin, inpbout;
        scanf("%d %d %d %d %d %d", &inpa, &inpain, &inpaout, &inpb, &inpbin, &inpbout);
        s[i].a=inpa;
        s[i].ain=inpain;
        s[i].aout=inpaout;
        s[i].b=inpb;
        s[i].bin=inpbin;
        s[i].bout=inpbout;
    }
    int now=0;
    for(int i=1;i<=q;i++)
    {
        int input;
        scanf("%d", &input);
        if(s[now].ain==input)
        {
            printf("%d\n", s[now].aout);
            now=s[now].a;
        }
        else
        {
            printf("%d\n", s[now].bout);
            now=s[now].b;
        }
        if(i==q)
        {
            printf("S%d\n", now);
        }
    }
    return 0;
}