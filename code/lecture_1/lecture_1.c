#include <stdio.h>

int main()
{
        int a[10];
        int i = 0;
        for (; i < 10; ++i)
        {
                printf("a[%d] = %p \n", i, &a[i]);
        }
        return 0;
}