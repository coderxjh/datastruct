#include <stdio.h>
#include <malloc.h>

typedef char ElemType;
typedef struct linknode {
    ElemType data;         //数据域
    struct linknode *next; //指针域
} LinkStNode;              //链栈结点类型

/**
 * 初始化栈
 */
void InitStack(LinkStNode *&s) {
    s = (LinkStNode *) malloc(sizeof(LinkStNode));
    s->next = NULL;
}

/**
 * 销毁栈
 */
void DestroyStack(LinkStNode *&s) {
    LinkStNode *pre = s, *p = pre->next; // pre指向头节点,p指向首结点
    while (p != NULL) {                 //循环到p为空
        free(pre); //释放pre结点
        pre = p;   // pre、p同步后移
        p = pre->next;
    }
    free(pre); //此时pre指向尾节点，释放其空间
}

/**
 * 判断栈是否为空
 */
bool StackEmpty(LinkStNode *s) {
    return s->next == NULL;
}

/**
 * 进栈
 */
void Push(LinkStNode *&s, ElemType e) {
    LinkStNode *p = (LinkStNode *) malloc(sizeof(LinkStNode)); //新建结点p
    p->data = e;                                              //存放元素p
    p->next = s->next;                                        //将p结点插入作为首结点
    s->next = p;
}

/**
 * 出栈
 */
bool Pop(LinkStNode *&s, ElemType &e) {
    if (s->next == NULL) //栈空的情况
    {
        return false;
    }
    LinkStNode *p = s->next; // p指向首结点
    e = p->data;             //提取首结点值
    s->next = p->next;       //删除首结点
    free(p);                 //释放被删结点的存储空间
    return true;
}

/**
 * 取栈顶元素
 */
bool GetTop(LinkStNode *s, ElemType &e) {
    if (s->next == NULL)
        return false;
    e = s->next->data;
    return true;
}

/**
 * 例3.5
 * 判断表达式中括号是否配对
 */
bool Match(char exp[], int n) {
    char e;
    bool match = true;
    LinkStNode *st;
    InitStack(st);                       //初始化链栈
    for (int i = 0; i < n && match; i++) //扫描exp中所有字符
    {
        if (exp[i] == '(') //当前字符为左括号，将其进栈
            Push(st, exp[i]);
        else if (exp[i] == ')') //当前字符为右括号
        {
            if (GetTop(st, e)) //成功获取到栈顶元素e
            {
                if (e != '(')      //栈顶元素不为'('时
                    match = false; //表示不匹配
                else               //栈顶元素为'('时
                    Pop(st, e);    //将栈顶元素出栈
            } else
                match = false; //无法取栈顶元素时表示不匹配
        }
    }
    if (!StackEmpty(st)) //栈不空时表示不匹配
        match = false;
    DestroyStack(st); //销毁栈
    return match;
}

int main() {
    // LinkStNode *s;
    // InitStack(s);
    // Push(s, 'a');
    // char elem;
    // GetTop(s, elem);
    // printf("%c", elem);
    char exp[] = {'(', '(', ')', ')'};
    printf("%d", Match(exp, 4));
    return 0;
}