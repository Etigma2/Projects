/*
** my_play.c for my_play.c in /home/Paul.Juyaux/Projet/EN_COUR/PSU_2016_navy/Re_Navy
** 
** Made by Paul Juyaux
** Login   <Paul.Juyaux@epitech.net>
** 
** Started on  Fri Feb 10 15:14:43 2017 Paul Juyaux
** Last update Sun Feb 19 15:29:24 2017 Magellan
*/

#include <navy.h>

int	received_attack(t_info player)
{
  int	i;
  int	pow;
  int	nb;

  nb = 0;
  i = 0;
  pow = 32;
  while (i < 7)
    {
      pause();
      if (g_byte == 1)
	nb = nb + pow;
      pow = pow / 2;
      i = i + 1;
    }
  return (nb);
}

t_info	my_defend(t_info player)
{
  int	nb;

  my_putstr("waiting for enemy's attack...\n");
  nb = received_attack(player);
  usleep(100000);
  my_putchar(nb / 8 + 65);
  my_putchar(nb % 8 + 49);
  if (player.my_map[nb % 8][nb / 8] < 57 && player.my_map[nb % 8][nb / 8] > 48)
    {
      my_putstr(": hit\n\n");
      player.my_map[nb % 8][nb / 8] = 'x';
      kill(player.enemy_pid, 12);
    }
  else
    {
      my_putstr(": missed\n\n");
      player.my_map[nb % 8][nb / 8] = 'o';
      kill(player.enemy_pid, 10);
    }
  return (player);
}

int	my_send_attack(t_info player, int to_send)
{
  int	i;
  int	pow;

  i = 0;
  pow = 32;
  while (i < 7)
    {
      if (pow <= to_send)
	{
	  kill(player.enemy_pid, 12);
	  to_send = to_send - pow;
	}
      else
	{
	  kill(player.enemy_pid, 10);
	}
      pow = pow / 2;
      usleep(1000);
      i = i + 1;
    }
  pause();
  return (g_byte);
}

t_info	my_attack(t_info player)
{
  char	*buf;

  my_putstr("attack: ");
  buf = malloc(sizeof(char) * 128);
  read(0, buf, 128);
  if  ((buf[0] < 65 || buf[0] > 72) || (buf[1] < 49 || buf[1] > 56))
    {
      my_putstr("wrong position\n");
      return (my_attack(player));
    }
  if (my_send_attack(player, my_convert(buf)) == 1)
    {
      my_putchar(buf[0]);
      my_putchar(buf[1]);
      my_putstr(": hit\n\n");
      player.enemy_map[buf[1] - 49][buf[0] - 65] = 'x';
    }
  else
    {
      my_putchar(buf[0]);
      my_putchar(buf[1]);
      my_putstr(": missed\n\n");
      player.enemy_map[buf[1] - 49][buf[0] - 65] = 'o';
    }
  return (player);
}

int	my_play(t_info player, int i)
{
  g_byte = 0;
  while (check_end(player) != 1)
    {
      if (i++ == 0)
	{
	  my_putstr("my positions:\n");
	  aff_map(player.my_map);
	  my_putstr("\n\nenemy's positions:\n");
	  aff_map(player.enemy_map);
	  my_putchar('\n');
	}
      else
	i = 0;
      if (player.turn == 1)
	{
	  player = my_attack(player);
	  player.turn = 0;
	}
      else if (player.turn == 0)
	{
	  player = my_defend(player);
	  player.turn = 1;
	}
    }
  return (my_show_end(player));
}
