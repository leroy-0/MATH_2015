##
## Makefile for Makefile in /home/leroy_0/rendu/Piscine_C_bistromathique
##
## Made by maxime leroy
## Login   <leroy_0@epitech.net>
##
## Started on  Wed Oct 28 13:45:12 2015 maxime leroy
## Last update Wed Mar 30 17:39:45 2016 Tekm
##

CC =	gcc

RM =	rm -Rf

CFLAGS =	-Wextra -Wall -W

CFLAGS +=	-I./include

MATH =	-lm

NAME =	109titration

SRCS =  src/109titration.c \
	src/get_next_line.c

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
