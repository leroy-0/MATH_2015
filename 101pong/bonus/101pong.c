/*
** 101pong.c for 101pong in /home/leroy_0/rendu/101pong
**
** Made by leroy_0
** Login   <leroy_0@epitech.net>
**
** Started on  Wed Nov  4 22:09:57 2015 leroy_0
** Last update Sat Nov  7 17:11:51 2015 leroy_0
*/

#include                <lapin.h>
#include		<stdio.h>
#include		"structure.h"

t_bunny_response	keyhook(t_bunny_event_state state,
				t_bunny_keysym key, t_struct_data *data)
{
  if (key == 25 && state == 0)
    {
      data->pos4.y += -6;
      data->limit1 += -6;
      data->pos4b.y += -6;
      data->limit1b.y += -6;
    }
  if (key == 18 && state == 0)
    {
      data->pos4.y += 6;
      data->limit1 += 6;
      data->pos4b.y += 6;
      data->limit1b.y += 6;
    }
  if (key == 73 && state == 0)
    {
      data->pos5.y += -6;
      data->limit2 += -6;
      data->pos5b.y += -6;
      data->limit2b.y += -6;
    }
  if (key == 74 && state == 0)
    {
      data->pos5.y += 6;
      data->limit2 += 6;
      data->pos5b.y += 6;
      data->limit2b.y += 6;
      }
  if (key == 36)
    return (EXIT_ON_SUCCESS);
  return (GO_ON);
}

t_bunny_response	mainloop(t_struct_data *data)
{
  data->pos6.x = 26;
  data->pos6.y = 0;
  data->pos7.x = 776;
  data->pos7.y = 0;
  data->pos3.x = 400;
  data->pos3.y = 0;
  while (data->pos3.y < 800)
    {
      bunny_set_pixel(&data->win->buffer, data->pos3, WHITE);
      data->pos3.y++;
    }
  while (data->pos4.y < data->limit1)
    {
      bunny_set_pixel(&data->win->buffer, data->pos4, WHITE);
      data->pos4.y++;
    }
  data->pos4.y += -50;
  while (data->pos5.y < data->limit2)
    {
      bunny_set_pixel(&data->win->buffer, data->pos5, WHITE);
      data->pos5.y++;
    }
  data->pos5.y += -50;
  bunny_set_pixel(&data->win->buffer, data->limit1b, BLACK);
  bunny_set_pixel(&data->win->buffer, data->pos4b, BLACK);
  bunny_set_pixel(&data->win->buffer, data->limit2b, BLACK);
  bunny_set_pixel(&data->win->buffer, data->pos5b, BLACK);
  if ((data->pos2.y <= data->limit1) && (data->pos2.y >= data->pos4.y)
      && (data->pos2.x == data->pos4.x))
    {
      bunny_set_pixel(&data->win->buffer, data->pos, BLACK);
      data->vecteurx = 2;
      data->pos2.x = data->pos2.x + data->vecteurx;
      data->pos.x = data->pos.x - data->vecteurx;
    }
  else if ((data->pos2.y <= data->limit2) && (data->pos2.y >= data->pos5.y)
      && (data->pos2.x == data->pos5.x))
    {
      bunny_set_pixel(&data->win->buffer, data->pos, BLACK);
      data->vecteurx = -2;
      data->pos2.x = data->pos2.x + data->vecteurx;
      data->pos.x = data->pos.x - data->vecteurx;
    }
  else if (data->pos2.x < 800 && data->pos2.y < 600 && data->pos2.x > 0
      && data->pos2.y > 0)
    {
      bunny_set_pixel(&data->win->buffer, data->pos2, WHITE);
      bunny_set_pixel(&data->win->buffer, data->pos, BLACK);
      data->pos2.y = data->pos2.y + data->vecteury;
      data->pos2.x = data->pos2.x + data->vecteurx;
      data->pos.y = data->pos.y + data->vecteury;
      data->pos.x = data->pos.x + data->vecteurx;
    }
  else if (data->pos2.y >= 600)
    {
      bunny_set_pixel(&data->win->buffer, data->pos, BLACK);
      data->vecteury = -2;
      data->pos2.y = data->pos2.y + data->vecteury;
      data->pos.y = data->pos.y - data->vecteury;
    }
  else if (data->pos2.y <= 0)
    {
      bunny_set_pixel(&data->win->buffer, data->pos, BLACK);
      data->vecteury = 2;
      data->pos2.y = data->pos2.y + data->vecteury;
      data->pos.y = data->pos.y - data->vecteury;
    }
  else if (data->pos2.x >= 800)
    {
      bunny_set_pixel(&data->win->buffer, data->pos, BLACK);
      return (EXIT_ON_SUCCESS);
    }
  else if (data->pos2.x <= 0)
    {
      bunny_set_pixel(&data->win->buffer, data->pos, BLACK);
      return (EXIT_ON_SUCCESS);
    }
  while (data->pos6.y < data->pos4.y)
    {
      bunny_set_pixel(&data->win->buffer, data->pos6, BLACK);
      data->pos6.y++;
    }
  data->pos6.y = data->limit1;
  while (data->pos6.y < 800)
    {
      bunny_set_pixel(&data->win->buffer, data->pos6, BLACK);
      data->pos6.y++;
    }
  while (data->pos7.y < data->pos5.y)
    {
      bunny_set_pixel(&data->win->buffer, data->pos7, BLACK);
      data->pos7.y++;
    }
  data->pos7.y = data->limit2;
  while (data->pos7.y < 800)
    {
      bunny_set_pixel(&data->win->buffer, data->pos7, BLACK);
      data->pos7.y++;
    }
  bunny_set_key_response(&keyhook);
  bunny_display(data->win);
  return (GO_ON);
}

int                     main(int argc, char **argv)
{
  t_struct_data		data;
  t_bunny_music         *music;

  if (argv[1] == NULL)
    {
      printf("Usage: ./101pong pongmusic.ogg\n");
      return (0);
    }
  argc = argc;
  data.vecteurx = 2;
  data.vecteury = 2;
  data.pos.x = 448;
  data.pos.y = 298;
  data.pos2.x = 450;
  data.pos2.y = 300;
  data.limit1 = 300;
  data.pos4.x = 26;
  data.pos4.y = 250;
  data.limit2 = 300;
  data.pos5.x = 776;
  data.pos5.y = 250;
  data.limit1b.x = 26;
  data.limit1b.y = 248;
  data.pos4b.x = 26;
  data.pos4b.y = 298;
  data.limit2b.x = 776;
  data.limit2b.y = 248;
  data.pos5b.x = 776;
  data.pos5b.y = 298;
  data.pos6.x = 26;
  data.pos6.y = 0;
  music = bunny_load_music(argv[1]);
  bunny_sound_volume(music, 60);
  bunny_sound_play(music);
  data.win = bunny_start(800, 600, false, "101pong");
  bunny_set_loop_main_function(&mainloop);
  bunny_loop(data.win, 150, &data);
  return (0);
}
