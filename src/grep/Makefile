CFLAGS=-c -Wall -Wextra -Werror

s21_grep: main.o parser.o reader.o
	gcc *.o -o s21_grep

main.o: main.c
	gcc $(CFLAGS) main.c

parser.o: parser.c
	gcc $(CFLAGS) parser.c

reader.o: reader.c
	gcc $(CFLAGS) reader.c

check:
	clang-format -n *.c *.h
	cppcheck main.c parser.c reader.c
	leaks -atExit -- ./s21_grep -l hey 1.txt 2.txt 3.txt
test:
	sh my_test.sh

clean:
	rm -rf *.o build