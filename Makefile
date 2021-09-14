all:
	gcc -c -Wall -Wextra -Werror *.c; ar rc libftprintf.a *.o

clean:
	rm -f *.o

fclean: clean
	rm -f libftprintf.a
