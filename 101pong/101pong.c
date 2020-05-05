/*
** 101pong.c for 101pong in /home/leroy_0/rendu/101pong
**
** Made by maxime leroy
** Login   <leroy_0@epitech.net>
**
** Started on  Mon Nov  2 10:38:03 2015 maxime leroy
** Last update Fri Nov 13 12:33:16 2015 leroy_0
*/

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int	pong(char **av)
{
  float x1 = atof(av[4]);
  float x0 = atof(av[1]);
  float y0 = atof(av[2]);
  float y1 = atof(av[5]);
  float z0 = atof(av[3]);
  float z1 = atof(av[6]);
  int tmp = atoi(av[7]);
  float h;
  float res;
  float x = (x1 - x0);
  float y = (y1 - y0);
  float z = (z1 - z0);
  if (x0 == x1 && y0 == y1 && z0 == z1)
    return (84);
  printf("The speed vector coordinates are :\n(%.2f;%.2f;%.2f)\n", x, y, z);
  printf("At time t+%d, ball coordinates will be :\n(%.2f;%.2f;%.2f)\n", tmp, x * tmp + x1, y * tmp + y1, z * tmp + z1);
  if (z0 < z1 && 0 < z0 && 0 < z1)
    {
      printf("The ball won't reach the bat.\n");
      return (0);
    }
  else if (z0 < z1 && z0 < 0 && 0 < z1)
    {
      printf("The ball won't reach the bat.\n");
      return (0);
    }
  else if (z0 > z1 && z0 > 0 && 0 > z1)
    {
      printf("The ball won't reach the bat.\n");
      return (0);
    }
  else if (z0 > z1 && 0 > z0 && 0 > z1)
    {
      printf("The ball won't reach the bat.\n");
      return (0);
    }
  else if (z0 == z1 && z0 != 0)
    {
      printf("The ball won't reach the bat.\n");
      return (0);
    }
  else
    {
      h = sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2));
      res = z/h;
      res = acos(res);
      res = res*180/M_PI;
      res = res - 90;
      if ((x*tmp+x1) == 0 && (y*tmp+y1) == 0 && (z*tmp+z1) == 0)
	return (84);
      printf("The incidence angle is :\n");
      printf("%.2f degrees\n", fabs(res));
      return (0);
    }
}

int	main(int ac, char **av)
{
  int a = 0;
  int b = 1;
  int i;
  if (ac != 8)
    return (84);
  i = 0;
  while (av[7][i] != '\0')
    {
      if (av[7][i] == '.')
	return (84);
      i++;
    }
  while (b != 8)
    {
      while ((av[b][a] >= '0' && av[b][a] <= '9')
	|| av[b][a] == '-' || av[b][a] == '+' || av[b][a] == '.')
      a++;
      if ((av[b][a] < '0' || av[b][a] > '9')
	&& av[b][a] != '-' && av[b][a] != '+' && av[b][a] != '\0' && av[b][a] != '.')
      return (84);
      a = 0;
      b++;
    }
  int n = atoi(av[7]);
  if (n < 0)
    return (84);
  pong(av);
  return (0);
}
