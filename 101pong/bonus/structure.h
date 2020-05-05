/*
** structure.h for structure in /home/leroy_0/rendu/101pong
**
** Made by leroy_0
** Login   <leroy_0@epitech.net>
**
** Started on  Thu Nov  5 16:30:36 2015 leroy_0
** Last update Sat Nov  7 16:03:59 2015 leroy_0
*/

#ifndef STRUCTURE_H_
# define STRUCTURE_H_

typedef struct		s_struct_data
{
  t_bunny_window        *win;
  t_bunny_music         *music;
  t_bunny_position      pos;
  t_bunny_position      pos2;
  t_bunny_position      pos3;
  t_bunny_position      pos4;
  t_bunny_position      pos5;
  t_bunny_position      pos4b;
  t_bunny_position      pos5b;
  t_bunny_position      pos6;
  t_bunny_position      pos7;
  unsigned int          vecteurx;
  unsigned int          vecteury;
  int		        limit1;
  int			limit2;
  t_bunny_position      limit1b;
  t_bunny_position	limit2b;

}			t_struct_data;

#endif /*!STRUCTURE_H_!*/
