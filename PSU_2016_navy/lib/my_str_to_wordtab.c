/*
** my_str_to_wordtab.c for my_str_to_wordtab in /home/magellan.chaux/wireframe
** 
** Made by Magellan chaux-limantour
** Login   <magellan.chaux@epitech.net>
** 
** Started on  Wed Dec  7 21:33:30 2016 Magellan chaux-limantour
** Last update Fri Feb 17 16:49:06 2017 Magellan
*/

#include <stdlib.h>

int	my_strlen(char *str)
{
    int	res;

    res = -1;
    while (str[++res])
        ;
    return (res);
}

int	count_line(char *str)
{
  int	i;
  int	cpt;

  cpt = 0;
  i = -1;
  while (str[++i])
    if (str[i] == '\n')
      cpt++;
  return (cpt);
}

char	**fill_tab(char **tab, char *str)
{
  int	i;
  int	y;
  int	x;

  x = 0;
  i = -1;
  y = -1;
  while (str[++i])
    {
      if (str[i] == '\n')
	{
	  tab[x][y + 1] = '\0';
	  y = -1;
	  x++;
	}
      else
	tab[x][++y] = str[i];
    }
  tab[x + 1] = NULL;
  return (tab);
}

char	**my_str_to_wordtab(char *str)
{
  char	**res;
  int	i;

  i = -1;
  res = malloc(sizeof(char*) * (count_line(str) + 5));
  while (++i < count_line(str) + 5)
    res[i] = malloc(sizeof(char) * (my_strlen(str) + 5));
  fill_tab(res, str);
  return (res);
}
