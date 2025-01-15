#include <math.h>
#include <stdio.h>

int SimpleDivisor(int number);
int prime(int num);

int main() {
  int number;
  if (scanf("%d", &number) != 1 || number == 0) {
    printf("n/a");
    return 0;
  } else {
    int result = SimpleDivisor(number);
    printf("%d", result);
    return 0;
  }
}

int SimpleDivisor(int number) {
  number = fabs(number);
  int x = 0;
  for (int i = 1; i <= number; i++) {
    int count = 0;
    while (number - i * count > 0) {
      count++;
    }
    if (number - i * count == 0 && prime(i)) {
      x = i;
    }
  }
  return x;
}

int prime(int num) {
  if (num <= 1)
    return num;
  for (int i = 2; i * i <= num; i++) {
    int count = 0;
    while (num - i * count > 0) {
      count++;
    }
    if (num - i * count == 0)
      return 0;
  }
  return 1;
}
