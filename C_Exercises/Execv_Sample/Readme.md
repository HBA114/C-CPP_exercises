# Execv Sample

## Requirements

- `Unix-Like` operating system.
- `gcc` or `clang`

## How To Run

- First you need to create executables from each ".c" file.

    - For gcc
        ```
        gcc main.c -o main.o
        ```
        and
        ```
        gcc program2.c -o program2.o
        ```
    - For clang
        ```
        clang main.c -o main.o
        ```
        and
        ```
        clang program2.c -o program2.o
        ```

- If you didn't get any error with compiling code and creating executables you can test program 2 with:

```
./program2.o
```

- program2 runs forever and writes seconds while it is running. You can end process with "CTRL + C" shortcut.

- Now you can test main program with giving parameters as file and int like below:

```
./main.o program2.o 5
```

- This command runs main program. main program runs program2 program for 5 seconds.

- Output should be:
```
[main] program2.o will work for 5 seconds...
[Program2] i'm Program2 and i'm working continually...
[Program2] 1. seconds
[Program2] 2. seconds
[Program2] 3. seconds
[Program2] 4. seconds
[Program2] 5. seconds
[main] 5 seconds ended, closing program2.o...
```
