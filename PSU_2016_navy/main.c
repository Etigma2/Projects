/*
** main.c for main.c in /home/Paul.Juyaux/Projet/EN_COUR/PSU_2016_navy/Re_Navy
** 
** Made by Paul Juyaux
** Login   <Paul.Juyaux@epitech.net>
** 
** Started on  Thu Feb  9 16:52:36 2017 Paul Juyaux
** Last update Sun Feb 19 21:13:27 2017 Paul Juyaux
*/

#include <navy.h>

void	use_signal(int sig, siginfo_t *info)
{
  if (g_byte == 42)
    g_byte = info->si_pid;
  else
    {
      if (sig == 10)
	g_byte = 0;
      else if (sig == 12)
	g_byte = 1;
    }
}

int     print_help()
{
  my_putstr("USAGE\n\t./navy [first_player_pid] navy_positions\n\nDESCR\
I");
  my_putstr("PTION\n\tfirst_player_pid\tonly for the 2nd player. pid \
");
  my_putstr("of the first player.\n\tnavy_positions\t\tfile represent");
  my_putstr("ing the positions of the ships.\n");
  return (0);
}

void	start_sigaction()
{
  sigset_t    sig_proc;
  struct sigaction action;

  sigemptyset(&sig_proc);
  action.sa_mask = sig_proc;
  action.sa_flags = SA_SIGINFO;
  action.sa_handler = (void *)use_signal;
  sigaction(10, &action, 0);
  sigaction(12, &action, 0);
  g_byte = 42;
  my_putstr("my_pid: ");
  my_put_nbr(getpid());
  my_putchar('\n');
}

int	connect_player(int pl, char **av)
{
	int enemy_pid;

  if (pl == 1)
    {
      my_putstr("waiting for enemy connexion...\n");
      pause();
      enemy_pid = g_byte;
      usleep(100);
      kill(enemy_pid, 10);
      my_putstr("enemy connected\n\n");
    }
  else
    {
      enemy_pid = my_toint(av[1]);
      kill(enemy_pid, 10);
      g_byte = 84;
      usleep(1000);
    }
    return (enemy_pid);
}

int	main(int ac, char **av)
{
  t_info	player;

  if (ac < 2 || ac > 3)
    return (84);
  if (my_strncmp(av[1], "-h", 1) == 0)
    return (print_help());
  start_sigaction();
  player.my_map = gest_map(open(av[ac - 1], O_RDONLY));
  player.turn = (ac - 1) % 2;
  if (g_byte == 84)
    return (84);
  player.enemy_map = my_empty_map();
  player.enemy_pid = connect_player(player.turn, av);
  if (g_byte == 84 && player.turn == 0)
    {
      my_putstr("Wrong Pid, try again");
      return (84);
    }
  else
    my_putstr("succesfully connected\n\n");
  return (my_play(player, 0));
}
