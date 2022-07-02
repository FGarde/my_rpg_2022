##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## Makefile lib
##

SRC	=	my_get_nbr.c			\
		my_putstr.c 			\
		my_putchar.c 			\
		my_strlen.c 			\
		my_int_to_str.c 		\
		my_str_to_word_array.c	\
		my_strcmp.c 			\
		my_strncmp.c 			\
		my_strncpy.c 			\
		linked_list.c 			\

OBJ	=	$(SRC:.c=.o)

NAME	= 	libmy.a

all: 	$(NAME)

$(NAME): 	$(OBJ)
	ar rc $(NAME) $(OBJ)
	mkdir -p ../../includes
	cp my_lib.h ../../includes
	cp linked_list.h ../../includes
	cp $(NAME) ../../lib

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:	fclean all
