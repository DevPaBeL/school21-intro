#include "data_stat.h"

double max(double *data, int n) {
    double max = -10000000;
    for (int i = 0; i < n; i++)
        if (data[i] > max) max = data[i];
    return max;
}

double min(double *data, int n) {
    double min = 10000000;
    for (int i = 0; i < n; i++)
        if (data[i] < min) min = data[i];
    return min;
}

double mean(double *data, int n) {
    double sum = 0;
    for (int i = 0; i < n; i++) {
        sum += data[i];
    }
    return sum / n;
}

double variance(double *data, int n) {
    double mean_v = mean(data, n);
    double variance_v = 0;
    for (int i = 0; i < n; i++) {
        variance_v += (mean_v - data[i]) * (mean_v - data[i]);
    }
    return variance_v / n;
}

void sort(double *data, int n) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n - 1; j++)
            if (data[j] > data[j + 1]) {
                double tmp = data[j];
                data[j] = data[j + 1];
                data[j + 1] = tmp;
            }
}
