#include <math.h>
#include <stdio.h>

void Verz(double x);
void Bern(double x);
void Kvad(double x);

int main() {
  double pi = -3.14159265358979323846;
  double x = 2 * (-pi) / 41;
  for (int i = 1; i < 41; i++) {
    printf("%.7lf | ", pi);
    ;
    Verz(pi);
    Bern(pi);
    Kvad(pi);
    if (i != 41)
      printf("\n");
    pi += x;
  }
  return 0;
}

void Verz(double x) {
  double answer = 1 / (1 + pow(x, 2));
  printf("%.7lf | ", answer);
}

void Bern(double x) {
  double Sqrt;
  double SecondSqrt;
  Sqrt = sqrt(1 + 4 * pow(x, 2) * 1);
  double answer = Sqrt - pow(x, 2) - 1;
  if (answer < 0) {
    printf("- |");
  } else {
    printf("%.7lf | ", sqrt(answer));
  }
}

void Kvad(double x) {
  double answer = 0;
  answer = 1 / pow(x, 2);
  printf("%.7lf | ", answer);
}
