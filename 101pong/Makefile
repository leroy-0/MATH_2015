

NAME		=	101pong

LIB		=	-lm

FLAG		=	-W -Wall -ansi -pedantic -I/home/${USER}/.froot/include/

SRC		=	101pong.c \

OBJ		=	$(SRC:.c=.o)

CC		=	gcc

all:		$(NAME)

$(NAME):	$(OBJ)
		$(CC) -o $(NAME) $(SRC) $(LIB)
clean:
		rm -f $(OBJ)

fclean:		clean
		rm -f $(NAME)

re:		fclean all

.PHONY:	all clean fclean re