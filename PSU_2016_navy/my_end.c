/*
** my_end.c for my_end.c in /home/Paul.Juyaux/Projet/EN_COUR/PSU_2016_navy/Re_Navy
** 
** Made by Paul Juyaux
** Login   <Paul.Juyaux@epitech.net>
** 
** Started on  Mon Feb 13 09:49:56 2017 Paul Juyaux
** Last update Fri Feb 17 15:38:26 2017 Magellan
*/

#include <navy.h>

int	my_convert(char	*buf)
{
  int	nb;

  nb = 0;
  nb = nb + (buf[1] - 49);
  nb = nb + (buf[0] - 65) * 8;
  return (nb);
}

int	my_show_end(t_info player)
{
  if (check_enemy(player.enemy_map) == 1 && check_my(player.my_map) == 1)
    {
      my_putstr("Egality\n");
      return (0);
    }
  if (check_enemy(player.enemy_map) != 1 && check_my(player.my_map) == 1)
    {
      my_putstr("Enemy won\n");
      return (0);
    }
  if (check_enemy(player.enemy_map) == 1 && check_my(player.my_map) != 1)
    {
      my_putstr("I won\n");
      return (1);
    }
}

int	check_enemy(char **my_map)
{
  int	i;
  int	n;
  int	cunt;

  cunt = 0;
  i = 0;
  n = 0;
  while (my_map[i] != '\0')
    {
      while (my_map[i][n] != '\0')
	{
	  if (my_map[i][n] == 'x')
	    cunt = cunt + 1;
	  n = n + 1;
	}
      n = 0;
      i = i + 1;
    }
  if (cunt == 14)
    return (1);
  return (0);
}

int	check_my(char **my_map)
{
  int	i;
  int	n;

  i = 0;
  n = 0;
  while (my_map[i] != '\0')
    {
      while (my_map[i][n] != '\0')
	{
	  if (my_map[i][n] > 48 && my_map[i][n] < 57)
	    return (0);
	  n = n + 1;
	}
      n = 0;
      i = i + 1;
    }
  return (1);
}

int	check_end(t_info player)
{
  if (check_enemy(player.enemy_map) == 1
      || check_my(player.my_map) == 1)
    {
      return (1);
    }
  return (0);
}
