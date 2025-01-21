#include<stdio.h>
#include<stdlib.h>

int data[200005];

typedef struct node{
    int num;
    struct node *nextPtr;
}node;

typedef struct list{
    node *head;
    node *tail; 
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
    if(data[num]>0)
    {
        return;
    }

    node *new_node = create_node(num);
    if(li->head == NULL)
    {
        //new_node->nextPtr = li->head;
        li->head = new_node;
        li->tail = new_node;
    }
   else
    {
        li->tail->nextPtr = new_node;
        li->tail = new_node;
    }
    data[num]++;
    li->count++;
}

// void Delete(list *li,int a[], int n)
// {
//    node **indirect = &li->head;
//     while (*indirect != NULL) 
//     {
//         if (a[(*indirect)->num] > 1)
//         {
//             node *temp = *indirect;
//             *indirect = (*indirect)->nextPtr;
//             a[temp->num]--;
//             free(temp);
//             li->count--;
//         } else 
//         {
//             indirect = &((*indirect)->nextPtr);
//         }
//     }
// }


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
    li->tail = NULL;
    li->count = 0;
}

void print_list(list* li) {
    node* current = li->head;
    while (current != NULL) {
        printf("%d ", current->num);
        current = current->nextPtr;
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    list li = {NULL, NULL, 0};
    for(int i=0;i<n;i++)
    {
        int num;
        scanf("%d", &num);
        //data[num]++;
        insert(&li, num);
    }
    //Delete(&li, data, n);
    printf("%d\n", li.count);
    print_list(&li);
    destroy(&li);
    return 0;
}