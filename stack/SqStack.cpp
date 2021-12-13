#include <stdio.h>
#include <malloc.h>

#define MaxSize 30
typedef char ElemType;
typedef struct {
    ElemType data[MaxSize]; //存放栈中的数据元素
    int top;    // 栈顶指针，即存放栈顶元素在data数组中的下标
} SqStack;  //顺序栈类型

/**
 * 初始化栈
 */
void InitStack(SqStack *&s) {
    s = (SqStack *) malloc(sizeof(SqStack)); //分配一个顺序栈空间，首地址存放在s中
    s->top = -1;                            //栈顶指针置为-1
}

/**
 * 销毁栈
 */
void DestroyStack(SqStack *&s) {
    free(s);
}

/**
 * 判断栈是否为空
 */
bool StackEmpty(SqStack *s) {
    return s->top == -1;
}

/**
 * 进栈
 */
bool Push(SqStack *&s, ElemType e) {
    if (s->top == MaxSize - 1) //栈满的情况，即栈上溢出
        return false;
    s->top++;            // 栈顶指针增1
    s->data[s->top] = e; //元素e放在栈顶指针处
    return true;
}

/**
 * 出栈
 */
bool Pop(SqStack *&s, ElemType &e) {
    if (s->top == -1) //栈为空的情况下，即栈下溢出
        return false;
    e = s->data[s->top]; //取栈顶元素
    s->top--;            //栈顶指针减1
    return true;
}

/**
 * 取栈顶元素
 */
bool GetTop(SqStack *s, ElemType &e) {
    if (s->top == -1)
        return false;
    e = s->data[s->top];
    return true;
}

/**
 * 例3.4
 * 利用顺序栈判断一个字符串是否为对称串
 */
bool symmetry(ElemType str[]) {
    ElemType e;
    SqStack *s;                     // 定义顺序栈指针
    InitStack(s);                   // 初始化栈
    for (int i = 0; i != '\0'; i++) // 将所有元素进栈
        Push(s, str[i]);
    for (int i = 0; i != '\0'; i++) //处理str的所有字符
    {
        Pop(s, e);       // 退栈元素e
        if (e != str[i]) // 若e与当前字符不同表示不是对称串
        {
            DestroyStack(s); // 销毁栈
            return false;    //返回假
        }
    }
    DestroyStack(s);
    return true;
}

int main() {
    SqStack *s;
    InitStack(s);
    Push(s, 'a');
    printf("%d\n", s->top);
    printf("%c\n", s->data[s->top]);
    return 0;
}