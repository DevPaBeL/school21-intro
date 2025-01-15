#include <stdio.h>
#define NMAX 10

int input(int *a, int *n);
void output(int *a, int n);
int max(const int *a, int n);
int min(const int *a, int n);
double mean(const int *a, int n);
double variance(int *a, int n);

void output_result(int max_v, int min_v, double mean_v, double variance_v);

int main() {
    int n, data[NMAX];
    if (input(data, &n)) {
        output(data, n);
        output_result(max(data, n), min(data, n), mean(data, n), variance(data, n));
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

void output(int *a, int n) {
    for (int i = 0; i < n; i++) {
        if (i != n - 1)
            printf("%d ", a[i]);
        else
            printf("%d\n", a[i]);
    }
}

int max(const int *a, int n) {
    int max = a[0];
    for (int i = 1; i < n; i++) {
        if (a[i] > max) {
            max = a[i];
        }
    }
    return max;
}

int min(const int *a, int n) {
    int min = a[0];
    for (int i = 1; i < n; i++) {
        if (a[i] < min) {
            min = a[i];
        }
    }
    return min;
}

double mean(const int *a, int n) {
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

void output_result(int max_v, int min_v, double mean_v, double variance_v) {
    printf("%d %d %.6lf %.6lf", max_v, min_v, mean_v, variance_v);
}
