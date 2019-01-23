/*
** my_strncmp.c for emacs in /home/magellan.chaux/CPool_Day06
** 
** Made by Magellan chaux-limantour
** Login   <magellan.chaux@epitech.net>
** 
** Started on  Mon Oct 10 09:32:52 2016 Magellan chaux-limantour
** Last update Mon Oct 10 09:44:07 2016 Magellan chaux-limantour
*/

int	my_strncmp(char *s1, char *s2, int n)
{
  int	i;

  i = 0;
  while (s1[i] == s2[i] && s1[i] && s2[i] && i < n)
    i = i + 1;
  if (s1[i] == s2[i])
    return (0);
  return (s1[i] - s2[i]);
}
