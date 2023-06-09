##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## makefile
##

all:
	@make -C server/
	@make -C client/

clean:
	@rm -f myteams_cli
	@rm -f myteams_server
	@make clean -C server/
	@make clean -C client/

fclean:	clean
	@make fclean -C server/
	@make fclean -C client/

re:	fclean all
	@make re -C server/
	@make re -C client/
