#include <stdio.h>
#include <malloc.h>
#include <string.h>

int main()
{
    char *p;
    p = (char *)malloc(10 * sizeof(char));
    strcpy(p, "China");
    printf("%c\n", *p);
    printf("%s\n", p);
    free(p);
}