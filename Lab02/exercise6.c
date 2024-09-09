#include <stdio.h>

void printRectangle(int height, int width) {
  for (int i = 0; i < height; ++i) {
    for (int j = 0; j < width; ++j) {
      printf("*");
    }
    printf("\n");
  }
}

void printTriangle(int height) {
  for (int i = 0; i < height; ++i) {
    for (int j = 0; j <= i; ++j) {
      printf("*");
    }
    printf("\n");
  }
}

// Printing the half-diamond pattern using only 2 loops(nested)
void printDiamond1(int height) {
  for (int i = 1; i <= 2 * height - 1; i++) {
    int stars = (i <= height) ? i : 2 * height - i;

    for (int j = 1; j <= stars; j++) {
      printf("*");
    }
    printf("\n");
  }
}

// Printing the half-diamond pattern reusing the printTriangle function
void printDiamond2(int height) {
  printTriangle(height);
  for (int i = 0; i < height; ++i) {
    for (int j = 0; j < height - i - 1; ++j) {
      printf("*");
    }
    printf("\n");
  };
}

int main() {
  int height, width;
  scanf("%d%d", &height, &width);
  printRectangle(height, width);
  printf("\n----------\n");
  printTriangle(height);
  printf("\n----------\n");
  printDiamond2(height);
  printf("\n----------\n");
  printDiamond2(height);
}

