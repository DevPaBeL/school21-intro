#include <stdio.h>
#define NMAX 10

int input(int *buffer, int *length, int *shift);
void output(int *a, int n);
void doShift(int *src, int *dst, int length, int shift);

int main() {
    int buffer[NMAX];
    int answer[NMAX];
    int length;
    int shift;
    if (input(buffer, &length, &shift)) {
        doShift(buffer, answer, length, shift);
        output(answer, length);
    } else {
        printf("n/a");
    }
}

int input(int *buffer, int *length, int *shift) {
    int flag = 1;
    float num = 0;

    if (scanf("%f", &num) == 1 && num <= NMAX && num > 0 && num == (int)num) {
        *length = num;
        for (int i = 0; i < *length; i++) {
            num = 0;
            if (scanf("%f", &num) == 1 && num == (int)num) {
                buffer[i] = num;
            } else {
                flag = 0;
            }
        }
        if (flag && scanf("%f", &num) == 1 && num == (int)num) {
            if (num > *length) {
                num = (int)num % *length;
            }
            *shift = num;
        } else {
            flag = 0;
        }
    } else {
        flag = 0;
    }
    return flag;
}

void doShift(int *src, int *dst, int length, int shift) {
    int j = 0;
    if (shift >= 0) {
        j = shift;
    } else {
        j = length + shift;
    }
    for (int i = 0; i < length; i++) {
        if (j >= length) j = 0;
        dst[i] = src[j];
        j++;
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
