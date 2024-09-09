# Execution flow of C program

## 1. Preprocessing

The first stage of compiling a C program is preprocessing. This stage is responsible for handling preprocessor directives, which are instructions to the preprocessor. Common directives include `#include`, `#define`, and `#ifdef`.

The preprocessor expands macros, includes header files, and performs conditional compilation. It produces an intermediate code file with the extension `.i`.

```bash
gcc -E main.c -o main.i
```


## 2. Compilation


After preprocessing, the next stage is compilation. In this stage, the preprocessed code is translated into assembly language code, which is specific to the target architecture. This assembly code is stored in a file with the extension `.asm` or `.s`.

``` bash
gcc -S main.i -o main.asm
```

## 3. Assembly


The assembly stage converts the architecture-specific assembly code into machine code or object code. The output is an object file with the extension `.obj` or `.o`.

``` bash
gcc -c main.asm -o main.obj
```
OR

``` bash
as main.asm -o main.obj
```

## 4. Linking


The final stage is linking. At this stage, the linker combines multiple object files (if your program consists of multiple source files) and resolves external references to libraries, creating the final executable program.

``` bash
gcc main.obj -o main.out
```

Finally you can execute with the following command:

> ./main.out



