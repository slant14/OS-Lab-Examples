#include <stdio.h>

int tribonacci(int n) {
    if (n == 0) return 0;  
    if (n == 1 || n == 2) return 1;  

    int tn_3 = 0; 
    int tn_2 = 1;  
    int tn_1 = 1;  
    int tn = 0;

    for (int i = 3; i <= n; i++) {
        tn = tn_1 + tn_2 + tn_3;
        
        tn_3 = tn_2;
        tn_2 = tn_1;
        tn_1 = tn;
    }

    return tn;
}

int main() {
    int n;
    // for n > 37 you need to use long long int
    printf("Enter a value for n (0 <= n <= 37): ");
    scanf("%d", &n);

    if (n < 0 || n > 37) {
        printf("Invalid input. Please enter a value between 0 and 37.\n");
        return 1;
    }

    printf("T(%d) = %d\n", n, tribonacci(n));
    return 0;
}

