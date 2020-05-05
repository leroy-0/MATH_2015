/*
** 110borwein.c for 110borwein in /home/tekm/tek1/110borwein
**
** Made by Tekm
** Login   <tekm@epitech.net>
**
** Started on  Fri Apr 15 11:09:10 2016 Tekm
** Last update Sun Apr 17 14:18:12 2016 Tekm
*/

#include <math.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

double			my_res(double n, double x)
{
  double		res = 1;
  double		k = 0;
  double		two = 2;
  double	        one = 1;

  if (x == 0)
    return (res);
  while (k <= n)
    {
      res = res * (sin(x / ((two * k) + one)) / (x / ((two * k) + one)));
      k++;
    }
  return (res);
}

void			my_rectangle_method(double nb)
{
  double		a = 0;
  double		b = 5000;
  double		i = a;
  double		h = (b - a);
  double		result = 0;
  double		two = 2;
  double		bign = 10000;

  h /= bign;
  while (i < bign)
    {
      result = result + my_res(nb, (a + i * h));
      i++;
    }
  result = result * h;
  printf("Rectangles:\n");
  printf("I%.0f = %.10f\n", nb, result);
  printf("diff = %.10f\n\n", result - (M_PI / two));
}

void			my_trapezoid_method(double nb)
{
  double		a = 0;
  double		b = 5000;
  double		i = 1;
  double		h = (b - a) / 10000;
  double		result = 0;
  double		two = 2;
  double		bign = 20000;

  while (i < 10000)
    {
      result = result + my_res(nb, (a + i * h));
      i++;
    }
  result = ((result * two) + my_res(nb, a) + my_res(nb, b)) *
    ((b - a) / bign);
  printf("Trapezoids:\n");
  printf("I%.0f = %.10f\n", nb, result);
  printf("diff = %.10f\n\n", result - (M_PI / two));
}

void			my_simpson_method(double nb)
{
  double		a = 0;
  double		b = 5000;
  double		i = a;
  double		h = (b - a) / 10000;
  double		result = 0;
  double		res = 0;
  double		final;
  double		two = 2;
  double		four = 4;
  double		bign = 60000;

  while (i < 10000)
    {
      result = result + my_res(nb, (a + i * h) + (h / two));
      i++;
    }
  i = 1;
  while (i < 10000)
    {
      res = res + my_res(nb, (a + i * h));
      i++;
    }
  final = ((result * four) + (res * two) + my_res(nb, a) + my_res(nb, b)) *
    ((b - a) / bign);
  printf("Simpson:\n");
  printf("I%.0f = %.10f\n", nb, final);
  printf("diff = %.10f\n", final - (M_PI / two));
}

void			my_110borwein(double nb)
{
  my_rectangle_method(nb);
  my_trapezoid_method(nb);
  my_simpson_method(nb);
}

int			my_check(char *str)
{
  int		cpt = 0;

  while (str && str[cpt])
    {
      if (str[cpt] < '0' || str[cpt] > '9')
	return (1);
      cpt++;
    }
  return (0);
}

int			main(int argc, char **argv)
{
  (void)argc;
  (void)argv;
  if (argc == 2)
    {
      if (strncmp(argv[1], "-h", strlen("-h")) == 0)
	{
	  printf("USAGE\n");
	  printf("	./110borwein n\n\n");
	  printf("DESCRIPTION\n");
	  printf("	n	constant defining the integral to be computed\n");
	  return (84);
	}
      else
	{
	  if (my_check(argv[1]) == 1)
	    {
	      printf("Error : argument n must be a positive number\n");
	      return (84);
	    }
	  if (atoi(argv[1]) < 0)
	    {
	      printf("Error : argument n must be a positive number\n");
	      return (84);
	    }
	  my_110borwein(atof(argv[1]));
	  return (0);
	}
    }
  return (84);
}
