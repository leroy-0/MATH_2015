/*
** 109titration.c for 109titration in /home/tekm/tek1/109titration
**
** Made by Tekm
** Login   <tekm@epitech.net>
**
** Started on  Wed Mar 30 16:49:43 2016 Tekm
** Last update Sun Apr  3 16:26:10 2016 Arthur Klein
*/

#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include "get_next_line.h"

int			my_109titration(char *name)
{
  char		*str;
  int		fd;

  if ((fd = open(name, O_RDONLY)) == -1)
    {
      printf("Error : File '%s' does not exist\n", name);
      return (84);
    }
  while ((str = get_next_line(fd)) != NULL)
    printf("%s\n", str);
  return (84);
}

int			main(int ac, char **av)
{
  if (ac == 2 || ac == 1)
    {
      if (!av[1] || (av[1][0] == '-' && av[1][1] == 'h'))
	{
	  printf("USAGE\n");
	  printf("	%s file\n", av[0]);
	  printf("DESCRIPTION\n");
	  printf("	file	a csv file containing \"vol;ph\" lines\n");
	}
      else
	return (my_109titration(av[1]));
    }
  else
    return (84);
  return (0);
}
