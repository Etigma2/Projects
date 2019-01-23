/*
** navy.h for PSU_2016_navy in /home/magellan/PSU/PSU_2016_navy/include
** 
** Made by Magellan
** Login   <magellan@epitech.eu>
** 
** Started on  Wed Feb  1 18:36:09 2017 Magellan
** Last update Fri Feb 17 16:37:31 2017 Magellan
*/

#ifndef NAVY_H_
# define NAVY_H_

#include <unistd.h>
#include <signal.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>

int	g_byte;

typedef	struct	s_info
{
  int	turn;
  int	enemy_pid;
  char	**my_map;
  char	**enemy_map;
}		t_info;

int	main(int, char**);
char	**my_str_to_wordtab(char *);
int	check_buff(char *);
char	**my_reset(char**, int, int);
char	**gest_map(int);
char	**my_fill(char**, int, int, int);
int	print_help(void);
int	my_play(t_info, int);
void	aff_map(char**);
int	my_send_attack(t_info, int);
t_info	my_attack(t_info);
t_info	my_defend(t_info);
int	received_attack(t_info);
void	my_putstr(char*);
int	my_toint(char*);
void	my_putchar(char);
int	check_end(t_info);
int	my_show_end(t_info);
void	my_put_nbr(int);
char	**my_empty_map();
int	check_enemy(char**);
int	check_my(char**);
int	my_convert(char *);
int	my_strncmp(char *, char *, int);
void	start_sigaction();
void	aff_player2(t_info);

#endif
