#include <stdio.h>

int main(){
    int var =10;
    int *p=&var;
    printf("var的内存地址：%p\n",&var);
    printf("var变量：%d\n",var);
    printf("指针变量p：%d",*p);
    return 0;
}