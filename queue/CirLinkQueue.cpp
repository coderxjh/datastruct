#include <stdio.h>
#include <malloc.h>

typedef int ElemType;
typedef struct LNode {
    ElemType data;
    LNode *next;
} LinkNode;

void initQueue(LinkNode *&rear) //初始化算法
{
    rear = NULL;
}

void enQueue(LinkNode *&rear, ElemType e) //进队算法
{
    LinkNode *p;
    p = (LinkNode *) malloc(sizeof(LinkNode)); //创建新结点
    p->data = e;
    if (rear == NULL) //原链队为空
    {
        p->next = p; //改为循环链表
        rear = p;    // rear指向新结点
    } else //原链队不为空
    {
        p->next = rear->next; //将p结点插入到rear结点之后
        rear->next = p;       //改为循环链表
        rear = p;             // rear指向新结点
    }
}

bool deQueue(LinkNode *&rear, ElemType &x) //出队算法
{
    if (rear == NULL) //队空
    {
        return false;
    } else if (rear->next == rear) //原队中只有一个结点
    {
        x = rear->data;
        free(rear);
        rear = NULL; //让rear为空链表
    } else //原队中有两个或两个以上的结点
    {
        LinkNode *t = rear->next; // t指向对头结点
        x = t->data;
        rear->next = t->next; //删除t结点
        free(t);              //释放结点空间
    }
    return true;
}

bool queueEmpty(LinkNode *rear) {
    return rear == NULL;
}

int main() {
    LinkNode *p;
    initQueue(p);
    enQueue(p, 4);
    enQueue(p, 5);
    enQueue(p, 6);
    int x;
    deQueue(p, x);
    printf("%d\n", x);
    deQueue(p, x);
    printf("%d\n", x);
}