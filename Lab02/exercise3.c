#include <stdio.h>
#include <string.h>

#define LEN 256

int main() {
  char str[LEN], current;
  int i = 0;

  while ((current = getc(stdin)) && current != '.' && current != '\n') {
    str[i] = current;
    i++;
  }

  putc('\"', stdout);
  for (; i >= 0; i--) {
    putc(str[i], stdout);
  }
  putc('\"', stdout);
  putc('\n', stdout);

  return 0;
}
