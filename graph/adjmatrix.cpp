//
// Created by 肖江辉 on 2021/12/26.
//
#include <iostream>

#define MaxInt 32767    //表示极大值，即无穷大
#define MVNum 100       //最大顶点数
typedef char VerTexType;   //设顶点的数据类型为字符型
typedef int ArcType;        //假设边的权值类型为整型
typedef struct {
    VerTexType vexs[MVNum];     //顶点表
    ArcType arcs[MVNum][MVNum]; //邻接矩阵
    int vexnum, arcnum;  //当前顶点数和边数
} AMGraph;

/**
 * 在图中查找顶点的索引
 * @param G
 * @param u
 * @return
 */
int LocateVex(AMGraph G, VerTexType u) {
    for (int i = 0; i < G.vexnum; ++i) {
        if (u == G.vexs[i]) {
            return i;
        }
    }
    return -1;
}

bool CreateUDN(AMGraph &G) {
    VerTexType v1, v2;
    ArcType i, j, w;
    std::cin >> G.vexnum >> G.arcnum;   //输入总顶点数、总边数
    //输入各点，构造顶点表
    for (i = 0; i < G.vexnum; ++i) {
        std::cin >> G.vexs[i];  //依次输入点的信息
    }
    //初始化邻接矩阵
    for (i = 0; i < G.vexnum; ++i) {
        for (j = 0; j < G.vexnum; ++j) {
            G.arcs[i][j] = MaxInt;  //边的权值均置为极大值
        }
    }
    //构造邻接矩阵
    for (int k = 0; k < G.arcnum; ++k) {
        std::cin >> v1 >> v2 >> w;  //输入一条边所依附的顶点及边的权值
        //确定v1和v2在G中的位置
        i = LocateVex(G, v1);
        j = LocateVex(G, v2);
        G.arcs[i][j] = w;   //边<v1,v2>的权值置为w
        G.arcs[j][i] = G.arcs[i][j];    //置<v1,v2>的对称边<v2,v1>的权值为w
    }
    return true;
}