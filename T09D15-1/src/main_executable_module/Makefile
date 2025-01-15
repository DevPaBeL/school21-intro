CC = gcc
CFLAGS = -g -std=c11 -Wall -Wextra -Werror
OUT_DIR = $(CURDIR)/../../build
all: build
build: main_executable_module.o data_io.o data_stat.o data_process.o decision.o
	$(CC) $(CFLAGS) $(OUT_DIR)/main_executable_module.o $(OUT_DIR)/data_io.o $(OUT_DIR)/data_stat.o $(OUT_DIR)/data_process.o $(OUT_DIR)/decision.o -o $(OUT_DIR)/Quest_3
	make clean
build_with_macro: main_executable_module_macro.o data_stat.o data_process.o decision.o
	$(CC) $(CFLAGS) $(OUT_DIR)/main_executable_module_macro.o $(OUT_DIR)/data_stat.o $(OUT_DIR)/data_process.o $(OUT_DIR)/decision.o -o $(OUT_DIR)/Quest_4
	make clean
build_with_static: main_executable_module.o data_io.o data_stat.a data_process.o decision.o
	$(CC) $(CFLAGS) $(OUT_DIR)/main_executable_module.o $(OUT_DIR)/data_io.o -L. data_stat.a $(OUT_DIR)/data_process.o $(OUT_DIR)/decision.o -o $(OUT_DIR)/Quest_5
	make clean
	
build_with_dynamic: main_executable_module.o data_io.o data_process.so decision.o
	$(CC) $(CFLAGS) -L. $(OUT_DIR)/main_executable_module.o $(OUT_DIR)/data_io.o $(OUT_DIR)/data_process.so $(OUT_DIR)/decision.o -o $(OUT_DIR)/Quest_6
	make clean_except_dynamic
rebuild: clean_all build
data_stat.a: data_stat.o
	ar r data_stat.a $(OUT_DIR)//data_stat.o
data_process.so: ../data_module/data_process.c data_stat.a
	$(CC) -shared -fPIC -o $(OUT_DIR)/data_process.so ../data_module/data_process.c ./data_stat.a
main_executable_module.o: main_executable_module.c
	$(CC) $(CFLAGS) -c main_executable_module.c -o $(OUT_DIR)/main_executable_module.o
main_executable_module_macro.o: main_executable_module.c
	$(CC) $(CFLAGS) -c main_executable_module.c -D MACRO -o $(OUT_DIR)/main_executable_module_macro.o
data_io.o: ../data_libs/data_io.c
	$(CC) $(CFLAGS) -c ../data_libs/data_io.c -o $(OUT_DIR)/data_io.o
data_process.o: ../data_module/data_process.c
	$(CC) $(CFLAGS) -c ../data_module/data_process.c -o $(OUT_DIR)/data_process.o
data_stat.o: ../data_libs/data_stat.c
	$(CC) $(CFLAGS) -c ../data_libs/data_stat.c  -o $(OUT_DIR)/data_stat.o
decision.o: ../yet_another_decision_module/decision.c
	$(CC) $(CFLAGS) -c ../yet_another_decision_module/decision.c -o $(OUT_DIR)/decision.o
clean:
	rm -rf $(OUT_DIR)/*.o
	rm -rf $(OUT_DIR)/*.so
	rm -rf ./*.a
clean_except_dynamic:
	rm -rf $(OUT_DIR)/*.o
	rm -rf ./*.a
clean_all:
	rm -rf $(OUT_DIR)/Quest_*
	rm -rf $(OUT_DIR)/*.o
	rm -rf $(OUT_DIR)/*.so
	rm -rf ./*.a