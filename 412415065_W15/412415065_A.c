#include<stdio.h>

typedef struct{
    int front, rear;
    int data[200005];
}QueueArray;

void Enqueue(QueueArray*QueueArray, int value)
{
    QueueArray->data[++QueueArray->rear] = value;
}

int Dequeue(QueueArray*QueueArray)
{
    if(!IsEmpty(QueueArray))
    {
        return QueueArray->data[++QueueArray->front];
    }
    return -1;
}

int Front(QueueArray *QueueArray)
{
    if(IsEmpty(QueueArray))
    {
        return -1;
    }
    return QueueArray->data[QueueArray->front+1];
}

int IsEmpty(QueueArray *QueueArray)
{
    return QueueArray->rear == QueueArray->front;
}

int main()
{
    QueueArray QueueArray;
    QueueArray.front = -1;
    QueueArray.rear = -1;
    int n, conditions, num;
    scanf("%d", &n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d", &conditions);
        if(conditions == 1)
        {
            scanf("%d", &num);
            Enqueue(&QueueArray, num);
        }
        else if(conditions == 2)
        {
            Dequeue(&QueueArray);
        }
        else    //conditions == 3
        {
            if(IsEmpty(&QueueArray))
            {
                printf("no number\n");
            }
            else
            {
                num = Front(&QueueArray);
                printf("%d\n", num);
                //Dequeue(&QueueArray);
            }
        }
    }
    return 0;
}