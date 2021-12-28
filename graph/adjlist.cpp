//
// Created by 肖江辉 on 2021/12/26.
//
#include <iostream>
#include "graCirQueue.cpp"

#define MVNum 100       //最大顶点数
typedef char VerTexType;   //设顶点的数据类型为字符型
typedef int ArcType;        //假设边的权值类型为整型
//边的结点结构
typedef struct ArcNode {
    int adjvex; //该边所指向的顶点的位置
    struct ArcNode *nextarc; //指向下一条边的指针
    int weight;   //边的相关信息
} ArcNode;
//顶点的结点结构
typedef struct VNode {
    VerTexType data;    //顶点信息
    ArcNode *firstarc;  //指向第一条依附该顶点的边的指针
} VNode;

typedef struct {
    VNode vexs[MVNum];  //邻接表类型
    int vexnum, arcnum;  //当前顶点数和边数
} ALGraph;

int LocateVex(ALGraph G, VerTexType u) {
    for (int i = 0; i < G.vexnum; ++i) {
        if (u == G.vexs[i].data) {
            return i;
        }
    }
    return -1;
}

/**
 * 根据邻接表创建图
 * @param G
 * @return
 */
bool CreateUDG(ALGraph &G) {
    int i, j, w;
    char v1, v2;
    ArcNode *p1, *p2;
    std::cin >> G.vexnum >> G.arcnum;   //输入总顶点数、总边数
    //输入各点，构造头结点表
    for (i = 0; i < G.vexnum; ++i) {
        std::cin >> G.vexs[i].data; //输入顶点值
        G.vexs[i].firstarc = nullptr;   //初始化表头结点的指针域
    }
    //输入各点，构造邻接表
    for (int k = 0; k < G.arcnum; ++k) {
        std::cin >> v1 >> v2 >> w;   //输入一条边依附的两个顶点
        i = LocateVex(G, v1);
        j = LocateVex(G, v2);
        //删除以下代码，为入度边表，即逆邻接表
        p1 = new ArcNode;   //生成一个新的边结点p1
        p1->adjvex = j;     //邻接点序号为j
        p1->weight = w;     //边<v1,v2>的权值置为w
        p1->nextarc = G.vexs[i].firstarc;
        G.vexs[i].firstarc = p1;    //将新结点p1插入顶点vi的边表头部

        //删除以下代码，为出度边表，即邻接表
//        p2 = new ArcNode;   //生成一个新的边结点p2
//        p2->adjvex = i;     //邻接点序号为i
//        p2->weight = w;     //置<v1,v2>的对称边<v2,v1>的权值为w
//        p2->nextarc = G.vexs[j].firstarc;
//        G.vexs[j].firstarc = p2;    //将新结点p2插入顶点vj的边表头部
    }
    return true;
}

int visited[MVNum];

/**
 * 根据邻接表的深度遍历算法
 * @param G
 * @param v
 */
void DFS(ALGraph G, int v) {
    ArcNode *p;
    std::cout << v << "\n"; //访问第v个顶点
    visited[v] = 1;
    p = G.vexs[v].firstarc;
    while (p != nullptr) {
        if (visited[p->adjvex] == 0) {
            DFS(G, p->adjvex);
        }
        p = p->nextarc;
    }
}

/**
 * 根据邻接表的广度遍历算法
 * @param G
 * @param v
 */
void BFS(ALGraph G, int v) {
    int visited[MVNum],w;
    ArcNode *p;
    CirSqQueue *queue;
    initQueue(queue);
    std::cout << v << "\n"; //访问第v个顶点
    visited[v] = 1; //将第v个顶点置为以访问
    enQueue(queue, v);  //将第v个顶点入队
    while (!queueEmpty(queue)) {
        deQueue(queue, w);
        p = G.vexs[w].firstarc; //指向第w个顶点的第一个邻接点
        while (p != nullptr) {  //如果邻接点存在，循环执行
            if (visited[p->adjvex] == 0) {  //如果邻接点没有访问过
                std::cout << p->adjvex << "\n"; //访问邻接点
                visited[p->adjvex] = 1; //将邻接点置为以访问
                enQueue(queue, p->adjvex);  //将邻接点入队
            }
            p = p->nextarc; //找下一个邻接点
        }
    }
}

int main() {
    ALGraph G;
    CreateUDG(G);
    DFS(G, 0);
    std::cout << "<--------------->\n";
    BFS(G, 0);
}