#include <math.h>
#include <stdio.h>

int fibo(int n);

int main() {
  int n;
  if (scanf("%d", &n) != 1) {
    printf("n/a");
    return 0;
  } else {
    printf("%d", fibo(n));
    return 0;
  }
}
int fibo(int n) {
  return (pow(((1 + sqrt(5)) / 2), n) - pow(((1 - sqrt(5)) / 2), n)) / sqrt(5);
}
