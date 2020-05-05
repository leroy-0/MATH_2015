/*
** 107transfer.c for 107transfer in /home/tekm/tek1/107transfer
**
** Made by Tekm
** Login   <tekm@epitech.net>
**
** Started on  Mon Feb 29 16:43:02 2016 Tekm
** Last update Mon Feb 29 17:00:27 2016 Tekm
*/

#include <stdlib.h>
#include <stdio.h>

int			my_107transfer(char **av)
{
  int		cpt = 1;
  int		r = 0;

  (void)av;
  while (av[cpt])
    {
      while (av[cpt][r])
	{
	  if (av[cpt][r] != '*' && (av[cpt][r] > '9' || av[cpt][r] < '0'))
	    {
	      printf("Error: Invalid argument '%s'\n", av[cpt]);
	      return (84);
	    }
	  r++;
	}
      cpt++;
      r = 0;
    }
  return (0);
}

int			main(int ac, char **av)
{
  if (ac == 1)
    {
      printf("USAGE\n           ./107transfer [num den]\n\n");
      printf("DESCRIPTION\n         num  polynomial numerator defined by its coeficients\n");
      printf("         den  polynomial denominator defined by its coeficients\n");
      return (84);
    }
  else
    return (my_107transfer(av));
  return (0);
}
