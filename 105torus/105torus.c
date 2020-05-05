/*
** 105torus.c for 105torus in
**
** Made by leroy_0
** Login   <leroy_0@epitech.net>
**
** Started on  Thu Jan 14 19:39:32 2016 leroy_0
** Last update Sun Jan 17 17:32:40 2016 leroy_0
*/

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

# define ABSOLUTE(x) ((x) < 0) ? -(x) : (x)

double		my_absolute(double x)
{
  x = (x > 0) ? - x : x;
  return (x);
}

double		my_poly(int *tab, double x)
{
  double		tmp = (tab[5] * pow(x, 4));

  tmp += (tab[4] * pow(x, 3));
  tmp += (tab[3] * pow(x, 2));
  tmp += (tab[2] * x);
  tmp += tab[1];
  return (tmp);
}

double		my_deri(int *tab, double x)
{
  double		tmp = ((4 * tab[5]) * pow(x, 3));

  tmp += ((3 * tab[4]) * pow(x, 2));
  tmp += ((2 * tab[3]) * x);
  tmp += tab[2];
  return (tmp);
}

int		my_bissec(int *tab)
{
  double		x1 = 0;
  double		x2 = 1;
  double		xm;
  int			a = 0;

  while ((x2 - x1) > pow(10, -tab[6]))
    {
      xm = ((x1 + x2) / 2);
      if (my_poly(tab, x1) * my_poly(tab, xm) >= 0)
	x1 = xm;
      else
	x2 = xm;
      a++;
      printf("x = %.*g\n", tab[6], xm);
      if (a > 100)
	return (84);
    }
  return (0);
}

int		my_newt(int *tab)
{
  double		xn = 0.5;
  int			a = 0;

  while (ABSOLUTE(my_poly(tab, xn)) > pow(10, -tab[6]))
    {
      xn = (xn - (my_poly(tab, xn) / my_deri(tab, xn)));
      if (my_deri(tab, xn) == 0)
	return (84);
      printf("x = %.*g\n", tab[6], xn);
      a++;
      if (a > 100)
	return (84);
    }
  return (0);
}

int		my_seca(int *tab)
{
  double		x1 = 0;
  double		x2 = 1;
  double		xn1;
  int			a = 0;

  while (ABSOLUTE(my_poly(tab, x2)) > pow(10, -tab[6]))
    {
      xn1 = x2 - (((my_poly(tab, x2)) * (x2 - x1)) /  (my_poly(tab, x2) - (my_poly(tab, x1))));
      if (my_poly(tab, x2) == my_poly(tab, x1))
	return (84);
      printf("x = %.*g\n", tab[6], xn1);
      x1 = x2;
      x2 = xn1;
      a++;
      if (a > 100)
	return (84);
    }
  return (0);
}

int		my_check(int *tab,  char **argv)
{
  int		cpt;
  int		a = 1;

  while (argv[a])
    {
      cpt = -1;
      while (argv[a][++cpt])
	if ((argv[a][cpt] < 48 || argv[a][cpt] > 57)
	    && argv[a][cpt] != '-')
	  return (84);
      a++;
    }
  if (tab[1] == 0 && tab[2] == 0 && tab[4] == 0 && tab[3] == 0 && tab[5] == 0)
    return (84);
  if (tab[6] < 0)
    return (84);
  return (0);
}

int		*my_tab(char **argv)
{
  int		*tab;
  int		a = 1;

  if ((tab = malloc(sizeof(int) * 8)) == NULL)
    return (NULL);
  while (argv[a])
    {
      tab[a - 1] = atoi(argv[a]);
      a++;
    }
  return (tab);
}

int		main(int argc, char **argv)
{
  int		*tab;

  if (argc != 8)
    return (84);
  if ((tab = my_tab(argv)) == NULL)
    return (84);
  if (my_check(tab, argv) != 0)
    return (84);
  if (tab[0] > 3 || tab[0] < 1)
    return (84);
  if (tab[0] == 1)
    my_bissec(tab);
  else if (tab[0] == 2)
    my_newt(tab);
  else if (tab[0] == 3)
    my_seca(tab);
  else
    return (84);
  return (0);
}
