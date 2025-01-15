#include <stdio.h>
#include <stdlib.h>
#define SMAX 100

int getSize(int *width, int *height);
void output(double det);
void dynamicAllocation1(double ***matrix, int height, int width);
int input(double **matrix, int height, int width);
double det(double **matrix, int size);
void getMatrix(double **matrix, double **sub, int i, int j, int size);
void free_matrix(double **matrix, int height);

int main() {
    int width, height;
    double **matrix = NULL;
    if (getSize(&height, &width)) {
        dynamicAllocation1(&matrix, height, width);
        if (matrix == NULL) {
            printf("n/a");
        } else if (input(matrix, height, width)) {
            double determ = det(matrix, height);
            output(determ);
        } else {
            printf("n/a");
        }
        free_matrix(matrix, height);
    } else {
        printf("n/a");
    }
    return 0;
}

int getSize(int *width, int *height) {
    float x, y;
    int flag = 1;
    if (scanf("%f%f", &x, &y) == 2 && x == (int)x && y == (int)y && x > 0 && y > 0) {
        *width = x;
        *height = y;
    } else {
        flag = 0;
    }
    return flag;
}

void output(double det) { printf("%.6lf", det); }

int input(double **matrix, int height, int width) {
    int flag = 1;
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (scanf("%lf", &matrix[i][j]) != 1) {
                flag = 0;
                break;
            }
        }
    }
    return flag;
}

void dynamicAllocation1(double ***matrix, int height, int width) {
    *matrix = (double **)malloc(sizeof(double *) * height);
    for (int i = 0; i < height; i++) {
        (*matrix)[i] = (double *)malloc(sizeof(double) * width);
    }
}

void getMatrix(double **matrix, double **sub, int i, int j, int size) {
    int di = 0, dj = 0;
    for (int n = 0; n < size - 1; n++) {
        if (n == i) di = 1;
        dj = 0;
        for (int m = 0; m < size - 1; m++) {
            if (m == j) dj = 1;
            sub[n][m] = matrix[n + di][m + dj];
        }
    }
}

double det(double **matrix, int size) {
    double determ = 0;

    if (size == 1) {
        determ = matrix[0][0];
    } else if (size == 2) {
        determ = matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
    } else {
        int k = 1;
        double **sub = NULL;
        dynamicAllocation1(&sub, size - 1, size - 1);
        for (int i = 0; i < size; i++) {
            getMatrix(matrix, sub, i, 0, size);
            determ += k * matrix[i][0] * det(sub, size - 1);
            k *= -1;
        }
        for (int i = 0; i < size - 1; i++) free(sub[i]);
        free(sub);
    }
    return determ;
}

void free_matrix(double **matrix, int height) {
    for (int i = 0; i < height; i++) {
        free(matrix[i]);
    }
    free(matrix);
}