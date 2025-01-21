#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    int city;
    struct Node *next;
} Node;

typedef struct {
    int city;
    int time;
} QueueNode;

typedef struct {
    int front, rear;
    QueueNode *data;
} Queue;

void initQueue(Queue *q, int size) {
    q->front = q->rear = 0;
    q->data = (QueueNode *)malloc(size * sizeof(QueueNode));
}

void enqueue(Queue *q, QueueNode node) {
    q->data[q->rear++] = node;
}

QueueNode dequeue(Queue *q) {
    return q->data[q->front++];
}

int isEmpty(Queue *q) {
    return q->front == q->rear;
}

void freeQueue(Queue *q) {
    free(q->data);
}

void addEdge(Node **adjList, int u, int v) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->city = v;
    newNode->next = adjList[u];
    adjList[u] = newNode;
}

void freeAdjList(Node **adjList, int n) {
    for (int i = 0; i < n; i++) {
        Node *temp = adjList[i];
        while (temp) {
            Node *toFree = temp;
            temp = temp->next;
            free(toFree);
        }
    }
}

int main() {
    int n, e, s;
    scanf("%d %d %d", &n, &e, &s);

    int *infected = (int *)malloc(s * sizeof(int));
    int *time = (int *)malloc(n * sizeof(int));
    memset(time, -1, n * sizeof(int));

    Node **adjList = (Node **)malloc(n * sizeof(Node *));
    for (int i = 0; i < n; i++) {
        adjList[i] = NULL;
    }

    Queue q;
    initQueue(&q, n);

    for (int i = 0; i < s; i++) {
        int city;
        scanf("%d", &city);
        infected[i] = city;
        enqueue(&q, (QueueNode){city, 0});
        time[city] = 0;
    }

    for (int i = 0; i < e; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        addEdge(adjList, a, b);
        addEdge(adjList, b, a);
    }

    while (!isEmpty(&q)) {
        QueueNode current = dequeue(&q);
        Node *neighbor = adjList[current.city];
        while (neighbor) {
            if (time[neighbor->city] == -1) {
                time[neighbor->city] = current.time + 1;
                enqueue(&q, (QueueNode){neighbor->city, current.time + 1});
            }
            neighbor = neighbor->next;
        }
    }

    for (int i = 0; i < n; i++) {
        printf("%d ", time[i]);
    }
    printf("\n");

    freeQueue(&q);
    free(infected);
    free(time);
    freeAdjList(adjList, n);
    free(adjList);

    return 0;
}