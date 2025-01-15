CFLAGS = -Wall -Wextra -Werror
all: build

build: strlen_tests strcmp_tests strcpy_tests strcat_tests strchr_tests

rebuild: clean build

s21_string.o: s21_string.c
	gcc -c $(CFLAGS) s21_string.c -o s21_string.o

# Quest 1: STRLEN
strlen_tests.o: s21_string_test.c
	gcc -c $(CFLAGS) -D STRLEN s21_string_test.c -o strlen_tests.o
strlen_tests: strlen_tests.o s21_string.o
	gcc strlen_tests.o s21_string.o -o ../build/Quest_1
	make clean_o

# Quest 2: STRCMP
strcmp_tests.o: s21_string_test.c
	gcc -c $(CFLAGS) -D STRCMP s21_string_test.c -o strcmp_tests.o
strcmp_tests: strcmp_tests.o s21_string.o
	gcc strcmp_tests.o s21_string.o -o ../build/Quest_2
	make clean_o

# Quest 3: STRCPY
strcpy_tests.o: s21_string_test.c
	gcc -c $(CFLAGS) -D STRCPY s21_string_test.c -o strcpy_tests.o
strcpy_tests: strcpy_tests.o s21_string.o
	gcc strcpy_tests.o s21_string.o -o ../build/Quest_3
	make clean_o

# Quest 4: STRCAT
strcat_tests.o: s21_string_test.c
	gcc -c $(CFLAGS) -D STRCAT s21_string_test.c -o strcat_tests.o
strcat_tests: strcat_tests.o s21_string.o
	gcc strcat_tests.o s21_string.o -o ../build/Quest_4
	make clean_o

# Quest 5: STRCHR
strchr_tests.o: s21_string_test.c
	gcc -c $(CFLAGS) -D STRCHR s21_string_test.c -o strchr_tests.o
strchr_tests: strchr_tests.o s21_string.o
	gcc strchr_tests.o s21_string.o -o ../build/Quest_5
	make clean_o

# Quest 6: STRSTR
strstr_tests.o: s21_string_test.c
	gcc -c $(CFLAGS) -DSTRSTR s21_string_test.c -o strstr_tests.o
strstr_tests: strstr_tests.o s21_string.o
	gcc strstr_tests.o s21_string.o -o ../build/Quest_6

# CLEAN
clean:
	rm -rf ./*.o
	rm -rf ../build/Quest_*
clean_o:
	rm -rf ./*.o