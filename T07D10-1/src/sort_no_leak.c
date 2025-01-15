#include <stdio.h>
#include <stdlib.h>

int input(int *a, int len);
void output(int *data, int len);
void quickSort(int *data, int size);

int main() {
    float len = 0;
    if (scanf("%f", &len) == 1 && len == (int)len && len > 0) {
        int *data;
        data = (int *)malloc(len * sizeof(int));
        if (input(data, len)) {
            quickSort(data, len);
            output(data, len);
        } else {
            printf("n/a");
        }
        free(data);
    } else {
        printf("n/a");
    }

    return 0;
}

int input(int *a, int len) {
    int flag = 1;
    float num;
    for (int i = 0; i < len; i++) {
        num = 0;

        if (scanf("%f", &num) != 1 || num != (int)num) {
            flag = 0;
        } else {
            a[i] = num;
        }
    }
    return flag;
}

void output(int *data, int len) {
    for (int i = 0; i < len; i++) {
        if (i != len - 1)
            printf("%d ", data[i]);
        else
            printf("%d", data[i]);
    }
}

void quickSort(int *data, int size) {
    int left = 0;
    int right = size - 1;

    int mid = data[size / 2];

    while (left <= right) {
        while (data[left] < mid) left++;
        while (data[right] > mid) right--;

        if (left <= right) {
            int tmp = data[left];
            data[left] = data[right];
            data[right] = tmp;

            left++;
            right--;
        }
    }

    if (right > 0) quickSort(data, right + 1);
    if (left < size) quickSort(&data[left], size - left);
}