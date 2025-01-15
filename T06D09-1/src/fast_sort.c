#include <stdio.h>
#define NMAX 10

int input(int *a);
void output(int *data);
void quickSort(int *data, int size);
void mergeSort(int *data, int l, int r);
void copy(const int *data, int *copyData);

int main() {
    int data[NMAX];

    if (input(data)) {
        int dataCopy[NMAX];
        quickSort(data, NMAX);
        copy(data, dataCopy);
        mergeSort(dataCopy, 0, NMAX - 1);
        output(data);
        output(dataCopy);
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
    printf("\n");
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

void copy(const int *data, int *copyData) {
    for (int i = 0; i < NMAX; i++) {
        copyData[i] = data[i];
    }
}

void mergeSort(int *data, int l, int r) {
    if (l == r) return;
    int mid = (l + r) / 2;

    mergeSort(data, l, mid);
    mergeSort(data, mid + 1, r);
    int i = l;
    int j = mid + 1;
    int tmp[10];
    for (int step = 0; step < r - l + 1; step++) {
        if ((j > r) || ((i <= mid) && (data[i] < data[j]))) {
            tmp[step] = data[i];
            i++;
        } else {
            tmp[step] = data[j];
            j++;
        }
    }
    for (int step = 0; step < r - l + 1; step++) data[l + step] = tmp[step];
}