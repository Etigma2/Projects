/*
** aff.c for aff.c in /home/Paul.Juyaux/Projet/EN_COUR/PSU_2016_navy/Re_Navy
** 
** Made by Paul Juyaux
** Login   <Paul.Juyaux@epitech.net>
** 
** Started on  Fri Feb 10 15:32:20 2017 Paul Juyaux
** Last update Mon Feb 13 11:10:51 2017 Paul Juyaux
*/

#include <navy.h>

void    my_putchar(char c)
{
  write(1, &c, 1);
}

void    my_putstr(char *str)
{
  int   i;

  i = 0;
  while (str[i++])
    my_putchar(str[i - 1]);
}

void	aff_map(char **my_map)
{
  int	i;
  int	n;

  i = 0;
  n = 0;
  my_putstr(" |A B C D E F G H\n-+---------------\n");
  while (my_map[i] != '\0')
    {
      my_putchar(i + 49);
      my_putchar('|');
      while (my_map[i][n] != '\0')
	{
	  my_putchar(my_map[i][n]);
	  my_putchar(' ');
	  n = n + 1;
	}
      my_putchar('\n');
      n = 0;
      i = i + 1;
    }
}

void	my_put_nbr(int	nb)
{
  if (nb < 10)
    {
      my_putchar(nb + 48);
    }
  else
    {
      my_put_nbr(nb / 10);
      my_putchar(nb % 10 + 48);
    }
}

int	my_toint(char *str)
{
  int	i;
  int	res;

  i = 0;
  res = 0;
  while (str[i] != '\0')
    {
      res = res * 10;
      res = res + str[i] - 48;
      i = i + 1;
    }
  return (res);
}
