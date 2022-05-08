#include <stdio.h>
#include <stdlib.h>

int main(){
    int x = 5;
    int *ptr = &x;
    printf("x'in degeri(The value of x)................. = %d\n",x);
    printf("ptr'nin degeri(The value of ptr)............ = %d\n",ptr);
    printf("*ptr'nin degeri(The value of *ptr).......... = %d\n",*ptr);
    printf("&x'in adresi(The adress of &x).............. = %d\n",&x);
    printf("&ptr'nin adresi(The adress of &ptr)......... = %d\n",&ptr);

    return 0;
}