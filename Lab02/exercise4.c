#include <stdio.h>
#include <ctype.h>

#define LEN 256

int count(const char *str, char ch) {
    int occurrences = 0;
    while (*str) {
        if (tolower(*str) == tolower(ch)) {
            occurrences++;
        }
        str++;
    }
    return occurrences;
}

void countAll(const char *str) {
    int counted[256] = {0};  
    while (*str) {
        char lower_char = tolower(*str);
        if (!counted[(unsigned char)lower_char]) {
            int occurrences = count(str, *str);
            printf("%c:%d\n", lower_char, occurrences);
            counted[(unsigned char)lower_char] = 1;
        }
        str++;
    }
}

int main() {
    char input[LEN];

    printf("Enter a string: ");
    scanf("%s", input);

    printf("Count all (case-insensitive):\n");
    countAll(input);

    return 0;
}

