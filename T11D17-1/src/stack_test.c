#include "stack.h"

#include <stdio.h>
void test();
int main() { test(); }
void test() {
    // INITIALIZATION TEST
    struct elem* head = init(777);
#ifdef PRINTING
    printf("1. Инициализация стека\n");
    printf("\t> Ожидаемое значение рута:\t777\n");
    printf("\t> Реальное значение рута:\t%d\n", head->val);
    printf("\t> Результат:\t");
#endif
    if (head->val == 777)
        printf("\tSUCCESS\n");
    else
        printf("\tFAIL\n");
    // PUSH TEST
    push(&head, -123);
#ifdef PRINTING
    printf("2. Stack push\n");
    printf("\t> Ожидаемое значение:\t-123\n");
    printf("\t> Реальное значение:\t%d\n", head->val);
    printf("\t> Результат:\t");
#endif
    if (head->val == -123)
        printf("\tSUCCESS\n");
    else
        printf("\tFAIL\n");
    // POP TEST
    int res = pop(&head);
#ifdef PRINTING
    printf("3. Stack pop\n");
    printf("\t> Ожидаемое значение:\t777\n");
    printf("\t> Реальное значение:\t%d\n", head->val);
    printf("\t> Ожидаемое значение return:\t-123\n");
    printf("\t> Реальное значение return:\t%d\n", res);
    printf("\t> Результат:\t");
#endif
    if (head->val == 777 && res == -123)
        printf("\tSUCCESS\n");
    else
        printf("\tFAIL\n");
    destroy(&head);
}
