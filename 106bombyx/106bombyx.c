/*
** 106bombyx.c for bombyx in /home/leroy_0/rendu/106bombyx
**
** Made by leroy_0
** Login   <leroy_0@epitech.net>
**
** Started on  Mon Feb  8 11:12:16 2016 leroy_0
** Last update Sun Feb 21 22:58:36 2016 Tekm
*/

#include <stdlib.h>
#include <stdio.h>

int		my_opt1(char **arg)
{
  float		n = atof(arg[1]);
  float		k = atof(arg[2]);
  float		num = 1000.000000000;
  int		a = 1;
  int		x = 0;

  while (arg[1][x])
    {
      if ((arg[1][x] < '0' || arg[1][x] > '9'))
	{
	  printf("Error: Argument isnt a number\n");
	  return (84);
	}
      x++;
    }
  x = 0;
  while (arg[2][x])
    {
      if ((arg[2][x] < '0' || arg[2][x] > '9') && arg[2][x] != '.')
	{
	  printf("Error: Argument isnt a number\n");
	  return (84);
	}
      x++;
    }
  if (k > 4.00000000 || k < 1.0000000)
    {
      printf("Error: K must be between 0 and 4\n");
      return (84);
    }
  if (n < 0)
    {
      printf("Error: N must be positive\n");
      return (84);
    }
  while (a <= 100)
    {
      printf("%d %.2f\n",a , n);
      n = (float)((float)k * (float)n * ((float)((float)num - (float)n) / (float)num));
      if (n < 0)
	n = 0.00;
      a++;
    }
  return (0);
}

int		my_opt2(char **arg)
{
  double		k = (double)1.00000000;
  double		n = (double)atof(arg[1]);
  double		min = (double)atof(arg[2]);
  double		max = (double)atof(arg[3]);
  double		num = (double)1000.0000000;
  int		cpt;
  int		x = 0;

  while (arg[1][x])
    {
      if ((arg[1][x] < '0' || arg[1][x] > '9'))
	{
	  printf("Error: Argument isnt a number\n");
	  return (84);
	}
      x++;
    }
  x = 0;
  while (arg[2][x])
    {
      if ((arg[2][x] < '0' || arg[2][x] > '9'))
	{
	  printf("Error: Argument isnt an int\n");
	  return (84);
	}
      x++;
    }
  x = 0;
  while (arg[3][x])
    {
      if ((arg[3][x] < '0' || arg[3][x] > '9'))
	{
	  printf("Error: Argument isnt an int\n");
	  return (84);
	}
      x++;
    }
  if (min < 1 || max < 1)
    {
      printf("Error: Arguments need to be superior to 0\n");
      return (84);
    }
  if (min > max)
    {
      printf("Error: i0 must be inferior to i1\n");
      return (84);
    }
  if (n < 0)
    {
      printf("Error: N must be positive\n");
      return (84);
    }
  if (n <= 0)
    n = 0.000000000000;
  x = n;
  while (k <= 4)
    {
      cpt = 2;
      while (cpt <= max)
	{
	  while (cpt < min)
	    {
	      n = (double)((double)k * (double)n * ((double)((double)num - (double)n) / (double)num));
	      if (n < 0)
		n = 0.000000000000000;
	      cpt++;
	    }
	  n = (double)((double)k * (double)n * ((double)((double)num - (double)n) / (double)num));
	  if (n < 0)
	    n = 0.0000000000000000;
	  printf("%.2lf %.2lf\n",k , n);
	  cpt++;
	}
      k += 0.01;
      n = x;
    }
  return (0);
}

int		main(int ac, char **av)
{
  if (ac != 3 && ac != 4)
    {
      printf("Usage: ./106bombyx n [k | i0 i1]\n");
      return (84);
    }
  if (ac == 3)
    {
      if (my_opt1(av) == 84)
	return (84);
    }
  if (ac == 4)
    {
      if (my_opt2(av) == 84)
	return (84);
    }
  return (0);
}
