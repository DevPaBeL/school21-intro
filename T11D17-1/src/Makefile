.PHONY: door_struct list_test all clean rebuild
CC_FLAGS = -Wall -Werror -Wextra
all: door_struct list_test stack_test
# Quest 1
door_struct: dmanager_module.c
	gcc $(CC_FLAGS) dmanager_module.c -o ../build/Quest_1
# Quest 2
list_test: list_test.c list.c
	gcc $(CC_FLAGS) list_test.c list.c -o ../build/Quest_2
# Quest 3
stack_test: stack_test.c stack.c
	gcc $(CC_FLAGS) stack_test.c stack.c -o ../build/Quest_3
clean:
	rm -rf ../build/*
	rm -f *.o
rebuild: clean all