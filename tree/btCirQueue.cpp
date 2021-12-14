//
// Created by 肖江辉 on 2021/12/11.
//
#include <malloc.h>
#include "btSqStack.cpp"
typedef struct {
    BTNode *data[MaxSize];
    int front, rear;
} SqQueue;

void initQueue(SqQueue *&q) {
    q = (SqQueue *) malloc(sizeof(SqQueue));
    q->rear = q->front = 0;
}

void destroyQueue(SqQueue *&q) {
    free(q);
}

bool queueEmpty(SqQueue *q) {
    return q->front == q->rear;
}

bool enQueue(SqQueue *&q, BTNode *e) {
    if ((q->rear + 1) % MaxSize == q->front) {
        return false;
    }
    q->rear = (q->rear + 1) % MaxSize;
    q->data[q->rear] = e;
    return true;
}

bool deQueue(SqQueue *&q, BTNode *&x) {
    if (q->front == q->rear) {
        return false;
    }
    q->front = (q->front + 1) % MaxSize;
    x = q->data[q->front];
    return true;
}

