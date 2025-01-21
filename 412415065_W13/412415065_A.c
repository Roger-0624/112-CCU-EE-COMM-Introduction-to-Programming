#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int num;
    struct node *nextPtr;
}node;

typedef struct list{
    node *head;
    int count;
}list;

node * create_node(int num)
{
    node *new_node = (node*)malloc(sizeof(node));
    new_node->num = num;
    new_node->nextPtr = NULL;
    return new_node;
}

void insert(list *li, int num)
{
    node *new_node = create_node(num);
    if(li->head == NULL || li->head->num >= num)
    {
        new_node->nextPtr = li->head;
        li->head = new_node;
    }
    else
    {
        node *current =li->head;
        while(current->nextPtr != NULL && current->nextPtr->num < num) 
        {
            current = current ->nextPtr;
        }
        new_node->nextPtr = current->nextPtr;
        current->nextPtr = new_node;
    }
    li->count++;
}

void Delete(list *li, int num)
{
    node **indirect = &li->head;
    //int flag = 0;
    while(*indirect != NULL)
    {
        if((*indirect)->num == num)
        {
            node *temp = *indirect;
            *indirect = (*indirect)->nextPtr;
            free(temp);
            li->count--;
            //flag = 1;
        }
        else
        {
            indirect = &((*indirect)->nextPtr);
        }
   }
   //if(!flag) return; 
}

void reverse(list *li, int site, int r)
{
    
    if(site < 1 || r < 2 || site + r -1 > li->count) return;
    if(li->head == NULL) return;

    node **indirect = &(li->head);
    for(int i=1; i < site && *indirect !=NULL; i++)
    {
        indirect = &((*indirect)->nextPtr);
    }

    // node *check = *indirect;
    // for (int i = 0; i < r && check != NULL; i++) 
    // {
    //     check = check->nextPtr;
    // }
    // if (check == NULL) return;

    node *current = *indirect;
    node *prev = NULL;
    node *nextPtr = NULL;
    node *tail = current;

    for(int i = 0; i < r && current != NULL; i++)
    {
        nextPtr = current->nextPtr;
        current->nextPtr = prev; 
        prev = current;
        current = nextPtr;
    }

    if(tail != NULL)
    {
        tail->nextPtr = current;
    }
    *indirect = prev;
}

void destroy(list *li)
{
    node *current = li->head;
    while(current != NULL)
    {
        node *temp = current;
        current = current->nextPtr;
        free(temp); 
    }
    //free(li);
    li->head = NULL;
    li->count = 0;
}

void print_list(list* li) {
    node* current = li->head;
    while (current != NULL) {
        printf("%d ", current->num);
        current = current->nextPtr;
    }
    //printf("NULL\n");
}

int main()
{
    int n, q;
    scanf("%d %d", &n, &q);

    list li = {NULL, 0};

    for(int i=0;i<n;i++)
    {
        int num;
        scanf("%d", &num);
        insert(&li, num);
    }
    for(int i=0;i<q;i++)
    {
        int which;  //1或2
        int num, site, r;
        scanf("%d", &which);
        if(which == 1)
        {
            scanf("%d", &num);
            Delete(&li, num);
        }
        else
        {
            scanf("%d %d", &site, &r);
            reverse(&li, site, r);
        }
    }
    print_list(&li);
    destroy(&li);
    return 0;
}