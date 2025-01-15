#include "s21_string.h"

size_t s21_strlen(char *str) {
    size_t i = 0;
    while (str[i] != '\0') i++;
    return i;
}

int s21_strcmp(const char *s1, const char *s2) {
    size_t i = 0;

    while (s1[i] && s2[i] && s1[i] == s2[i]) i++;
    return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

char *s21_strcpy(char *dest, char *src) {
    char *address = dest;
    while (*src != '\0') {
        *dest++ = *src++;
    }
    dest = address;
    return dest;
}

char *s21_strcat(char *dest, char *addition) {
    int str1_length = s21_strlen(dest);
    int str2_length = s21_strlen(addition);
    for (int i = 0; i <= str2_length; i++) {
        dest[str1_length + i] = addition[i];
    }
    return dest;
}

char *s21_strchr(char *str, int symbol) {
    char *ptr = 0;
    while (*str != '\0') {
        if (*str == symbol) {
            ptr = str;
            break;
        }
        str++;
    }
    return ptr;
}

char *s21_strstr(char *str1, char *str2) {
    char *ptr = 0;
    while (*str1 != '\0') {
        char *tmp = str1;
        char *tmp2 = str2;
        while (*tmp == *tmp2) {
            tmp++;
            tmp2++;
            if (*tmp2 == '\0') {
                ptr = str1;
                break;
            }
        }
        str1++;
    }
    return ptr;
}