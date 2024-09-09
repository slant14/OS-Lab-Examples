#include <stdio.h>

int main() {
    unsigned int hexNum;

    printf("Enter a hexadecimal number:");
    scanf("%x", &hexNum);

    printf("You entered: 0x%x\n", hexNum);
    printf("%d", hexNum);

    return 0;
}
