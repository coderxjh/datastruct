#include <stdio.h>
#include <malloc.h>
#define MaxSize 50
typedef int ElemType;
typedef struct
{
    ElemType data[MaxSize]; //存放队中元素
    int front, rear;        //对头和队尾指针
} SqQueue;                  //顺序队类型

void InitQueue(SqQueue *&q)
{
    q = (SqQueue *)malloc(sizeof(SqQueue));
    q->front = q->rear = -1;
}

void DestroyQueue(SqQueue *&q)
{
    free(q);
}
bool QueueEmpty(SqQueue *&q)
{
    return (q->front == q->rear);
}

bool enQueue(SqQueue *&q, ElemType e)
{
    if (q->rear == MaxSize - 1)
    {
        return false;
    }
    q->rear++;
    q->data[q->rear] = e;
    return true;
}

bool deQueue(SqQueue *&q, ElemType &x)
{
    if (q->front == q->rear)
    {
        q->front = q->rear = 0;
        return false;
    }
    q->front++;
    x = q->data[q->front];
    return true;
}

int main()
{
    SqQueue *q;
    InitQueue(q);
    enQueue(q, 5);
    enQueue(q, 7);
    enQueue(q, 6);
    int x;
    deQueue(q, x);
    deQueue(q, x);
    printf("%d", x);
}