##
## Makefile for Makefile in /home/leroy_0/rendu/Piscine_C_bistromathique
##
## Made by maxime leroy
## Login   <leroy_0@epitech.net>
##
## Started on  Wed Oct 28 13:45:12 2015 maxime leroy
## Last update Mon Jan 18 11:43:07 2016 Arthur Klein
##

CC =	gcc

RM =	rm -f

CFLAGS +=	-Wextra -Wall

LDFLAGS =	-lm

NAME =	105torus

SRCS =  105torus.c

OBJS =	$(SRCS:.c=.o)

all:	$(NAME)

$(NAME):	$(OBJS)
	  $(CC) -o $(NAME) $(SRCS) $(LDFLAGS) $(CFLAGS)

clean:
	$(RM) $(OBJS)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

.PHONY:	all clean fclean re
