##
## Makefile for Makefile in /home/leroy_0/rendu/Piscine_C_bistromathique
##
## Made by maxime leroy
## Login   <leroy_0@epitech.net>
##
## Started on  Wed Oct 28 13:45:12 2015 maxime leroy
## Last update Fri Apr 15 11:08:57 2016 Tekm
##

CC =	gcc

RM =	rm -Rf

CFLAGS =	-Wextra -Wall -W

CFLAGS +=	-I./include

MATH =	-lm

NAME =	110borwein

SRCS =  110borwein.c

OBJS =	$(SRCS:.c=.o)

all:	$(NAME)

$(NAME):	$(OBJS)
	  $(CC) -o $(NAME) $(OBJS) $(MATH)

clean:
	$(RM) $(OBJS)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

.PHONY:	all clean fclean re
