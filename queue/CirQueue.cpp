#include <malloc.h>

#define MaxSize 50
typedef int ElemType;
typedef struct {
    ElemType data[MaxSize];
    int front, rear;
} CirSqQueue;

void initQueue(CirSqQueue *&q) {
    q = (CirSqQueue *) malloc(sizeof(CirSqQueue));
    q->rear = q->front = 0;
}

void destroyQueue(CirSqQueue *&q) {
    free(q);
}

bool queueEmpty(CirSqQueue *q) {
    return q->front == q->rear;
}

bool enQueue(CirSqQueue *&q, ElemType e) {
    if ((q->rear + 1) % MaxSize == q->front) {
        return false;
    }
    q->rear = (q->rear + 1) % MaxSize;
    q->data[q->rear] = e;
    return true;
}

bool deQueue(CirSqQueue *&q, ElemType &x) {
    if (q->front == q->rear) {
        return false;
    }
    q->front = (q->front + 1) % MaxSize;
    x = q->data[q->front];
    return true;
}

typedef struct {
    ElemType data[MaxSize];
    int front, count;
} QuType;

void InitQueue(QuType *&qu) {
    qu = (QuType *) malloc(sizeof(QuType));
    qu->count = qu->front = 0;
}

void DestroyQueue(QuType *&qu) {
    free(qu);
}

bool EnQueue(QuType *&qu, ElemType e) {
    if (qu->count == MaxSize) {
        return false;
    } else {
        int rear = (qu->front + qu->count) % MaxSize;
        rear = (rear + 1) % MaxSize;
        qu->data[rear] = e;
        qu->count++;
        return true;
    }
}

bool DeQueue(QuType *&qu, ElemType &x) {
    if (qu->count == 0) {
        return false;
    } else {
        qu->front = (qu->front + 1) % MaxSize;
        x = qu->data[qu->front];
        qu->count--;
        return true;
    }
}

bool QueueEmpty(QuType *qu) {
    return qu->count == 0;
}