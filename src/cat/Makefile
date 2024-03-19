CC= gcc -std=c11
CFLAGS= -Wall -Wextra -Werror -g
OS := $(shell uname -s)

all: cat

cat:
	$(CC) $(CFLAGS) cat.c -o cat -lm

test: cat
	chmod 777 test_func_cat.sh
	-./test_func_cat.sh

clean:
	rm -rf cat *.a *.out *.o *.dSYM *.txt

check: cat
	-cppcheck --enable=all --suppress=missingIncludeSystem ../../src/grep/
	cp ../../materials/linters/CPPLINT.cfg ./
	-python3 ../../materials/linters/cpplint.py --extensions=c ./*.c
	-python3 ../../materials/linters/cpplint.py --extensions=c ./*.h
	rm 	./CPPLINT.cfg
ifeq ($(OS), Darwin)
	-CK_FORK=no leaks --atExit -- ./cat -betns test/test_1_cat.txt test/test_2_cat.txt test/test_3_cat.txt test/test_4_cat.txt
else
	-valgrind --leak-check=full --quiet ./cat -betns test/test_1_cat.txt test/test_2_cat.txt test/test_3_cat.txt test/test_4_cat.txt
endif
	rm -rf cat *.a *.out *.o *.dSYM *.txt

.PHONY: all clean rebuild

rebuild: clean all