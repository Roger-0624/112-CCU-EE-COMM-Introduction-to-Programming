#include <stdio.h>
#include <stdlib.h>


int main()
{
    int input, test=0, N;
    scanf("%d", &N);
    for(int i=1;i<=N;i++)
    {
        test=0;
        scanf("%d", &input);
        if(input%2==0&&input!=2)
        {
            printf("No\n");
        }
        else if(input==1)
        {
            printf("No\n");
        }
        else
        {

            for(int i=3;i*i<=input;i=i+2)
            {
                if(input%i==0)
                {
                    test=1;
                    break;
                }
            }
            if(test)
            {
                printf("No\n");
            }
            else
            {
                printf("Yes\n");
            }
        }
    }
    return 0;
}
