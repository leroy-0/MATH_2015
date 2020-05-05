/*
** 102cipher.c for 102cipher in /home/leroy_0/rendu/102cipher
**
** Made by leroy_0
** Login   <leroy_0@epitech.net>
**
** Started on  Fri Nov 13 15:29:31 2015 leroy_0
** Last update Sun Nov 29 23:36:59 2015 leroy_0
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <math.h>
#include "include/my.h"

void	my_encryption(char *msg, int *key, int column)
{
  int	b;
  int	a;
  int	len;
  int	len2;
  len = strlen(msg) - 1;
  len2 = sqrt(len) + 1;
  len2 = (len2*len2) - column;
  int	message[len2];

  a = 0;
  b = 0;
  key = key;
  while (a <= len)
    {
      if (b == column)
	b = 0;
      message[a] = (int)msg[a];
      a++;
      b++;
    }
  b = column - b;
  while (a <= len+b)
    {
      message[a] = 0;
      a++;
    }
  message[a] = '\0';
  while (a <= len+b)
    {
      msg[a] = 0;
      a++;
    }
  msg[a] = '\0';
  len2 = len + b;
  printf("\nEncrypted message :\n");
  int	c = 0;
  int	d = 0;
  int	f = 0;
  int	g = 0;
  int	res = 0;
  a = 0;
  b = 0;
  while (c <= len2)
    {
      f = b;
      while (g < column)
	{
	  res += (key[d]*message[b]);
	  b++;
	  d += column;
	  g++;
	}
      printf("%d ",res);
      c++;
      res = 0;
      if (a == (column - 1))
	a = 0;
      else
	a++;
      d = a;
      if (a == 0)
	{
	  b = f;
	  b += column;
	}
      else
	b = f;
      g = 0;
    }
  printf("\n");
}

void	my_102cipher(char *msg, char *keymsg)
{
  int	a;
  int	b;
  int	len;
  len = sqrt(my_strlen(keymsg));
  int	key[(len + 1) * (len + 1)];

  msg = msg;
  a = 0;
  my_putstr("Key matrix :\n");
  while (keymsg[a] != '\0')
    {
      key[a] = (int)keymsg[a];
      a++;
    }
  while (a != ((len + 1)*(len + 1)))
    {
      key[a] = 0;
      a++;
    }
  key[a] = '\0';
  a = 0;
  b = 0;
  if ((len * len) >= my_strlen(keymsg))
    {
      while (a != (len * len))
	{
	  if (b == len)
	    {
	      printf("\n");
	      b = 0;
	    }
	  printf("%d	", key[a]);
	  a++;
	  b++;
	}
    }
  else
    {
      len += 1;
      while (a != (len * len))
	{
	  if (b == len)
	    {
	      printf("\n");
	      b = 0;
	    }
	  printf("%d	", key[a]);
	  a++;
	  b++;
	}
    }
  printf("\n");
  my_encryption(msg, key, len);
}

int	main(int argc, char **argv)
{
  if (argc != 4)
    return (84);
  else if (argv[1][0] == '\0')
    return (84);
  else if (argv[2][0] == '\0')
    return (84);
  else if (argv[3][0] == '0')
    my_102cipher(argv[1], argv[2]);
  else if (argv[3][0] == '1')
    printf("pas fait dsl");
  else
    return (84);
  return (0);
}
