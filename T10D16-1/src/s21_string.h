#ifndef S21_STRING_H_
#define S21_STRING_H_

#include <stdio.h>
#include <stdlib.h>

size_t s21_strlen(char *str);
int s21_strcmp(const char *s1, const char *s2);
char *s21_strcpy(char *dest, char *src);
char *s21_strcat(char *dest, char *addition);
char *s21_strchr(char *str, int symbol);
char *s21_strstr(char *str1, char *str2);

#endif  // S21_STRING_H_