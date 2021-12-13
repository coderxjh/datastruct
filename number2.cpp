#include <stdio.h>

int main()
{
    int x, y, z;
    int max(int a, int b, int c);
    scanf("%d%d%d", &x, &y, &z);
    max(x, y, z);
    return 0;
}

int max(int a, int b, int c)
{
    if (a > b)
    {
        if (b > c)
        {
            printf("%d,%d,%d", c, b, a);
        }
        else if (a > c)
        {
            printf("%d,%d,%d", b, c, a);
        }
        else
        {
            printf("%d,%d,%d", b, a, c);
        }
    }
    else
    {
        if (b > c)
        {
            printf("%d,%d,%d", a, c, b);
        }
        else
        {
            printf("%d,%d,%d", a, b, c);
        }
    }
    return 0;
}