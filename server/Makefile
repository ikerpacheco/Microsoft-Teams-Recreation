##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## makefile
##

SRC	=	src/error_handling.c 	\
		src/my_teams.c 			\
		src/server_connections.c \
		src/cmd_handler.c 		\
		../structs/server.c 	\
		../structs/client.c 	\
		../structs/team.c 		\
		../structs/comment.c	\
		../structs/channel.c 	\
		../structs/thread.c 	\
		../structs/chats.c 	\
		../structs/message.c 	\
		../utils/command.c 		\
		../utils/command2.c 		\
		../utils/init_data.c 	\
		../utils/socket.c 		\
		../utils/my_str_to_arr.c \
		../utils/check_logged.c \
		../utils/arr_len.c \
		src/commands/commands.c \
		src/commands/help.c \
		src/commands/list.c \
		src/commands/login.c \
		src/commands/logout.c \
		src/commands/users.c \
		src/commands/user.c \
		src/commands/create/create.c \
		src/commands/create/create_channel.c \
		src/commands/create/create_team.c \
		src/commands/create/create_thread.c \
		src/commands/use/use.c \
		src/commands/use/use_channel.c \
		src/commands/use/use_thread.c \
		src/commands/use/use_team.c \
		src/commands/send.c \
		src/add_clients.c \
		main.c

OBJ	=	$(SRC:.c=.o)

NAME	=	myteams_server

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
