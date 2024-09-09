#include <stdlib.h>
#include <stdio.h>
#include <math.h>

long long convertToDecimal(long long x, int s) {
    long long result = 0;
    int i = 0;
    while (x > 0) {
        int digit = x % 10;
        if (digit >= s) {
            puts("cannot convert!");
            exit(0);
        }
        result = result + digit * (int) pow(s, i);
        x = x / 10;
        i++;
    }
    return result;
}

long long convertFromDecimal(long long x, int t) {
    long long result = 0;
    int i = 0;
    while (x > 0) {
        int digit = x % t;
        result = result + (int) pow(10, i) * digit;
        i++;
        x = x / t;
    }
    return result;
}

long long convert(long long x, int s, int t) {
    if (s < 2 || s > 10 || t < 2 || t > 10) {
        puts("cannot convert!");
        exit(0);
    }
    return convertFromDecimal(convertToDecimal(x, s), t);
}

int main() {
    long long n;
    int s, t;
    scanf("%ld %d %d", &n, &s, &t);
    printf("%d\n", convert(n, s, t));
}
