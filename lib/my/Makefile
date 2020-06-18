##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## return
##

SRC =	my_strlen.c					\
		my_getnbr.c					\
		my_putstr.c					\
		my_putchar.c				\
		my_put_array.c				\
		my_put_nbr.c				\
		my_strcmp.c					\
		my_free_array.c				\
		my_strcat.c					\
		my_strcmp_mn.c				\
		my_putstrtwo.c				\
		my_str_to_word_array.c		\
		my_strdup.c

OBJ = $(SRC:.c=.o)

NAME = libmy.a

HEADER  = 	my.h

build:
	gcc -c -g $(SRC)
	ar rc $(NAME) $(OBJ)
	cp $(NAME) ../
	cp $(HEADER) ../../include/