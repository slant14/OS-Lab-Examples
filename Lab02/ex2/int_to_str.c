#include <stdio.h>

int main() {
    int num = 2022;
    char str[10]; 
    
    sprintf(str, "%d", num);
    
    printf("Integer: %d\n", num);
    printf("String: %s\n", str);

    return 0;
}
