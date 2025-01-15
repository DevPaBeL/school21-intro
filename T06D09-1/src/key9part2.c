#include <stdio.h>

#define LEN 100

void sum(int *buff1, int *buff2, int len2);
void sub(int *buff1, int *buff2, int len2);
int input(int *buff, int *len);
void output(int *a, int n);
void copy(int *src, int *dst, int len);
int checkNumbers(int *data1, int *data2, int len1, int len2);

int main() {
    int data1[LEN];
    int data2[LEN];

    int len1;
    int len2;

    if (input(data1, &len1) && input(data2, &len2)) {
        int mirrorData1[LEN + 1];
        int mirrorData2[LEN];
        copy(data1, mirrorData1, len1);
        copy(data1, mirrorData2, len1);
        sum(mirrorData1, data2, len2);
        output(mirrorData1, len1 + 1);
        printf("\n");
        if (checkNumbers(data1, data2, len1, len2)) {
            sub(mirrorData2, data2, len2);
            output(mirrorData2, len1);
        } else {
            printf("n/a");
        }
    } else {
        printf("n/a");
    }
}

int input(int *buff, int *len) {
    char ch = 1;
    int i = 0;
    int flag = 1;
    while (ch != '\n' && ch != '\0' && flag == 1) {
        float num;
        if (scanf("%f", &num) == 1 && num == (int)num && num >= 0 && num < 10 && i < LEN) {
            buff[i] = num;
            i++;
        } else {
            flag = 0;
        }
        ch = getchar();
        if (ch != ' ' && ch != '\0' && ch != '\n') {
            flag = 0;
        }
    }
    *len = i;
    return flag;
}

int checkNumbers(int *data1, int *data2, int len1, int len2) {
    int flag = 1;
    int i = 0;
    int j = 0;
    while (data1[i] == 0) i++;
    while (data2[j] == 0) j++;
    if (len1 - i < len2 - j) {
        flag = 0;
    } else if (len1 - i == len2 - j) {
        if (data1[i] < data2[j]) {
            flag = 0;
        } else if (data1[i] == data2[j]) {
            for (; i < len1; i++) {
                if (data1[i] < data2[j]) {
                    flag = 0;
                    break;
                }
                j++;
            }
        }
    }
    return flag;
}

void sum(int *buff1, int *buff2, int len2) {
    int j = 0;
    for (int i = len2 - 1; i >= 0; i--) {
        if (buff1[j] + buff2[i] > 9) {
            buff1[j + 1] += (buff1[j] + buff2[i]) / 10;
            buff1[j] = (buff1[j] + buff2[i]) % 10;
        } else {
            buff1[j] += buff2[i];
        }
        j++;
    }
}

void sub(int *buff1, int *buff2, int len2) {
    int j = 0;
    for (int i = len2 - 1; i >= 0; i--) {
        if (buff1[j] - buff2[i] < 0) {
            if (buff1[j + 1] > 0)
                buff1[j + 1]--;
            else {
                int z = j + 1;
                for (; buff1[z] < 1; z++) {
                    buff1[z] += 9;
                }
                buff1[z]--;
            }
            buff1[j] = buff1[j] + 10 - buff2[i];
        } else {
            buff1[j] -= buff2[i];
        }
        j++;
    }
}

void output(int *a, int n) {
    int i = n - 1;
    while (a[i] == 0 && n != 1) {
        i--;
    }
    if (i == -1) {
        printf("%d", 0);
    } else {
        for (; i >= 0; i--) {
            if (i != 0)
                printf("%d ", a[i]);
            else
                printf("%d", a[i]);
        }
    }
}

void copy(int *src, int *dst, int len) {
    int j = 0;
    for (int i = len - 1; i >= 0; i--) {
        dst[j] = src[i];
        j++;
    }
    dst[j] = 0;
}