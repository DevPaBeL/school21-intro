#ifndef PROCESSING_H
#define PROCESSING_H

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "../data_libs/data_io.h"
#include "../data_libs/data_stat.h"

#define EPS 1E-6

int normalization(double *data, int n);

#endif