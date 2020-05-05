##
## Makefile for Makefile in /home/leroy_0/rendu/Piscine_C_bistromathique
##
## Made by maxime leroy
## Login   <leroy_0@epitech.net>
##
## Started on  Wed Oct 28 13:45:12 2015 maxime leroy
## Last update Mon Feb 29 16:42:50 2016 Tekm
##

CC =	gcc

RM =	rm -f

CFLAGS +=	-Wextra -Wall

NAME =	107transfer

SRCS =  107transfer.c

OBJS =	$(SRCS:.c=.o)

all:	$(NAME)

$(NAME):	$(OBJS)
	  $(CC) -o $(NAME) $(SRCS) $(CFLAGS)

clean:
	$(RM) $(OBJS)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

.PHONY:	all clean fclean re
