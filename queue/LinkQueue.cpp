#include <stdio.h>
#include <malloc.h>

typedef int ElemType;
typedef struct qnode
{
    ElemType data;      //存放元素1
    struct qnode *next; //下一个结点指针
} DataNode;             //链队数据结点的类型

typedef struct
{
    DataNode *front; //指向队首结点
    DataNode *rear;  //指向队尾结点
} LinkQuNode;        //链队结点的类型

void initQueue(LinkQuNode *&q)
{
    q = (LinkQuNode *)malloc(sizeof(LinkQuNode));
    q->front = q->rear = NULL;
}

void destroyQueue(LinkQuNode *&q)
{
    DataNode *pre = q->front, *p; // pre指向队首结点
    while (pre != NULL)
    {
        p = pre->next;
        while (p != NULL)
        {
            free(pre); //释放pre结点
            pre = p;   // pre、p同步后移
            p = pre->next;
        }
        free(q);
    }
    free(q);
}

bool queueEmpty(LinkQuNode *&q)
{
    return (q->rear == NULL);
}

void enQueue(LinkQuNode *&q, ElemType e)
{
    DataNode *p = (DataNode *)malloc(sizeof(DataNode));
    p->data = e;
    p->next = NULL;
    if (q->rear == NULL) //若链队为空，则新结点既是队首结点又是队尾结点
    {
        q->front = q->rear = p;
    }
    else //若链队不为空
    {
        q->rear->next = p; //将结点p链到队尾，并将rear指向它
        q->rear = p;
    }
}

bool deQueue(LinkQuNode *&q, ElemType &x)
{
    if (q->rear == NULL) //原来队列为空
    {
        return false;
    }
    DataNode *t = q->front;  // t指向首结点
    if (q->front == q->rear) //原来队列中只有一个数据结点时
    {
        q->front = q->rear = NULL;
    }
    else //原来队列中有两个或两个以上结点时
    {
        q->front = q->front->next;
    }
    x = t->data;
    free(t);
    return true;
}

int main()
{
    LinkQuNode *qu;
    initQueue(qu);
    enQueue(qu, 4);
    enQueue(qu, 5);
    enQueue(qu, 6);
    int x;
    deQueue(qu, x);
    printf("%d", x);
}