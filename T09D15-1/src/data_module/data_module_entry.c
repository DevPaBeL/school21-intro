#include "data_process.h"

int main() {
    double *data;
    int size;

    if (getSize(&size)) {
        data = malloc(sizeof(double) * size);
        if (input(data, size)) {
            if (normalization(data, size))
                output(data, size);
            else
                printf("ERROR");
        } else {
            printf("n/a");
        }
        free(data);
    } else {
        printf("n/a");
    }
    return 0;
}
