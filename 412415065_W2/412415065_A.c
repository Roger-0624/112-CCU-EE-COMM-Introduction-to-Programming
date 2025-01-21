#include <stdio.h>
#include <stdlib.h>

int main()
{
    int input;
    scanf("%d", &input);
    int num[input];
    for(int i=0;i<input;i++)
        {
            scanf("%d", &num[i]);
        }
    if(input%2==0)
    {
        printf("0");
    }
    else
    {
        for(int i=0;i<input;i++)
        {
            num[i+1]=num[i]^num[i+1];
        }
        printf("%d", num[input-1]);
    }
    return 0;
}
