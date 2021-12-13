#define M 8
#define N 8
#define MaxSize 7
typedef int ElemType;
typedef struct {
    int r;      //行号
    int c;      //列号
    ElemType d; //元素值
} TupNode;      //三元组类型

typedef struct {
    int rows; //行数
    int cols; //列数
    int nums; //非零元素个数
    TupNode data[MaxSize];
} TSMatrix; //三元组顺序表的类型

/**
 * 从二维稀疏矩阵创建三元组表示
 */
void CreateMat(TSMatrix &t, ElemType A[M][N]) {
    t.rows = M;
    t.cols = N;
    t.nums = 0;
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            if (A[i][j] != 0) {
                t.data[t.nums].r = i;
                t.data[t.nums].c = j;
                t.data[t.nums].d = A[i][j];
                t.nums++;
            }
        }
    }
}

/**
 * 三元组元素的赋值
 */
bool Value(TSMatrix &t, ElemType x, int i, int j) {
    if (i >= t.rows || j >= t.cols) // i,j参数越界
    {
        return false;   //返回false
    }
}