/*
** 103architect.c for 103architect in /home/leroy_0/rendu/103architect
**
** Made by leroy_0
** Login   <leroy_0@epitech.net>
**
** Started on  Mon Dec  7 11:38:09 2015 leroy_0
** Last update Sun Dec 13 14:04:04 2015 leroy_0
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>

# define	degree	M_PI/180

void	my_choose(char **str)
{
  float	x;
  float	y;
  float	vectorx;
  float	vectory;
  float	angle;
  char	option;
  float	x0;
  float	y0;
  float	z0;
  float	x1;
  float	y1;
  float	z1;
  float	x2;
  float	y2;
  float	z2;

  x = atof(str[1]);
  y = atof(str[2]);
  option = str[3][1];
  vectorx = atof(str[4]);
  if (option != 'r' && option != 's')
    vectory = atof(str[5]);
  angle = vectorx;
  if (option == 't')
    {
      printf("Translation by the vector (%s, %s)\n", str[4], str[5]);
      x0 = 1;
      y0 = 0;
      z0 = vectorx;
      x1 = 0;
      y1 = 1;
      z1 = vectory;
      x2 = 0;
      y2 = 0;
      z2 = 1;
      printf("%.2f	%.2f	%.2f\n", x0, y0, z0);
      printf("%.2f	%.2f	%.2f\n", x1, y1, z1);
      printf("%.2f	%.2f	%.2f\n", x2, y2, z2);
      printf("(%.f,%.f) => (%.2f,%.2f)\n", x, y, vectorx+x, vectory+y);
    }
  else if (option == 'h')
    {
      printf("Homothety by the ratios %s and %s\n", str[4], str[5]);
      x0 = vectorx;
      y0 = 0;
      z0 = 0;
      x1 = 0;
      y1 = vectory;
      z1 = 0;
      x2 = 0;
      y2 = 0;
      z2 = 1;
      printf("%.2f	%.2f	%.2f\n", x0, y0, z0);
      printf("%.2f	%.2f	%.2f\n", x1, y1, z1);
      printf("%.2f	%.2f	%.2f\n", x2, y2, z2);
      printf("(%.f,%.f) => (%.2f,%.2f)\n", x, y, vectorx*x, vectory*y);
    }
  else if (option == 'r')
    {
      printf("Rotation at a %.f degree angle\n", angle);
      x0 = cos(angle*degree);
      y0 = -1*sin(angle*degree);
      z0 = 0;
      x1 = sin(angle*degree);
      y1 = cos(angle*degree);
      z1 = 0;
      x2 = 0;
      y2 = 0;
      z2 = 1;
      printf("%.2f	%.2f	%.2f\n", x0, y0, z0);
      printf("%.2f	%.2f	%.2f\n", x1, y1, z1);
      printf("%.2f	%.2f	%.2f\n", x2, y2, z2);
      printf("(%.f,%.f) => (%.2f,%.2f)\n", x, y, cos(angle*degree), sin(angle*degree));
    }
  else if (option == 's')
    {
      printf("Symmetry about an axis inclined with an angle of %.f degrees\n", angle);
      x0 = cos(2*angle*degree);
      y0 = sin(2*angle*degree);
      z0 = 0;
      x1 = sin(2*angle*degree);
      y1 = -1*cos(2*angle*degree);
      z1 = 0;
      x2 = 0;
      y2 = 0;
      z2 = 1;
      printf("%.2f	%.2f	%.2f\n", x0, y0, z0);
      printf("%.2f	%.2f	%.2f\n", x1, y1, z1);
      printf("%.2f	%.2f	%.2f\n", x2, y2, z2);
      printf("(%.f,%.f) => (%.2f,%.2f)\n", x, y, x*x0, y*y1);
    }
}

void	architect(char **str)
{
  my_choose(str);
}

int	main(int argc, char **argv)
{
  if (argc < 2)
    {
      write(1, "Usage: ./103architect x y option arg1 arg2\n", 43);
      return (84);
    }
  else if (argc == 6 && (argv[3][1] == 't' || argv[3][1] == 'h'))
    architect(argv);
  else if (argc == 5 && (argv[3][1] == 'r' || argv[3][1] == 's'))
    architect(argv);
  else
    {
      write(1, "Usage: ./103architect x y option arg1 arg2\n", 43);
      return (84);
    }
  return (0);
}
