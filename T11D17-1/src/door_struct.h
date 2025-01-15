#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct door {
    int id;
    int status;
};

void initialize_doors(struct door* doors);
void sortDors(struct door* doors);
void changeStatus(struct door* doors);
void output(struct door* doors);