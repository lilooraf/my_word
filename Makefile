##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile
##

SRC	=	main.c			\
		src/my_world.c		\
		src/button.c		\
		src/change_map.c		\
		src/change_map_tools.c	\
		src/disp_map.c		\
		src/create_map.c	\
		src/check_error.c

OBJ	=	$(SRC:.c=.o)

NAME 	=	my_world

CFLAGS	=	-Iinclude -L lib/my -lmy -g3

LDFLAGS	=	-lcsfml-graphics -lcsfml-window -lcsfml-audio -lcsfml-system -lm

all:	$(NAME)

$(NAME):	$(OBJ)
	make -C ./lib/my/
	gcc -o $(NAME) $(OBJ) $(CFLAGS) $(LDFLAGS)

clean:
	make clean -C ./lib/my/
	rm -f $(OBJ)

fclean:	clean
	make fclean -C ./lib/my/
	rm -f $(NAME)

re:	fclean all
