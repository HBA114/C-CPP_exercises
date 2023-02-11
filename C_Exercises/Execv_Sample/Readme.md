# Execv Sample

## Requirements

- Unix-Like operating system.
- gcc

## How To Run

- First you need to create executables from each ".c" file.

```
gcc main.c -o main
```
and
```
gcc program2.c -o program2 
```

- If you didn't get any error with compiling code and creating executables you can test program 2 with:

```
./program2
```

- program2 runs forever and writes seconds while it is running. You can end process with "CTRL + C" shortcut.

- Now you can test execv program with giving parameters as file and int like below:

```
./main program2 5
```

- This command runs main program. main program runs program2 program for 5 seconds.

- Output should be:
```
[hw1] 5sn boyunca program2 çalıştırılacak...
[T2] test2 programıyım ve sürekli çalışıyorum...
[T2] 1. saniye
[T2] 2. saniye
[T2] 3. saniye
[T2] 4. saniye
[T2] 5. saniye
[hw1] 5 sn sona erdi program2 kapatılıyor...
```