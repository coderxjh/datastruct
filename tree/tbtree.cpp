#include <malloc.h>
#include <stdio.h>

//
// Created by 肖江辉 on 2021/12/13.
//
typedef struct node {
    char data;
    int ltag, rtag;
    struct node *lchild;
    struct node *rchild;
} TBTNode;

void CreateBTree(TBTNode *&b, const char str[]) {
    TBTNode *TBT[100], *p;
    int top = -1, k, j;
    b = nullptr;
    char ch = str[0];
    while (ch != '\0') {
        switch (ch) {
            case '(':
                top++;
                TBT[top] = p;
                k = 1;
                break;
            case ',':
                k = 2;
                break;
            case ')':
                top--;
                break;
            default:
                p = (TBTNode *) malloc(sizeof(TBTNode *));
                p->data = ch;
                p->lchild = p->rchild = nullptr;
                if (b == nullptr) {
                    b = p;
                } else {
                    switch (k) {
                        case 1:
                            TBT[top]->lchild = p;
                            break;
                        case 2:
                            TBT[top]->rchild = p;
                            break;
                    }
                }
        }
        j++;
        ch = str[j];
    }
}

TBTNode *pre;

void Threaded(TBTNode *&p) {
    if (p != nullptr) {
        Threaded(p->lchild);
        if (p->lchild == nullptr) {
            p->lchild = pre;
            p->ltag = 1;
        } else
            p->ltag = 0;
        if (pre->rchild == nullptr) {
            pre->rchild = p;
            pre->rtag = 1;
        } else
            pre->rtag = 0;
        pre = p;
        Threaded(p->rchild);
    }
}

TBTNode *ThreadedTBTree(TBTNode *b) {
    auto *root = new TBTNode;
    root->ltag = 0;
    if (b == nullptr) {
        root->lchild = root;
    } else {
        root->lchild = b;
        pre = root;
        Threaded(b);
        pre->rchild = root;
        pre->rtag = 1;
        root->rtag = 1;
        root->rchild = pre;
    }
    return root;
}

/**
 * 遍历线索二叉树
 */
void ThInOrder(TBTNode *tb) {
    TBTNode *p = tb->lchild;
    while (p != tb) {
        while (p->ltag == 0) p = p->lchild;
        printf("%c", p->data);
        while (p->rtag == 1 && p->rchild != tb) {
            p = p->rchild;
            printf("%c", p->data);
        }
        p = p->rchild;
    }
}


int main() {
    TBTNode *b;
    CreateBTree(b, "A(B(D(,G)),C(E,F))");
    TBTNode *root = ThreadedTBTree(b);
    ThInOrder(root);
}