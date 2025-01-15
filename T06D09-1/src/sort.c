#include <stdio.h>
#define NMAX 10

int input(int *a);
void output(int *data);
void quickSort(int *data, int size);

int main() {
    int data[NMAX];

    if (input(data)) {
        quickSort(data, NMAX);
        output(data);
    } else {
        printf("n/a");
    }

    return 0;
}

int input(int *a) {
    int flag = 1;
    float num;

    for (int i = 0; i < NMAX; i++) {
        num = 0;

        if (scanf("%f", &num) != 1 || num != (int)num) {
            flag = 0;
        } else {
            a[i] = num;
        }
    }
    return flag;
}

void output(int *data) {
    for (int i = 0; i < NMAX; i++) {
        if (i != NMAX - 1)
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