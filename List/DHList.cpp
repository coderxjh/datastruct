#include <stdio.h>
#include <malloc.h>
#define MaxCol 10 //大列数

typedef int ElemType;
typedef struct Node1 //定义数据结点类型
{
    ElemType data[MaxCol]; //存放一行的数据
    struct Node1 *next;    //指向后继数据结点
} DList;                   //行结点类型

typedef struct Node2 //定义头结点类型
{
    int Row, Col; //行数和列数
    DList *next;  //指向第一个数据结点
} HList;          //头结点类型

void CreateTable(HList *&h)
{
    DList *r, *s;
    h = (HList *)malloc(sizeof(HList));
    h->next = NULL;
    printf("表的行数,列数：");
    scanf("%d%d", &h->Row, &h->Col);
    for (int i = 0; i < h->Row; i++)
    {
        printf("  第%d行：", i + 1);
        s = (DList *)malloc(sizeof(DList));
        for (int j = 0; j < h->Col; j++)
        {
            scanf("%d", &s->data[j]);
        }
        if (h->next == NULL)
        {
            h->next = s;
        }
        else
        {
            r->next = s;
        }
        r = s;
    }
    r->next = NULL;
}

void DestroyTable(HList *&h)
{
    DList *pre = h->next, *p = pre->next;
    while (p != NULL)
    {
        free(pre);
        pre = p;
        p = pre->next;
    }
    free(pre);
    free(h);
}

void DispTable(HList *h)
{
    DList *p = h->next;
    while (p != NULL)
    {
        for (int i = 0; i < h->Col; i++)
        {
            printf("%4d", p->data[i]);
        }
        printf("\n");
        p = p->next;
    }
}

void LinkTable(HList *h1, HList *h2, HList *&h)
{
    int i, j, k;
    DList *p = h1->next, *q, *r, *s;
    printf("连接的字段是:第1个表序号，第2个表序号：");
    scanf("%d%d", &i, &j);
    h = (HList *)malloc(sizeof(HList));
    h->Row = 0;
    h->Col = h1->Col + h2->Col;
    h->next = NULL;
    while (p != NULL)
    {
        q = h2->next;
        while (q != NULL)
        {
            if (p->data[i - 1] = q->data[j - 1])
            {
                s = (DList *)malloc(sizeof(DList));
                for (k = 0; i < h1->Col; i++)
                    s->data[k] = p->data[k];
                for (k = 0; i < h2->Col; i++)
                    s->data[h1->Col + k] = q->data[k];
                if (h->next == NULL)
                    h->next = s;
                else
                    r->next = s;
                r = s;
                h->Row++;
            }
            q = q->next;
        }
        p = p->next;
    }
    r->next = NULL;
}

int main()
{
    HList *h1, *h2, *h;
    printf("表1:\n");
    CreateTable(h1);
    DispTable(h1);
    printf("表2:\n");
    CreateTable(h2);
    DispTable(h2);
    LinkTable(h1, h2, h);
    printf("连接结果表:\n");
    DispTable(h);
    DestroyTable(h1);
    DestroyTable(h2);
    DestroyTable(h);
    return 0;
}