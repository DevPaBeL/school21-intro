#include "file_io.h"

int fileOutput(FILE* ptr) {
    int flag = 0;

    if (ptr != NULL) {
        int ch = fgetc(ptr);
        flag = 1;
        while (ch != EOF) {
            flag = 0;
            printf("%c", ch);
            ch = fgetc(ptr);
        }
        if (!flag) printf("\n");
    } else {
        flag = 1;
    }
    return flag;
}

int fileInput(FILE* ptr) {
    int flag = 0;
    if (ptr == NULL) {
        flag = 1;
    } else if (!ftell(ptr)) {
        flag = 1;
    } else {
        rewind(ptr);
        char c;
        c = getchar();
        fputc('\n', ptr);
        while (c != '\n' && c != EOF) {
            fputc(c, ptr);
            c = getchar();
        }
    }
    return flag;
}

int readFile(char* path) {
    int flag = 0;
    FILE* ptr = fopen(path, "r");
    flag = fileOutput(ptr);
    fclose(ptr);
    return flag;
}

int writeToFile(char* path) {
    int flag = 0;
    if (path == NULL) {
        flag = 1;
    } else {
        FILE* ptr = fopen(path, "a");
        flag = fileInput(ptr);
        fclose(ptr);
    }
    return flag;
}
