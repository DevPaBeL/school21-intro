#include <stdio.h>
#include <stdlib.h>
#define SMAX 100

int getChoice(int *choice);
int getSize(int *width, int *height);
void output(int **matrix, int height, int width, int flag, int *maxValue, int *minValues);
void transform(int *buf, int **matr, int n, int m);
void staticAllocation(int ***matrix);
void dynamicAllocation1(int ***matrix, int height, int width);
void dynamicAllocation2(int ***matrix, int height, int width);
void dynamicAllocation3(int ***matrix, int height, int width);
int input(int **matrix, int height, int width, int *maxValues);
void findMin(int **matrix, int w, int l, int *minValues);

int main() {
    int choice = 0;
    int width, height;
    int **matrix = NULL;
    int flag = 0;
    int *maxValues;
    int *minValues;

    if (getChoice(&choice) && getSize(&width, &height)) {
        maxValues = (int *)malloc(width * sizeof(int));
        minValues = (int *)malloc(height * sizeof(int));
        switch (choice) {
            case 1:
                staticAllocation(&matrix);
                break;
            case 2:
                dynamicAllocation1(&matrix, height, width);
                flag = 1;
                break;
            case 3:
                dynamicAllocation2(&matrix, height, width);
                flag = 2;
                break;
            default:
                dynamicAllocation3(&matrix, height, width);
                flag = 2;
                break;
        }
        if (input(matrix, height, width, maxValues)) {
            findMin(matrix, width, height, minValues);
            output(matrix, height, width, flag, maxValues, minValues);
        } else {
            printf("n/a");
        }
    } else {
        printf("n/a");
    }
    if (choice > 1) free(matrix);
    return 0;
}

int getChoice(int *choice) {
    float n;
    int flag = 1;
    if (scanf("%f", &n) == 1 && n == (int)n && n >= 1 && n <= 4) {
        *choice = n;
    } else {
        flag = 0;
    }
    return flag;
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

void findMin(int **matrix, int w, int l, int *minValues) {
    for (int i = 0; i < w; i++) {
        int min = 2147483647;
        for (int j = 0; j < l; j++) {
            if (min > matrix[j][i]) {
                min = matrix[j][i];
            }
        }
        minValues[i] = min;
    }
}

void output(int **matrix, int height, int width, int flag, int *maxValues, int *minValues) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            printf("%d", matrix[i][j]);
            if (j != width - 1) printf(" ");
        }
        if (i != height - 1) printf("\n");
        if (flag == 1) free(matrix[i]);
    }
    if (flag == 2) free(*matrix);
    printf("\n");
    for (int i = 0; i < height; i++) {
        printf("%d", maxValues[i]);
        if (i != height - 1) printf(" ");
    }
    printf("\n");
    for (int i = 0; i < width; i++) {
        printf("%d", minValues[i]);
        if (i != width - 1) printf(" ");
    }
    free(maxValues);
    free(minValues);
}

int input(int **matrix, int height, int width, int *maxValues) {
    int flag = 1;
    int max = -2147483647;
    float num = 0;
    for (int i = 0; i < height; i++) {
        max = -2147483647;
        for (int j = 0; j < width; j++) {
            if (scanf("%f", &num) == 1 && num == (int)num) {
                if (num > max) max = num;
                matrix[i][j] = num;
            } else {
                flag = 0;
                break;
            }
        }
        maxValues[i] = max;
    }
    return flag;
}

void transform(int *buf, int **matr, int n, int m) {
    for (int i = 0; i < n; i++) {
        matr[i] = buf + i * m;
    }
}

void staticAllocation(int ***matrix) {
    int arr[SMAX][SMAX];
    int *parr[SMAX];
    *matrix = parr;
    transform(*arr, *matrix, SMAX, SMAX);
}

void dynamicAllocation1(int ***matrix, int height, int width) {
    *matrix = (int **)malloc(sizeof(int *) * height);
    for (int i = 0; i < height; i++) {
        (*matrix)[i] = (int *)malloc(sizeof(int) * width);
    }
}
void dynamicAllocation2(int ***matrix, int height, int width) {
    *matrix = (int **)malloc(sizeof(int *) * height);
    int *tmp = (int *)malloc(sizeof(int) * height * width);
    for (int i = 0; i < height; i++) (*matrix)[i] = tmp + width * i;
}
void dynamicAllocation3(int ***matrix, int height, int width) {
    *matrix = (int **)malloc(sizeof(int *) * height);
    (*matrix)[0] = (int *)malloc(sizeof(int) * height * width);
    for (int i = 0; i < height; i++) (*matrix)[i] = (*matrix)[0] + width * i;
}