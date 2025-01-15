#ifndef SRC_FILE_IO_H_
#define SRC_FILE_IO_H_

#include <stdio.h>

#include "cipher.h"

int readFile(char* path);
int writeToFile(char* path);
int fileOutput(FILE* ptr);
int fileInput(FILE* ptr);

#endif  // SRC_FILE_IO_H_
