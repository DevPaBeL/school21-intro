#include "s21_string.h"

#include <string.h>

void s21_strlen_test();
void s21_strcmp_test();
void s21_strcpy_test();
void s21_strcat_test();
void s21_strchr_test();
void s21_strstr_test();

int main() {
#ifdef STRLEN
    s21_strlen_test();
#endif

#ifdef STRCMP
    s21_strcmp_test();
#endif

#ifdef STRCPY
    s21_strcpy_test();
#endif

#ifdef STRCAT
    s21_strcat_test();
#endif

#ifdef STRCHR
    s21_strchr_test();
#endif

#ifdef STRSTR
    s21_strstr_test();
#endif
    return 0;
}

void s21_strlen_test() {
    char *test_cases[] = {
        "SAMPLE", "sample", "Spaced sample", "", "S4mPl3Str1nG",
    };
    const int results[] = {6, 6, 13, 0, 12};
    int count = sizeof(results) / sizeof(int);
    for (int i = 0; i < count; i++) {
        printf("%s\n", test_cases[i]);
        int res = s21_strlen(test_cases[i]);
        printf("%d\n", res);
        if (res == results[i]) {
            printf("SUCCESS");
        } else {
            printf("FAIL");
        }
        if (i != count - 1) {
            printf("\n\n");
        }
    }
}

void s21_strcmp_test() {
    char *test_cases[][2] = {
        {"SAMPLE", "SAMPLE"},
        {"samplee", "sample"},
        {"Spaced sample", "Spaced sample"},
        {"sampel", "sample"},
        {"S a m p l e", "S a m p l 3"},
        {"1234", "4321"},
        {"4321", "1234"},
        {"1234", "1233"},
        {"", ""},
        {"", "Sample"},
    };
    const int results[] = {0, 101, 0, -7, 50, -3, 3, 1, 0, -83};
    int count = sizeof(results) / sizeof(int);
    for (int i = 0; i < count; i++) {
        // printf("%d - strcmp\n", strcmp(test_cases[i][0], test_cases[i][1]));
        printf("%s | %s\n", test_cases[i][0], test_cases[i][1]);
        int res = s21_strcmp(test_cases[i][0], test_cases[i][1]);
        printf("%d\n", res);
        if (res == results[i]) {
            printf("SUCCESS");
        } else {
            printf("FAIL");
        }
        if (i != count - 1) {
            printf("\n\n");
        }
    }
}

void s21_strcpy_test() {
    char *test_cases[] = {
        "SAMPLE", "sample", "Spaced sample", "S a m p l e", "S4mpl3 Str1nG~",
    };
    char *results[] = {
        "SAMPLE", "sample", "Spaced sample", "S a m p l e", "S4mpl3 Str1nG~",
    };
    int count = sizeof(results) / sizeof(char *);
    for (int i = 0; i < count; i++) {
        char test_string[100] = "empty";
        // printf("%s - strcpy\n", strcpy(test_string, test_cases[i]));
        printf("%s\n", test_cases[i]);
        s21_strcpy(test_string, test_cases[i]);
        printf("%s\n", test_string);
        if (s21_strcmp(test_string, results[i]) == 0) {
            printf("SUCCESS");
        } else {
            printf("FAIL");
        }
        if (i != count - 1) {
            printf("\n\n");
        }
    }
}

void s21_strcat_test() {
    char *test_cases[][2] = {
        {"SAMPL", "E"},
        {"sampl", "e"},
        {"Spaced ", "sample"},
        {"W i d e ", "S a m p l e"},
        {"FirstIsVeryLong ", "SecondIsShort"},
        {"FirstIsShort", " SecondIsVeryLong"},
    };
    char *results[] = {
        "SAMPLE",
        "sample",
        "Spaced sample",
        "W i d e S a m p l e",
        "FirstIsVeryLong SecondIsShort",
        "FirstIsShort SecondIsVeryLong",
    };
    int count = sizeof(results) / sizeof(char *);
    for (int i = 0; i < count; i++) {
        char test_string[100] = "empty";
        s21_strcpy(test_string, test_cases[i][0]);
        printf("%s | %s\n", test_cases[i][0], test_cases[i][1]);
        s21_strcat(test_string, test_cases[i][1]);
        printf("%s\n", test_string);
        if (s21_strcmp(test_string, results[i]) == 0) {
            printf("SUCCESS");
        } else {
            printf("FAIL");
        }
        if (i != count - 1) {
            printf("\n\n");
        }
    }
}

void s21_strchr_test() {
    char *test_strings[] = {
        "Hello, World!", "abcdefg", "Lorem ipsum sit dolor amet",
        "aabbccdd",      "qwerty",  "segfaults are my life",
        "xyz",           "",
    };
    char test_symbols[] = {
        'l', 'a', 'i', 'b', 'r', 's', 'a', 'x',
    };
    char *results[] = {
        "llo, World!", "abcdefg", "ipsum sit dolor amet", "bbccdd", "rty", "segfaults are my life",
        "(null)",      "(null)",
    };
    int count = sizeof(results) / sizeof(char *);
    for (int i = 0; i < count; i++) {
        printf("%s | %c\n", test_strings[i], test_symbols[i]);
        char *res = s21_strchr(test_strings[i], test_symbols[i]);
        printf("%s\n", res);
        if ((!res && s21_strcmp(results[i], "(null)") == 0) || s21_strcmp(res, results[i]) == 0) {
            printf("SUCCESS");
        } else {
            printf("FAIL");
        }
        if (i != count - 1) {
            printf("\n\n");
        }
    }
}

void s21_strstr_test() {
    char *test_cases[][2] = {
        {"SAMPLE", "AM"},
        {"sample", "mpl"},
        {"Spaced sample", " s"},
        {"W i d e S a m p l e", "i d e"},
        {"LongNum3ricS4mple", "3r"},
        {"www.google.com", ".g"},
        {"sorry for (null) :/", "ok."},
    };
    char *results[] = {
        "AMPLE", "mple", " sample", "i d e S a m p l e", "3ricS4mple", ".google.com", "(null)",
    };
    int count = sizeof(results) / sizeof(char *);
    for (int i = 0; i < count; i++) {
        printf("%s | %s\n", test_cases[i][0], test_cases[i][1]);
        char *res = s21_strstr(test_cases[i][0], test_cases[i][1]);
        printf("%s\n", res);
        if ((!res && s21_strcmp(results[i], "(null)") == 0) || s21_strcmp(res, results[i]) == 0) {
            printf("SUCCESS");
        } else {
            printf("FAIL");
        }
        if (i != count - 1) {
            printf("\n\n");
        }
    }
}