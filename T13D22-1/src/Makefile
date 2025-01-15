all: cipher

FLAGS = -Wall -Wextra -Werror



cipher: cipher.c file_io.c
	gcc -c cipher.c file_io.c
	gcc cipher.o file_io.o -o ../build/cipher

clean:
	rm *.o
	rm ../build/*