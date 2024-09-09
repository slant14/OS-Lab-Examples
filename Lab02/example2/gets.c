#include <stdio.h>

int main() {
    char name[10]; 

    printf("Enter your name: ");
    // it is deprecated, unsafe, buffer overflow
    gets(name); 

    printf("Hello, %s!\n", name);

    return 0;
}