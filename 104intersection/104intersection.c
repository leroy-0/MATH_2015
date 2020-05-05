/*
** 104intersection.c for 104intersection in /home/leroy_0/rendu/104intersection
**
** Made by leroy_0
** Login   <leroy_0@epitech.net>
**
** Started on  Wed Dec 16 15:16:28 2015 leroy_0
** Last update Wed Dec 16 15:34:54 2015 leroy_0
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>

int 		select_opt(int opt, char *av, int xp, int yp, int zp, int vx, int vy, int vz, float radius, float *a, float *b, float *c)
{
  if (opt == 1)
    {
      printf("sphere of radius %s\n", av);
      *a = (vx * vx) + (vy * vy) + (vz * vz);
      *b = (2 * xp * vx) + (2 * yp * vy) + (2 * zp * vz);
      *c = xp * xp + yp * yp + zp * zp - (radius * radius);
    }
  else if (opt == 2)
    {
      printf("cylinder of radius %s\n", av);
      *a = vx * vx + vy * vy;
      *b = (2 * xp * vx) + (2 * yp * vy);
      *c = xp * xp + yp * yp - (radius * radius);
    }
  else if (opt == 3)
    {
      radius = (M_PI / 2) - radius * M_PI / 180;
      printf("cone of %s degree angle\n", av);
      *a = (tan(radius) * tan(radius)) * (vx*vx + vy*vy) - vz*vz;
      *b = 2 * ((tan(radius) * tan(radius)) * (xp*vx + yp*vy) - zp*vz);
      *c = (tan(radius) * tan(radius)) * (xp*xp + yp*yp) - zp*zp;
    }
  else
    return (84);
  return (1);
}


int	calc_delta(float delta, float a, float b, int xp, int vx, int yp, int vy, int zp, int vz)
{

  float	x1;
  float	x2;

  if (delta == 0)
    {
      if (a != 0)
	{
	  x1 = -1 * (b / (2 * a));
	  printf("1 intersection point :\n");
	  printf("(%.3f, %.3f, %.3f)\n", xp + x1 * vx, yp + x1 * vy, zp + x1 * vz);
	}
      else if (a == 0)
	printf("There is an infinite number of intersection points.\n");
    }
  else if (delta < 0)
    printf("No intersection point.\n");
  else if (delta > 0)
    {
      printf("2 intersection points :\n");
      x1 = ((-b) - sqrt(delta)) / (2 * a);
      x2 = ((-b) + sqrt(delta)) / (2 * a);
      printf("(%.3f, %.3f, %.3f)\n", xp + (x2 * vx), yp + (x2 * vy), zp + (x2 * vz));
      printf("(%.3f, %.3f, %.3f)\n", xp + (x1 * vx), yp + (x1 * vy), zp + (x1 * vz));
    }
  return (0);
}

int		my_104intersection(char	*av, int opt, int xp, int yp, int zp, int vx, int vy, int vz)
  {
    float 	radius;
    float	delta;
    float	a;
    float	b;
    float	c;

    radius = atof(av);
    if (select_opt(opt, av, xp, yp, zp, vx, vy, vz, radius, &a, &b, &c) == 84)
      return (84);
    printf("straight line going through the (%d,%d,%d) point and of direction vector (%d,%d,%d)\n", xp, yp, zp, vx, vy, vz);
    delta = (b * b) - (4 * a * c);
    calc_delta(delta, a, b, xp, vx, yp, vy, zp, vz);
    return (0);
  }

int		my_error(char *str)
{
  int		i;

  i = 0;
  while (str[i])
    {
      if (str[i] == '-')
	i++;
      if (str[i] >= '0' && str[i] <= '9')
	i++;
      else
	return (84);
    }
  return (0);
}

int	check_num(char **av, int ac)
{
  int i;

  i = 1;
  while (i < ac)
    {
      if (my_error(av[i]) == 84)
	return(84);
      else
	i++;
    }
  return (1);
}

int	main(int ac, char **av)
{
  int		opt;
  int		xp;
  int		yp;
  int		zp;
  int		vx;
  int		vy;
  int		vz;

  if (check_num(av, ac) == 84)
    return (84);
  if (ac != 9)
    {
      printf("Usage: ./104intersection opt xp yp zp xv yv zv p\n");
      return (84);
    }
  else if (av[1][0] != '1' && av[1][0] != '2' && av[1][0] != '3')
    {
      printf("Usage: ./104intersection opt xp yp zp xv yv zv p\n");
      return (84);
    }
  else if (av[8][0] != '0')
    {
      opt = atoi(av[1]);
      xp = atoi(av[2]);
      yp = atoi(av[3]);
      zp = atoi(av[4]);
      vx = atoi(av[5]);
      vy = atoi(av[6]);
      vz = atoi(av[7]);
      if (my_104intersection(av[8], opt, xp, yp, zp, vx, vy, vz) == 84)
	return (84);
    }
  return (0);
}
