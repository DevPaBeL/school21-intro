#include "cipher.h"

#include "file_io.h"

int getChoice();
void menu();

int main() {
    menu();
    return 0;
}

void menu() {
    int flag = 1;
    char* path = NULL;
    while (flag) {
        int error = 0;
        int choice = getChoice();
        if (choice == 1) {
            if (path != NULL) {
                free(path);
            }
            path = getPath();
            if (readFile(path)) {
                free(path);
                path = NULL;
                printf("n/a\n");
            }
        } else if (choice == 2) {
            error = writeToFile(path);
            if (error) {
                printf("n/a\n");
            } else {
                readFile(path);
            }
        } else if (choice == -1) {
            flag = 0;
        }
    }
    if (path != NULL) free(path);
}

int getChoice() {
    int num = 0;
    if (scanf("%d", &num) != 1) num = -2;
    getchar();
    return num;
}

char* getStr() {
    char* string = malloc(sizeof(char));
    int c = getchar();
    int i = 0;
    while (c != EOF && c != '\n') {
        char* new = realloc(string, sizeof(char) * (i + 2));
        if (new == NULL) {
            free(string);
        } else {
            string[i] = c;
            c = getchar();
            i++;
        }
    }
    string[i] = '\0';
    return string;
}

char* getPath() {
    char* str = getStr();
    return str;
}
