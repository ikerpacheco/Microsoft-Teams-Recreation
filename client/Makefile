##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## makefile
##

SRC	=	main.c \
		client_funcs.c \
		error_handling.c \
		../structs/client.c \
		../structs/server.c \
		../utils/command.c \
		../utils/init_data.c \
		../utils/socket.c \
		../utils/my_str_to_arr.c \
		$(wildcard response/*.c) \

OBJ	=	$(SRC:.c=.o)

NAME	=	myteams_cli

CURSE =	-luuid -L../libs/myteams -lmyteams

CFLAGS = -g -I ../include

FLAGS =	-Wall -Werror -Wextra

all:	$(NAME)

$(NAME):	$(OBJ)
	@	gcc -o $(NAME) $(OBJ) $(FLAGS) $(CURSE) $(CFLAGS)
	@ 	cp $(NAME) ../

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all
	make clean
