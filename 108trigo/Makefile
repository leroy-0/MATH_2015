##
## Makefile for Makefile in /home/leroy_0/rendu/Piscine_C_bistromathique
## 
## Made by maxime leroy
## Login   <leroy_0@epitech.net>
## 
## Started on  Wed Oct 28 13:45:12 2015 maxime leroy
## Last update Fri Mar 18 12:16:25 2016 Tekm
##

CC =	gcc

RM =	rm -Rf

CFLAGS =	-Wextra -Wall -W -lm

NAME =	108trigo

SRCS =  108trigo.c

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
