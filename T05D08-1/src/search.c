#include <math.h>
#include <stdio.h>
#define NMAX 10

int input(int *a, int *n);
double mean(int *a, int n);
double variance(int *a, int n);
int getAnswer(int *a, int n);

int main() {
    int n, data[NMAX];
    if (input(data, &n)) {
        printf("%d", getAnswer(data, n));
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

double mean(int *a, int n) {
    double sum = 0;
    for (int i = 0; i < n; i++) {
        sum += a[i];
    }
    return sum / n;
}

double variance(int *a, int n) {
    double mean_v = mean(a, n);
    double variance_v = 0;
    for (int i = 0; i < n; i++) {
        variance_v += (mean_v - a[i]) * (mean_v - a[i]);
    }
    return variance_v / n;
}

int getAnswer(int *a, int n) {
    int answer = 0;
    double mean_v = mean(a, n);
    double variance_v = variance(a, n);

    for (int i = 0; i < n; i++) {
        if (a[i] != 0 && a[i] % 2 == 0 && a[i] >= mean_v) {
            if (a[i] <= 3 + sqrt(variance_v)) {
                answer = a[i];
                break;
            }
        }
    }
    return answer;
}