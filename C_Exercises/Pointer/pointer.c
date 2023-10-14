#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x = 5;
    int *ptr = &x;
    printf("The value of x.......... = %d\n", x);
    printf("The value of ptr........ = %d\n", ptr);
    printf("The value of *ptr....... = %d\n", *ptr);
    printf("The address of &x....... = %d\n", &x);
    printf("The address of &pt)..... = %d\n", &ptr);

    return 0;
}
