#include <stdio.h>
#include <stdlib.h>
#define SMAX 100

int getSize(int *width, int *height);
void output(int **matrix, int height, int width);
void dynamicAllocation1(int ***matrix, int height, int width);
int input(int **matrix, int height, int width);
void bubbleSort(int *array, int length);
void sort_vertical(int **matrix, int height, int width, int **result);
void sort_horizontal(int **matrix, int height, int width, int **result);
void free_matrix(int **matrix, int height);

int main() {
    int width, height;
    int **matrix = NULL;
    int **result = NULL;
    if (getSize(&height, &width)) {
        dynamicAllocation1(&matrix, height, width);
        dynamicAllocation1(&result, height, width);
        if (matrix == NULL || result == NULL) {
            printf("n/a");
        } else if (input(matrix, height, width)) {
            sort_vertical(matrix, height, width, result);
            output(result, height, width);
            printf("\n\n");
            sort_horizontal(matrix, height, width, result);
            output(result, height, width);
        } else {
            printf("n/a");
        }
        free_matrix(result, height);
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

void output(int **matrix, int height, int width) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            printf("%d", matrix[i][j]);
            if (j != width - 1) printf(" ");
        }
        if (i != height - 1) printf("\n");
    }
}

int input(int **matrix, int height, int width) {
    int flag = 1;
    float num = 0;
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (scanf("%f", &num) == 1 && num == (int)num) {
                matrix[i][j] = num;
            } else {
                flag = 0;
                break;
            }
        }
    }
    return flag;
}

void dynamicAllocation1(int ***matrix, int height, int width) {
    *matrix = (int **)malloc(sizeof(int *) * height);
    for (int i = 0; i < height; i++) {
        (*matrix)[i] = (int *)malloc(sizeof(int) * width);
    }
}

void bubbleSort(int *array, int length) {
    for (int i = 0; i < length; i++) {
        for (int j = 0; j < length - 1; j++) {
            if (array[j] > array[j + 1]) {
                int tmp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = tmp;
            }
        }
    }
}

void sort_vertical(int **matrix, int height, int width, int **result) {
    int *array = (int *)malloc(sizeof(int) * height * width);
    int id = 0;
    for (int i = 0; i < height; i++)
        for (int j = 0; j < width; j++) {
            array[id] = matrix[i][j];
            id++;
        }
    bubbleSort(array, id);
    id = 0;
    for (int j = 0; j < width; j++) {
        if (j % 2 == 0) {
            for (int i = 0; i < height; i++) {
                result[i][j] = array[id];
                id++;
            }
        } else {
            for (int i = height - 1; i >= 0; i--) {
                result[i][j] = array[id];
                id++;
            }
        }
    }
    free(array);
}

void sort_horizontal(int **matrix, int height, int width, int **result) {
    int *array = (int *)malloc(sizeof(int) * height * width);
    int id = 0;
    for (int i = 0; i < height; i++)
        for (int j = 0; j < width; j++) {
            array[id] = matrix[i][j];
            id++;
        }
    bubbleSort(array, id);
    id = 0;
    for (int i = 0; i < height; i++) {
        if (i % 2 == 0) {
            for (int j = 0; j < width; j++) {
                result[i][j] = array[id];
                id++;
            }
        } else {
            for (int j = width - 1; j >= 0; j--) {
                result[i][j] = array[id];
                id++;
            }
        }
    }
    free(array);
}

void free_matrix(int **matrix, int height) {
    for (int i = 0; i < height; i++) {
        free(matrix[i]);
    }
    free(matrix);
}