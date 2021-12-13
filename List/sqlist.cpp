#include <stdio.h>
#include <malloc.h>
#define MaxSize 50
typedef int ElemType;
typedef struct
{
    //数组动态分配
    ElemType *data;
    int length;
} SqList;

// typedef struct
// {
// 数组静态分配
//     ElemType data[MaxSize];
//     int length;
// } SqList;

/**
 * 创建顺序表
 **/
void CreateList(SqList *&L, ElemType a[], int n)
{
    int i = 0, k = 0;
    L = (SqList *)malloc(sizeof(SqList));
    //动态的为数组分配内存
    L->data = (ElemType *)malloc(sizeof(ElemType *) * MaxSize);
    while (i < n)
    {
        L->data[k] = a[i];
        i++;
        k++;
    }
    L->length = k;
}
/**
 *  初始化顺序表
 **/
void InitList(SqList *&L)
{
    L = (SqList *)malloc(sizeof(SqList));
    L->length = 0;
    //动态的为数组分配内存
    L->data = (ElemType *)malloc(sizeof(ElemType *) * MaxSize);
}

/**
 * 销毁顺序表
 **/
void DestoryList(SqList *&L)
{
    free(L);
}

/**
 * 线性表是否为空
 */
bool ListEmpty(SqList *L)
{
    return (L->length == 0);
}

/**
 * 输出线性表的长度
 */
int ListLength(SqList *L)
{
    return (L->length);
}

/**
 * 输出线性表中的数据
 */
void DispList(SqList *L)
{
    for (int i = 0; i < L->length; i++)
    {
        printf("索引:%d   值：%d\n", i, L->data[i]);
    }
}

/**
 * 根据索引查找元素
 */
int GetElem(SqList *L, int i)
{
    if (i < 0 || i > L->length - 1)
    {
        return -1;
    }
    return L->data[i];
}

/**
 * 根据元素值查找元素的索引
 */
int LocateElem(SqList *L, ElemType e)
{
    for (int i = 0; i < L->length; i++)
    {
        if (e == L->data[i])
        {
            return i;
        }
    }
    return -1;
}

/**
 * 根据索引插入一个元素
 */
bool ListInsert(SqList *&L, int i, ElemType e)
{
    if (i < 0 || i > L->length || L->length == MaxSize)
        return false;
    for (int j = L->length; j > i; j--)
        L->data[j] = L->data[j - 1];
    L->data[i] = e;
    L->length++;
    return true;
}

/**
 * 根据索引删除一个元素
 */
bool ListDelete(SqList *&L, int i)
{
    if (i < 0 || i > L->length - 1)
        return false;
    for (int j = i; j < L->length - 1; j++)
        L->data[j] = L->data[j + 1];
    L->length--;
    return true;
}

void delnodel(SqList *&L, ElemType x)
{
    int k = 0;
    for (int i = 0; i < L->length; i++)
    {
        if (L->data[i] != x)
        {
            L->data[k] = L->data[i];
            k++;
        }
    }
    L->length = k;
}

void delnodel2(SqList *&L, ElemType x)
{
    int k = 0;
    for (int i = 0; i < L->length; i++)
    {
        if (L->data[i] == x)
            k++;
        else
            L->data[i - k] = L->data[i];
    }
    L->length -= k;
}

int main()
{
    SqList *list;
    int arr[] = {19, 20, 21, 21, 21, 21};
    CreateList(list, arr, sizeof(arr) / sizeof(int));
    DispList(list);
    printf("-------------\n");
    // DestoryList(list);
    // DispList(list);
    ListInsert(list, 4, 421);
    DispList(list);
    // printf("删除后===>\n");
    // ListDelete(list, 3);
    // delnodel(list, 21);
    // DispList(list);
}