/*
** load_map.c for gest_map.c in /home/Paul.Juyaux/Projet/EN_COUR/PSU_2016_navy/Jfait_Des_Tests
** 
** Made by Paul Juyaux
** Login   <Paul.Juyaux@epitech.net>
** 
** Started on  Tue Jan 31 14:25:52 2017 Paul Juyaux
** Last update Sat Feb 18 12:19:53 2017 Magellan
*/

#include <navy.h>

void	my_show_wordtab(char **tab)
{
  int	i;

  i = 0;
  while (tab[i] != '\0')
    {
      my_putstr(tab[i]);
      my_putchar('\n');
      i = i + 1;
    }
}

char	**my_empty_map()
{
  int	i;
  int	n;
  char	**my_map;

  i = 0;
  n = 0;
  my_map = malloc(sizeof(char*) * 9);
  while (i < 8)
    {
      my_map[i] = malloc(sizeof(char) * 9);
      while (n < 8)
	{
	  my_map[i][n] = '.';
	  n = n + 1;
	}
      n = 0;
      i = i + 1;
    }
  my_map[8] = '\0';
  return (my_map);
}

char	**my_fill(char **my_map, int x, int y, int i)
{
  while (x != y)
    {
      my_map[x / 8 - 1][x % 8] = i + 48;
      if (x % 8 > y % 8)
	x = x - 1;
      else if (x % 8 < y % 8)
	x = x + 1;
      else if (x / 8 < y / 8)
	x = x + 8;
      else if (x / 8 > y / 8)
	x = x - 8;
    }
  my_map[x / 8 - 1][x % 8] = i + 48;
  if (x % 8 > y % 8)
    x = x - 1;
  else if (x % 8 < y % 8)
    x = x + 1;
  else if (x / 8 < y / 8)
    x = x + 8;
  else if (x / 8 > y / 8)
    x = x - 8;
  return (my_map);
}

char    **my_reset(char **my_map, int i, int n)
{
  while (i--)
    {
      my_map[i] = malloc(sizeof(char) * 8);
      while (n--)
	my_map[i][n] = '.';
      n = 8;
    }
  return (my_map);
}

char	**gest_map(int fd)
{
	char	**my_map;
  char	*buff;
  int	x;
  int	y;
  int	i;

  my_map = malloc(sizeof(char*) * 8);
  buff = malloc(sizeof(char) * 50);
  my_map = my_reset(my_map, 8, 8);
  i = 0;
  read(fd, buff, 49);
  if (check_buff(buff) == 1)
  {
      g_byte = 84;
      return (my_map);
  }
  while (i < 4)
    {
      x = (buff[2 + i * 8] - 65) + (buff[3 + i * 8] - 48) * 8;
      y = (buff[5 + i * 8] - 65) + (buff[6 + i * 8] - 48) * 8;
      my_map = my_fill(my_map, x, y, i + 2);
      i = i + 1;
    }
  return (my_map);
}
