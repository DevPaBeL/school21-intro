/*------------------------------------
        Здравствуй, человек!
        Чтобы получить ключ
        поработай с комментариями.
-------------------------------------*/

#include <stdio.h>
#define NMAX 10

int input(int *buffer, int *length);
void output(int sum, int *buffer, int length);
int sum_numbers(int *buffer, int length);
int find_numbers(int *buffer, int length, int number, int *numbers);

/*------------------------------------
        Функция получает массив данных
        через stdin.
        Выдает в stdout особую сумму
        и сформированный массив
        специальных элементов
        (выбранных с помощью найденной суммы):
        это и будет частью ключа
-------------------------------------*/
int main() {
    int n, data[NMAX], answer[11];
    if (input(data, &n)) {
        int sum = sum_numbers(data, n);
        if (sum != 0) {
            int lenArray = find_numbers(data, n, sum, answer);
            output(sum, answer, lenArray);
        } else {
            printf("n/a");
        }
    } else {
        printf("n/a");
    }
    return 0;
}

int input(int *buffer, int *length) {
    int flag = 1;
    float num = 0;

    if (scanf("%f", &num) == 1 && num <= NMAX && num > 0 && num == (int)num) {
        *length = num;
        for (int i = 0; i < *length; i++) {
            num = 0;
            if (scanf("%f", &num) == 1 && num == (int)num) {
                buffer[i] = num;
            } else {
                flag = 0;
            }
        }
    } else {
        flag = 0;
    }
    return flag;
}

/*------------------------------------
        Функция должна находить
        сумму четных элементов
        с 0-й позиции.
-------------------------------------*/
int sum_numbers(int *buffer, int length) {
    int sum = 0;

    for (int i = 0; i < length; i++) {
        if (buffer[i] != 0 && buffer[i] % 2 == 0) {
            sum += buffer[i];
        }
    }

    return sum;
}

/*------------------------------------
        Функция должна находить
        все элементы, на которые нацело
        делится переданное число и
        записывает их в выходной массив.
-------------------------------------*/
int find_numbers(int *buffer, int length, int number, int *numbers) {
    int j = 0;
    for (int i = 0; i < length; i++) {
        if (buffer[i] != 0 && number % buffer[i] == 0) {
            numbers[j] = buffer[i];
            j++;
        }
    }
    return j;
}

void output(int sum, int *buffer, int length) {
    printf("%d\n", sum);
    for (int i = 0; i < length; i++) {
        if (i < length - 1)
            printf("%d ", buffer[i]);
        else
            printf("%d", buffer[i]);
    }
}