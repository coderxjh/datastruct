//
// Created by 肖江辉 on 2021/12/11.
//
#include "btCirQueue.cpp"

/**
 * 先序遍历
 * @param p
 */
void PreOrder(BTNode *p) {
    if (p != NULL) {
        printf("%c", p->data);
        PreOrder(p->lchild);
        PreOrder(p->rchild);
    }
}

/**
 * 中序遍历
 * @param p
 */
void InOrder(BTNode *p) {
    if (p != NULL) {
        InOrder(p->lchild);
        printf("%c", p->data);
        InOrder(p->rchild);
    }
}

/**
 * 后序遍历
 * @param p
 */
void PostOrder(BTNode *p) {
    if (p != NULL) {
        PostOrder(p->lchild);
        PostOrder(p->rchild);
        printf("%c", p->data);
    }
}

/**
 * 先序非递归遍历算法1
 * @param b
 */
void PreOrder1(BTNode *b) {
    BTNode *p;
    SqStack *s;
    InitStack(s);
    if (b != NULL) {
        Push(s, b);     //根结点进栈
        while (!StackEmpty(s)) {    //栈不为空时循环
            Pop(s, p);  //出栈结点p并访问
            printf("%c", p->data);
            if (p->rchild != NULL)  //有右孩子时将其进栈
                Push(s, p->rchild);
            if (p->lchild != NULL)  //有左孩子时将其进栈
                Push(s, p->lchild);
        }
        printf("\n");
    }
    DestroyStack(s);
}

/**
 * 先序非递归遍历算法2
 * @param b
 */
void PreOrder2(BTNode *b) {
    BTNode *p;
    SqStack *s;
    InitStack(s);
    p = b;
    int n = 0;
    while (!StackEmpty(s) || p != NULL) {
        //对于结点p及其所有的左下结点，边访问边进栈
        while (p != NULL) {
            //访问结点p，将其进栈
            printf("%c", p->data);
            Push(s, p);
            p = p->lchild;
            n++;
        }
        //此时栈顶结点(已访问)没有左孩子，或者左子树已遍历过
        if (!StackEmpty(s)) {
            Pop(s, p);
            p = p->rchild;
        }
    }
    printf("\n");
    printf("PreOrder2===>n=%d\n", n);
}

/**
 * 中序遍历非递归算法
 */
void InOrder1(BTNode *b) {
    BTNode *p;
    SqStack *s;
    InitStack(s);
    p = b;
    while (!StackEmpty(s) || p != nullptr) {
        while (p != nullptr) {
            Push(s, p);
            p = p->lchild;
        }
        if (!StackEmpty(s)) {
            Pop(s, p);
            printf("%c", p->data);
            p = p->rchild;
        }
    }
    printf("\n");
    DestroyStack(s);
}

/**
 * 后序遍历非递归算法
 */
void PostOrder1(BTNode *b) {
    BTNode *p, *r;
    SqStack *s;
    InitStack(s);
    p = b;
    int n;
    bool flag;
    do {
        while (p != nullptr) {
            Push(s, p);
            p = p->lchild;
        }
        flag = true;    // flag为真表示正在处理栈顶结点
        r = nullptr;   // r指向刚访问的结点，初始时为空
        while (!StackEmpty(s) && flag) {
            n++;
            // 取出当前的栈顶结点p
            GetTop(s, p);
            // 若结点p的右孩子为空或者为刚刚访问过的结点
            if (p->rchild == r) {
                printf("%c", p->data);
                Pop(s, p);
                r = p;  // r指向刚访问过的结点
            } else {
                p = p->rchild;  //转向处理栈顶结点的右子树
                flag = false;   //表示当前不是处理栈顶结点
            }
        }
    } while (!StackEmpty(s));
    printf("\n");
    printf("n=%d\n", n);
    DestroyStack(s);
}

/**
 * 例:7.17
 * 利用后序遍历非递归算法，输出从根结点到每个叶子结点的路径逆序列
 * @param b
 */
void AllPath1(BTNode *b) {
    BTNode *p, *r;
    SqStack *s;
    InitStack(s);
    p = b;
    bool flag;
    do {
        while (p != NULL) {
            Push(s, p);
            p = p->lchild;
        }
        flag = true;    // flag为真表示正在处理栈顶结点
        r = nullptr;   // r指向刚访问的结点，初始时为空
        while (!StackEmpty(s) && flag) {
            // 取出当前的栈顶结点p
            GetTop(s, p);
            // 若结点p的右孩子为空或者为刚刚访问过的结点
            if (p->rchild == r) {
                // 若为叶子结点
                if (p->lchild == NULL && p->rchild == NULL) {
                    // 输出栈中的所有结点值
                    for (int i = s->top; i > 0; i--)
                        printf("%c->", s->data[i]->data);
                    printf("%c", s->data[0]->data);
                    printf("\n");
                }
                Pop(s, p);
                r = p;  // r指向刚访问过的结点
            } else {
                p = p->rchild;  //转向处理栈顶结点的右子树
                flag = false;   //表示当前不是处理栈顶结点
            }
        }
    } while (!StackEmpty(s));
    printf("\n");
    DestroyStack(s);
}

/**
 * 层次遍历
 * @param b
 */
void LevelOrder(BTNode *b) {
    BTNode *p;
    SqQueue *queue;
    initQueue(queue);
    if (b != NULL) {
        // 先将根结点入队
        enQueue(queue, b);
        // 队列不为空时循环
        while (!queueEmpty(queue)) {
            // 出队结点p
            deQueue(queue, p);
            // 访问结点p
            printf("%c", p->data);
            //有左孩子时将其入队
            if (p->lchild != nullptr) {
                enQueue(queue, p->lchild);
            }
            //有右孩子时将其入队
            if (p->rchild != nullptr) {
                enQueue(queue, p->rchild);
            }
        }
    }
    printf("\n");
    destroyQueue(queue);
}

int main() {
    BTNode *btNode;
    CreateBTree(btNode, "A(B(D(,G)),C(E,F))");
//    DispBTree(btNode);
//    printf("\n");
//    AllPath1(btNode);
//    LevelOrder(btNode);
//    printf("%d", NodeCount(btNode));
//    printf("%d", LeafNode(btNode));
//    CreateBT("ABDGCEF", "DGBAECF", 7);
    BTNode *bt = CreateBT2("GDBEFCA", "DGBAECF", 7);
    DispBTree(bt);
    return 0;
}