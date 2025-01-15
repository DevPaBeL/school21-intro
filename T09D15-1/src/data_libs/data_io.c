#include "data_io.h"

int input(double *data, int n) {
    int flag = 1;
    for (int i = 0; i < n; i++) {
        if (scanf("%lf", &data[i]) != 1) {
            flag = 0;
            break;
        }
    }
    return flag;
}

void output(double *data, int n) {
    for (int i = 0; i < n; i++) {
        printf("%.2lf", data[i]);
        if (i != n - 1) printf(" ");
    }
}

int getSize(int *size) {
    int flag = 1;
    if (scanf("%d", size) != 1 || *size < 0) flag = 0;
    return flag;
}