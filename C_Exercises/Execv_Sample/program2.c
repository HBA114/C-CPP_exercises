#include <stdio.h>
#include <unistd.h>

int main(void)
{
    fflush(stdout);
    printf("\n[Program2] i'm Program2 and i'm working continually...");
    int d = 0;

    while (1)
    {
        printf("\n[Program2] %d. seconds", ++d);
        fflush(stdout);
        sleep(1);
    }
}

/**
 * 
 * hba114 ~/.../Execv_Sample $ ./main.o program2.o 5
 * [main] program2.o will work for 5 seconds...
 * [Program2] i'm Program2 and i'm working continually...
 * [Program2] 1. seconds
 * [Program2] 2. seconds
 * [Program2] 3. seconds
 * [Program2] 4. seconds
 * [Program2] 5. seconds
 * [main] 5 seconds ended, closing program2.o...
 * 
*/
