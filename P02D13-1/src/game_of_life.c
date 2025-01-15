#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define Y 25
#define X 80
#define MAX_GENS 1000

int getFromFile(int **display);
void output(int **display);
void dynamicAllocation1(int ***matrix);
int swapGeneration(int **display, int **swap);
_Bool isAlive(int **display, int x, int y);
void startGame(int **display, int **swap);
int setDelay();
void freeMatrix(int **matrix);
int checkArgs(int argc, char **argv);
int getInitialState(int mode, int **display);
int getFromStream(int **display);
int randomInit(int **display);

int main(int argc, char **argv) {
    int mode = checkArgs(argc, argv);

    if (mode) {
        int **display;
        int **swap;

        dynamicAllocation1(&display);

        if (getInitialState(mode, display)) {
            dynamicAllocation1(&swap);
            startGame(display, swap);
            freeMatrix(swap);
        } else {
            printf("Can't initialize state\n");
        }
        freeMatrix(display);
    }

    return 0;
}

int checkArgs(int argc, char **argv) {
    int setMode = 0;

    if (argc == 2) {
        switch (argv[1][0]) {
            case '1':
                setMode = 1;
                break;
            case '2':
                setMode = 2;
                break;
            case '3':
                setMode = 3;
                break;
            default:
                setMode = 0;
                break;
        }

    } else {
        printf(
            "Invalid arguments!!!!!\nUse:\n1 - if you want set initial file\n2 - if you want set stream from "
            "file\n3 - if you want random your map\n");
    }

    return setMode;
}

int getInitialState(int mode, int **display) {
    int flag = 1;

    switch (mode) {
        case 1:
            flag = getFromFile(display);
            break;
        case 2:
            flag = getFromStream(display);
            break;
        default:
            flag = randomInit(display);
            break;
    }

    return flag;
}

int getFromFile(int **display) {
    int flag = 1;
    FILE *fp;
    char fileName[30];
    printf("Введите имя файла конфигурации\n");
    for (int i = 0; i < 30; i++) {
        char ch = getchar();
        if (ch == '\n') {
            fileName[i] = '\0';
            break;
        }
        fileName[i] = ch;
    }

    fp = fopen(fileName, "r");

    if (fp != NULL) {
        int ch;

        for (int i = 0; i < Y; i++) {
            for (int j = 0; j <= X; j++) {
                ch = fgetc(fp);
                if (ch == '*')
                    display[i][j] = 1;
                else if (ch == ' ')
                    display[i][j] = 0;
                else if (ch != '\n' && ch != '\0' && ch != EOF) {
                    flag = 0;
                    break;
                }
                if (i < Y - 1 && j < X && ch == EOF) flag = 0;
            }
        }
        fclose(fp);
    } else {
        flag = 0;
    }
    return flag;
}

int getFromStream(int **display) {
    int flag = 1;

    for (int i = 0; i < Y; i++) {
        for (int j = 0; j <= X; j++) {
            int ch = getchar();
            if (ch == '*')
                display[i][j] = 1;
            else if (ch == ' ')
                display[i][j] = 0;
            else if (ch != '\n' && ch != '\0' && ch != EOF) {
                flag = 0;
                break;
            }
            if (i < Y - 1 && j < X && ch == EOF) flag = 0;
        }
    }

    if (freopen("/dev/tty", "r", stdin) == NULL) flag = 0;

    return flag;
}

int randomInit(int **display) {
    int flag = 1;

    for (int i = 0; i < Y; i++) {
        for (int j = 0; j < X; j++) {
            int symbol = rand() % 10;
            if (symbol == 0) {
                display[i][j] = 1;
            } else {
                display[i][j] = 0;
            }
        }
    }

    return flag;
}

void output(int **display) {
    for (int i = 0; i < Y; i++) {
        for (int j = 0; j < X; j++) {
            if (display[i][j] == 1) printf("*");
            if (display[i][j] == 0) printf(" ");
        }
        printf("\n");
    }
}

void dynamicAllocation1(int ***matrix) {
    *matrix = (int **)malloc(sizeof(int *) * Y);
    for (int i = 0; i < Y; i++) {
        (*matrix)[i] = (int *)malloc(sizeof(int) * X);
    }
}

_Bool isAlive(int **display, int x, int y) {
    _Bool current = display[x][y];
    int counter = 0;
    _Bool alive = 0;
    int x1 = x;
    int y1 = y;

    if (x == 0) x1 = Y - 2;
    if (x == Y - 1) x1 = 1;
    if (y == 0) y1 = X - 2;
    if (y == X - 1) y1 = 1;

    if (display[x1 - 1][y] == 1) counter++;
    if (display[x1 + 1][y] == 1) counter++;
    if (display[x][y1 + 1] == 1) counter++;
    if (display[x][y1 - 1] == 1) counter++;
    if (display[x1 - 1][y1 + 1] == 1) counter++;
    if (display[x1 - 1][y1 - 1] == 1) counter++;
    if (display[x1 + 1][y1 + 1] == 1) counter++;
    if (display[x1 + 1][y1 - 1] == 1) counter++;

    if (!current && counter == 3)
        alive = 1;
    else if (current && (counter == 2 || counter == 3))
        alive = 1;
    else if (current && (counter < 2 || counter > 3))
        alive = 0;

    return alive;
}

int swapGeneration(int **display, int **swap) {
    int flag = 0;
    for (int i = 0; i < Y; i++) {
        for (int j = 0; j < X; j++) {
            swap[i][j] = isAlive(display, i, j);
            if (flag == 0 && swap[i][j]) flag = 1;
        }
    }
    for (int i = 0; i < Y; i++) {
        for (int j = 0; j < X; j++) {
            display[i][j] = swap[i][j];
        }
    }
    return flag;
}

void startGame(int **display, int **swap) {
    int delay = setDelay();
    if (delay != 0) {
        int alive = swapGeneration(display, swap);
        int counterOfGens = 0;
        while (alive && counterOfGens < MAX_GENS) {
            alive = swapGeneration(display, swap);
            system("clear");
            output(swap);
            usleep(delay);
            counterOfGens++;
        }
        if (alive == 0) {
            printf("клетки мертвы:((((((((((((((((((((\n");
        }
    }
}

int setDelay() {
    int delay = 0;
    printf("Введите значение задержки\n");
    if (scanf("%d", &delay) != 1 || delay <= 0) {
        delay = 0;
        printf("Вы ввели неверное значение задержки\n");
    }
    return delay;
}

void freeMatrix(int **matrix) {
    for (int i = 0; i < Y; i++) {
        free(matrix[i]);
    }
    free(matrix);
}
