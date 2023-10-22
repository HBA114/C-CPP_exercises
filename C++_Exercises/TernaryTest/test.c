#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    if (argc != 3)
    {
        printf("Usage: %s number1 number2\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    int num1 = atoi(argv[1]);
    int num2 = atoi(argv[2]);
    int themax;

    themax = (num1 > num2 ? num1 : num2);

    printf("max of %d and %d is %d\n", num1, num2, themax);

    return 0;
}
