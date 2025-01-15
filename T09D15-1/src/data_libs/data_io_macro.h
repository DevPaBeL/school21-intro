#ifndef SRC_DATA_LIBS_DATA_IO_MACRO_H_
#define SRC_DATA_LIBS_DATA_IO_MACRO_H_

#include <stdio.h>

#define INPUT(TYPE, FORMAT)                     \
    int input(TYPE *data, int n) {              \
        int flag = 1;                           \
        for (int i = 0; i < n; i++) {           \
            if (scanf(FORMAT, &data[i]) != 1) { \
                flag = 0;                       \
                break;                          \
            }                                   \
        }                                       \
        return flag;                            \
    }
#define OUTPUT(TYPE, FORMAT)             \
    void output(TYPE *data, int n) {     \
        for (int i = 0; i < n; i++) {    \
            if (i == 0) {                \
                printf(FORMAT, data[i]); \
            } else {                     \
                printf(" ");             \
                printf(FORMAT, data[i]); \
            }                            \
        }                                \
    }
#define GETSIZE()                             \
    int getSize(int *size) {                  \
        int flag = 1;                         \
        if (scanf("%d", size) != 1) flag = 0; \
        return flag;                          \
    }
#endif  // SRC_DATA_LIBS_DATA_IO_MACRO_H_
