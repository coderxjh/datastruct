#include <stdio.h>
#include <malloc.h>
typedef int ElemType;
typedef struct LNode
{
    ElemType data;
    struct LNode *next;
} LinkNode;

/**
 * 使用头插法创建单链表
 */
void CreateListF(LinkNode *&L, ElemType a[], int n)
{
    LinkNode *s;
    L = (LinkNode *)malloc(sizeof(LinkNode));
    L->next = NULL;
    for (int i = 0; i < n; i++) //循环建立数据节点
    {
        s = (LinkNode *)malloc(sizeof(LinkNode));
        s->data = a[i];
        s->next = L->next; //每次循环，都将当前结点s插入到原首结点之前，头节点之后
        L->next = s;
    }
}

/**
 * 使用尾插法创建单链表
 */
void CreateListR(LinkNode *&L, ElemType a[], int n)
{
    LinkNode *s, *r;
    L = (LinkNode *)malloc(sizeof(LinkNode));
    r = L;                      //r始终指向尾结点，初始时指向头结点
    for (int i = 0; i < n; i++) //循环建立数据节点
    {
        s = (LinkNode *)malloc(sizeof(LinkNode));
        s->data = a[i];
        r->next = s; //将结点s插入到结点r之后
        r = s;
    }
    r->next = NULL; //尾结点的next域置为NULL
}

/**
 * 初始化单链表
 */
void InitList(LinkNode *&L)
{
    L = (LinkNode *)malloc(sizeof(LinkNode));
    L->next = NULL;
}

/**
 * 销毁单链表
 */
void DestroyList(LinkNode *&L)
{
    LinkNode *pre = L, *p = L->next;
    while (p != NULL)
    {
        free(pre);
        pre = p;
        p = pre->next;
    }
    free(pre);
}

/**
 * 判断链表是否为空
 */
bool ListEmpty(LinkNode *L)
{
    return L->next == NULL;
}

/**
 * 返回单链表中数据结点的个数
 */
int ListLength(LinkNode *L)
{
    int n = 0;
    LinkNode *p = L;
    while (p->next != NULL)
    {
        n++;
        p = p->next;
    }
    return n;
}
/**
 * 遍历单链表
 */
void DisList(LinkNode *L)
{
    LinkNode *p = L->next;
    while (p != NULL)
    {
        printf("%d\t", p->data);
        p = p->next;
    }
    printf("\n");
}

int main()
{
    LinkNode *L;
    int arr[] = {12, 54, 34, 23, 52, 44, 67, 88, 7, 34, 64};
    // CreateListF(L, arr, sizeof(arr) / sizeof(int));
    CreateListR(L, arr, sizeof(arr) / sizeof(int));
    DisList(L);
    printf("%p\n", &L);
    DestroyList(L);
    printf("%p\n", &L);
    // int count = ListLength(L);
    // printf("%d\n", count);
    // bool flag = ListEmpty(L);
    // printf("%d", flag);
    return 0;
}