#include <stdio.h>
#include <unistd.h>

int main( void )
{
        fflush(stdout);
        printf("\n[T2] test2 programıyım ve sürekli çalışıyorum...");
        int d=0;

        while(1) {
                printf("\n[T2] %d. saniye",++d);
                fflush(stdout);
                sleep(1);
        }
}
/*
$ gcc test2.c -o test2.o
$ ./test2.o
[T2] test2 programıyım ve sürekli çalışıyorum...
[T2] 1. saniye
[T2] 2. saniye
[T2] 3. saniye
[T2] 4. saniye
[T2] 5. saniye
[T2] 6. saniye
[T2] 7. saniye
[T2] 8. saniye
[T2] 9. saniye
[T2] 10. saniye
[T2] 11. saniye
[T2] 12. saniye
[T2] 13. saniye^C
$ gcc f191213999.c -o hw1.c
$ ./hw1.o test2.o 3
[hw1] 3sn boyunca test2 çalıştırılacak...
[T2] test2 programıyım ve sürekli çalışıyorum...
[T2] 1. saniye
[T2] 2. saniye
[T2] 3. saniye
[hw1] 3 sn sona erdi test2 kapatılıyor...
 ...
*/