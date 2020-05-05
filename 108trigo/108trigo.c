/*
** 108trigo.c for 108trigo in /home/tekm/tek1/108trigo
**
** Made by Tekm
** Login   <tekm@epitech.net>
**
** Started on  Fri Mar 18 12:21:40 2016 Tekm
** Last update Fri Mar 18 13:03:29 2016 Tekm
*/

#include <string.h>
#include <stdio.h>
#include <math.h>
#include <unistd.h>
#include <stdlib.h>

void			opt_exp(int ac, char **av, int cpt, int cpt_c, int sq)
{
  while (cpt_c < (ac - 2))
    {
      while (cpt < sq)
	{
	  printf("%.2f", atof(av[cpt + cpt_c]));
	  if (cpt + 1 != sq)
	    printf("	");
	  cpt++;
	}
      printf("\n");
      cpt_c += sq;
      cpt = 0;
    }
}

void			opt_cos(int ac, char **av, int cpt, int cpt_c, int sq)
{
  while (cpt_c < (ac - 2))
    {
      while (cpt < sq)
	{
	  printf("%.2f", atof(av[cpt + cpt_c]));
	  if (cpt + 1 != sq)
	    printf("	");
	  cpt++;
	}
      printf("\n");
      cpt_c += sq;
      cpt = 0;
    }
}

void			opt_sin(int ac, char **av, int cpt, int cpt_c, int sq)
{
  while (cpt_c < (ac - 2))
    {
      while (cpt < sq)
	{
	  printf("%.2f", atof(av[cpt + cpt_c]));
	  if (cpt + 1 != sq)
	    printf("	");
	  cpt++;
	}
      printf("\n");
      cpt_c += sq;
      cpt = 0;
    }
}

void			opt_cosh(int ac, char **av, int cpt, int cpt_c, int sq)
{
  while (cpt_c < (ac - 2))
    {
      while (cpt < sq)
	{
	  printf("%.2f", atof(av[cpt + cpt_c]));
	  if (cpt + 1 != sq)
	    printf("	");
	  cpt++;
	}
      printf("\n");
      cpt_c += sq;
      cpt = 0;
    }
}

void			opt_sinh(int ac, char **av, int cpt, int cpt_c, int sq)
{
  while (cpt_c < (ac - 2))
    {
      while (cpt < sq)
	{
	  printf("%.2f", atof(av[cpt + cpt_c]));
	  if (cpt + 1 != sq)
	    printf("	");
	  cpt++;
	}
      printf("\n");
      cpt_c += sq;
      cpt = 0;
    }
}

void			opt_help()
{
  printf("USAGE           \n           ./108trigo fun a0 a1 a2....\n\nDESCRIPTION\n");
  printf("           fun  function to be applied, among at least EXP, COS, SIN, COSH and SINH\n");
  printf("           ai   coeficients of the matrix\n");
}

void			my_108trigo(int ac, char **av)
{
  double			sq = sqrt(ac - 2);
  int				cpt = 0;
  int				cpt_c = 0;
  int				matrix = (ac - 2) / sq;

  if (ac == 2 && strcmp(av[1], "-h") == 0)
    opt_help();
  else if (matrix == sq)
    {
      if (ac >= 2 && strcmp(av[1], "EXP") == 0)
	opt_exp(ac, av, cpt, cpt_c, sq);
      else if (ac >= 2 && strcmp(av[1], "COS") == 0)
	opt_cos(ac, av, cpt, cpt_c, sq);
      else if (ac >= 2 && strcmp(av[1], "SIN") == 0)
	opt_sin(ac, av, cpt, cpt_c, sq);
      else if (ac >= 2 && strcmp(av[1], "COSH") == 0)
	opt_cosh(ac, av, cpt, cpt_c, sq);
      else if (ac >= 2 && strcmp(av[1], "SINH") == 0)
	opt_sinh(ac, av, cpt, cpt_c, sq);
      else
	exit(84);
    }
  else
    exit(84);
}

int			main(int ac, char **av)
{
  my_108trigo(ac, av);
  return (0);
}
