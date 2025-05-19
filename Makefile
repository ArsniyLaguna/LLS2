clear: 
	rm -rf *.o *.a *_test

fmt: 
	clang-format -style=LLVM -i `find -regex ".+\.[ch]"`

cFmt:
	clang-format -style=LLVM -i `find -regex ".+\.[ch]"` --dry-run --Werror

test: test_list

list.o: list.c list.h
	gcc -g -c list.c -o list.o

list.a: list.o
	ar rc list.a list.o

test_list.o: test_list.c list.h
	gcc -g -c test_list.c -o test_list.o

test_list: test_list.o list.a
	gcc -g -o test_list test_list.o list.a 

