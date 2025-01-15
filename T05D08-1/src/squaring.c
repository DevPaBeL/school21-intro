#include <stdio.h>
#define NMAX 10

int input(int *a, int *n);
void squaring(int *a, int n);
void output(int *a, int n);

int main() {
    int n, data[NMAX];
    if (input(data, &n)) {
        squaring(data, n);
        output(data, n);
    } else {
        printf("n/a");
    }

    return 0;
}

int input(int *a, int *n) {
    int flag = 1;
    float num = 0;

    if (scanf("%f", &num) == 1 && num <= NMAX && num > 0 && num == (int)num) {
        *n = num;
        for (int i = 0; i < *n; i++) {
            num = 0;
            if (scanf("%f", &num) == 1 && num == (int)num) {
                a[i] = num;
            } else {
                flag = 0;
            }
        }
    } else {
        flag = 0;
    }
    return flag;
}

void squaring(int *a, int n) {
    for (int i = 0; i < n; i++) {
        a[i] *= a[i];
    }
}

void output(int *a, int n) {
    for (int i = 0; i < n; i++) {
        if (i != n - 1)
            printf("%d ", a[i]);
        else
            printf("%d", a[i]);
    }
}
