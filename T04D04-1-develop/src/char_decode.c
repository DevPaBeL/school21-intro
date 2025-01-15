#include <stdio.h>

void code();
void decode();

int main() {
  int num;
  scanf("%d", &num);
  if (num == 0) {
    code();
  } else if (num == 1) {
    decode();
  } else {
    printf("n/a");
  }
  return 0;
}

void code() {
  int result = getchar();
  int symbol;
  while ((result = getchar()) != '\n') {
    symbol = getchar();
    if (symbol != ' ' && symbol != '\n') {
      printf("n/a");
      break;
    }
    printf("%x", result);
    if (symbol == '\n') {
      break;
    }
    printf(" ");
  }
}
void decode() {
  int result;
  while (scanf("%x", &result)) {
    int symbol = getchar();
    if ((symbol != ' ' && symbol != '\n') || (result > '~' || result < 32)) {
      printf("n/a");
      break;
    }
    printf("%c", result);
    if (symbol == '\n') {
      break;
    }
    printf(" ");
  }
}
