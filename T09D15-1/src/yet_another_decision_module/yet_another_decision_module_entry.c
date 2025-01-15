#include "decision.h"

int main() {
    double *data;
    int size;

    if (getSize(&size)) {
        data = malloc(sizeof(double) * size);
        if (input(data, size)) {
            if (make_decision(data, size))
                printf("YES");
            else
                printf("NO");
        } else {
            printf("n/a");
        }
        free(data);
    } else {
        printf("n/a");
    }

    return 0;
}
