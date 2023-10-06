/*
    This code works on Unix based Operating Systems. Linux, MacOs etc.
    This program runs another program (command line parameter) for seconds (command line parameter).
    Sample command line:
        - Compiling main.c
            gcc main.c -o main.o
        -Compiling program2.c
            gcc program2.c -o program2.o
        - Executing
            ./main.o program2.o 3
    With this 3 commands you run main program and main program runs 'program2' program for 15 seconds
*/

#include <stdio.h>  // In here i included standart input output header file
#include <stdlib.h> // In here i included standart library header file
#include <unistd.h> // In here i included unistd.h header file which contains fork and alarm functions.
#include <wait.h>   // In here i included wait.h header file for waiting the child process

void execute_program(int second, char *arg)
{                     // In here i declared a function called execute_program which gets parameters time and program name.
    int child_status; // In here i declared an integer variable which knows child processes status.
    if (fork() == 0)
    {                              // In here i called fork in an if condition and if process is child process :
        char *args[] = {"", NULL}; // I declared a char array for declaring parameters which necessary for program which we run with this function.
        alarm(second);             // In here i called the alarm function with a parameter second which i get from user.
        execv(arg, args);          // In here i called the execv function with the parameters which i get from user.
                                   // execv function runs the program which user define in command line.
    }
    else                     // If child processes not terminated:
        wait(&child_status); // I called wait function with parameter child_status for waiting the child processes terminate.
}

int main(int argc, char **argv)
{                                           // In here i declared main function which contains main program codes.
    int second = strtol(argv[2], NULL, 10); // In here i declared an int variable which gets value from 3. parameter in the command line.
    int i = 0;                              // In here i declared an int variable for counting the length of 2. parameter in the command line which contains program name.
    int size = 0;                           // In here i declared an int variable for declaring a char array with size.
    
    while (argv[1][i])
    { // In here i called while loop for counting the length of 2. command line parameter which contains program name.
        i++;
        size = i;
    }

    char args[size + 1]; // In here i declared a char array with size i found in while loop and i added 1 to size because of i'll add "./"  bash string before program name.

    for (int i = 0; i <= size + 2; i++)
    { // In here i started a for loop for getting program name with "./" string.
        if (i == 0)
            args[i] = '.'; // In here i assigned the '.' character to char array.
        else if (i == 1)
            args[i] = '/'; // In here i assigned tge '/' character to char array.
        else
            args[i] = argv[1][i - 2]; // In here i assigned the program name after assigning "./" string.
    }

    // In here i write to the command line which program is running and what is going to happen.
    printf("[main] %s will work for %d seconds...", argv[1], second);
    fflush(stdout);                // In here i cleaned the input buffer.
    
    execute_program(second, args); // In here i called the execute_program function which i wrote.
    
    printf("\n[main] %d seconds ended, closing %s...\n", second, argv[1]);
    return 0; // In here i terminated the main program.
}
