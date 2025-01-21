#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int num;
    struct node *nextPtr;
}node;


node *create_node(int num)
{
    node *new_node = (node*)malloc(sizeof(node));
    new_node->num = num;
    new_node->nextPtr = NULL;
    return new_node;
}

node *circular(int n)
{
    node *head = NULL;
    node *prev = NULL;
    for(int i = 1; i <= n; i++)
    {
        node *new_node = create_node(i);
        new_node->num = i;
        if(head == NULL) //第一個節點
        {
            head = new_node;
        }
        else
        {
            prev->nextPtr = new_node;
        }
        prev = new_node;
    }
    prev->nextPtr = head;
    return head;
    
}

//int pos = 1;

void Delete(node*head, int n, int q)
{
    if(head == NULL) return;
    node *current = head;
    node *prev = NULL;
    int count = 0;
    while(count<n)
    {
        if(count == 0)
        {
            for(int i=1;i<=q;i++)
            {
                prev = current;
                current = current->nextPtr;
            }
        }
        else
        {
            for(int i = 1; i<=q-1;i++)  //少跑一次
            {
                prev = current;
                current = current->nextPtr;
            }
        }
        node *temp = current;
        if(prev != NULL)    //指到下下個
        {
            prev->nextPtr = current->nextPtr; 
        }
        else
        {
            head = current->nextPtr;
        }
        current = current->nextPtr;
        printf("%d ", temp->num);
        free(temp);
        count++;
    }
    
}


int main()
{
    int n, q;
    scanf("%d %d", &n, &q);
    node *head = circular(n);
    Delete(head, n, q);
    return 0;
}