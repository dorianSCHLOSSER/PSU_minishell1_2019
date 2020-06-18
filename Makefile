##
## EPITECH PROJECT, 2019
## makefile
## File description:
## return
##

SRC = 	main.c				\
		src/my_pronpt.c		\
		src/my_getenv.c		\
		src/my_built.c		\
		src/my_builtt.c		\
		src/my_error.c		\
		src/my_option_get.c	\
		src/my_cd.c			\
		src/my_check_pwd.c

OBJ = $(SRC:.c=.o)

NAME = mysh

FLAGS =  -Llib/my -lmy

all:
	make -C lib/my build
	gcc -g -o $(NAME) $(SRC) $(FLAGS)

clean:
		rm -f $(OBJ)
		rm -f ./lib/my/*.o
		rm -f vgcore.*

fclean: clean
		rm -f $(NAME)
		rm -f ./lib/*.a
		rm -f ./lib/my/*.a

re: fclean all