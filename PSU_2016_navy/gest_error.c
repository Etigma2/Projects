/*
** gest_error.c for navy in /home/magellan/PSU/PSU_2016_navy
** 
** Made by Magellan
** Login   <magellan@epitech.eu>
** 
** Started on  Fri Feb 17 16:34:28 2017 Magellan
** Last update Sat Feb 18 21:24:17 2017 Magellan
*/

#include <navy.h>

int	my_strlen(char *);

int	check_buff(char *buff)
{
	char	**file;
	int	i;

	i = 1;
	if (my_strlen(buff) < 31 || my_strlen(buff) > 33)
    	return (1);
	file = my_str_to_wordtab(buff);
	while (++i < 6)
	{
    	if (file[i - 2][0] != i + '0' || file[i - 2][1] != ':' ||
    	    file[i - 2][4] != ':' ||
    	    (file[i - 2][2] < 'A' || file[i - 2][2] > 'H')
    	    || (file[i - 2][3] < '1' || file[i - 2][3] > '8') ||
    	    (file[i - 2][5] < 'A' || file[i - 2][5] > 'H')
    	    || (file[i - 2][6] < '1' || file[i - 2][6] > '8'))
        	return (1);
       if ((file[i - 2][0] - '0' - 1 != (file[i - 2][2] - file[i - 2][5]
                                    + file[i - 2][3] - file[i - 2][6]))&&
           (file[i - 2][0] - '0' - 1 != -(file[i - 2][2] - file[i - 2][5]
                                    + file[i - 2][3] - file[i - 2][6])))
       		return (1);
	}
	return (0);
}
