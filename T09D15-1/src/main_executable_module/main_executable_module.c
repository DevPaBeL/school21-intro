#include <stdlib.h>

#include "../data_libs/data_io.h"
#include "../data_libs/data_stat.h"
#include "../data_module/data_process.h"
#include "../yet_another_decision_module/decision.h"

#ifdef MACRO
#include "../data_libs/data_io_macro.h"
INPUT(double, "%lf");
OUTPUT(double, "%.2lf");
GETSIZE();
#else
#include "../data_libs/data_io.h"
#endif  // MACRO

int main() {
    double *data;
    int size;

    if (getSize(&size)) {
        data = (double *)malloc(sizeof(double) * size);
        printf("LOAD DATA...\n");
        if (input(data, size)) {
            printf("RAW DATA:\n\t");
            output(data, size);
            printf("\nNORMALIZED DATA:\n\t");
            normalization(data, size);
            output(data, size);
            printf("\nSORTED NORMALIZED DATA:\n\t");
            sort(data, size);
            output(data, size);
            printf("\nFINAL DECISION:\n\t");
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