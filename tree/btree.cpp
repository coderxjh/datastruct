#include <stdio.h>
#include <malloc.h>

#define MaxSize 50
typedef char ElemType;
typedef struct node {
    ElemType data;      //数据元素
    struct node *lchild; //指向左孩子结点
    struct node *rchild; //指向右孩子结点pt
} BTNode;

/**
 * 创建二叉树
 * @param b
 * @param str
 */
void CreateBTree(BTNode *&b, char str[]) {
    BTNode *ST[MaxSize], *p;
    int top = -1, k, j;
    b = NULL;
    char ch = str[0];
    while (ch != '\0') {
        switch (ch) {
            case '(':
                top++;
                ST[top] = p;
                k = 1;
                break;
            case ',':
                k = 2;
                break;
            case ')':
                top--;
                break;
            default:
                p = (BTNode *) malloc(sizeof(BTNode *));
                p->data = ch;
                p->lchild = p->rchild = NULL;
                if (b == NULL) {
                    b = p;
                } else {
                    switch (k) {
                        case 1:
                            ST[top]->lchild = p;
                            break;
                        case 2:
                            ST[top]->rchild = p;
                            break;
                    }
                }
        }
        j++;
        ch = str[j];
    }
}

/**
 * 销毁二叉树
 * @param b
 */
void DestroyBTree(BTNode *&b) {
    if (b != nullptr) {
        DestroyBTree(b->lchild);
        DestroyBTree(b->rchild);
        free(b);
    }
}

/**
 * 查找结点
 * @param b
 * @param x
 * @return
 */
BTNode *FindNode(BTNode *b, ElemType x) {
    BTNode *p;
    if (b == nullptr) {
        return nullptr;
    } else if (b->data == x) {
        return b;
    } else {
        p = FindNode(b->lchild, x);
        if (p != nullptr) {
            return p;
        } else {
            return FindNode(b->rchild, x);
        }
    }
}

/**
 * 找左孩子结点
 * @param b
 * @return
 */
BTNode *LchildNode(BTNode *b) {
    return b->lchild;
}

/**
 * 找右孩子结点
 * @param b
 * @return
 */
BTNode *RchildNode(BTNode *b) {
    return b->rchild;
}

/**
 * 求二叉树高度
 * @param b
 * @return
 */
int BTHeight(BTNode *b) {
    int lchildh, rchildh;
    if (b == nullptr) {
        return 0;
    } else {
        lchildh = BTHeight(b->lchild);
        rchildh = BTHeight(b->rchild);
        return lchildh > rchildh ? lchildh + 1 : rchildh + 1;
    }
}

/**
 * 输出二叉树结点
 * @param b
 */
void DispBTree(BTNode *b) {
    if (b != nullptr) {
        printf("%c", b->data);
        if (b->lchild != nullptr || b->rchild != nullptr) {
            printf("(");
            DispBTree(b->lchild);
            if (b->rchild != nullptr)
                printf(",");
            DispBTree(b->rchild);
            printf(")");
        }
    }
}

/**
 * 复制二叉树
 * @param b
 * @param newBt
 * @return
 */
int Copy(BTNode *b, BTNode *&newBt) {
    if (b == nullptr) {
        newBt = nullptr;
        return 0;
    } else {
        newBt = (BTNode *) malloc(sizeof(BTNode *));
        newBt->data = b->data;
        Copy(b->lchild, newBt->lchild);
        Copy(b->rchild, newBt->rchild);
        return 1;
    }
}

/**
 * 求结点总数
 * @param b
 * @return
 */
int NodeCount(BTNode *b) {
    if (b == nullptr) {
        return 0;
    } else {
        return NodeCount(b->lchild) + NodeCount(b->rchild) + 1;
    }
}

/**
 * 求叶子结点个数
 * @param b
 * @return
 */
int LeafNode(BTNode *b) {
    if (b == nullptr) {
        return 0;
    } else if (b->lchild == nullptr && b->rchild == nullptr) { //如果是叶子结点
        return 1;
    } else {
        return LeafNode(b->lchild) + LeafNode(b->rchild);
    }
}

/**
 * 根据先序和中序序列创建二叉树
 * @param pre 存放先序序列
 * @param in 存放后序序列
 * @param n 二叉树结点个数
 * @return 返回二叉树的根结点指针
 */
BTNode *CreateBT1(char pre[], char in[], int n) {
    BTNode *b;
    char *p;
    int k;
    if (n <= 0)return nullptr;
    b = (BTNode *) malloc(sizeof(BTNode));
    b->data = *pre;
    for (p = in; p < in + n; p++) {//在中序序列中找等于*pre字符的位置k
        if (*p == *pre) {
            break;
        }
    }
    k = p - in;
    b->lchild = CreateBT1(pre + 1, in, k);
    b->rchild = CreateBT1(pre + (k + 1), p + 1, n - k - 1);
    return b;
}

/**
 * 根据后序和中序序列创建二叉树
 * @param post 存放后序序列
 * @param in 存放后序序列
 * @param n 二叉树结点个数
 * @return 返回二叉树的根结点指针
 */
BTNode *CreateBT2(char post[], char in[], int n) {
    BTNode *b;
    char *p, *r;
    int k;
    if (n <= 0)return nullptr;
    b = (BTNode *) malloc(sizeof(BTNode));
    r = post + n - 1;
    b->data = *r;
    for (p = in; p < in + n; p++) {
        if (*p == *r) {
            break;
        }
    }
    k = p - in;
    b->lchild = CreateBT2(post, in, k);
    b->rchild = CreateBT2(post + k, p + 1, n - k - 1);
    return b;
}

/**
 * 创建一颗二叉树，约定用户遵照前序遍历的方式输入数据
 * @param b
 */
void CreateBTree2(BTNode *b) {
    char ch;
    scanf("%c", &ch);
    if (' ' == ch) {
        b = NULL;
    } else {
        b = (BTNode *) malloc(sizeof(BTNode));
        b->data = ch;
        CreateBTree2(b->lchild);
        CreateBTree2(b->rchild);
    }
}