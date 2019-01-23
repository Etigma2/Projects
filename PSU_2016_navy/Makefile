##
## Makefile for navy in /home/magellan/PSU/PSU_2016_navy
## 
## Made by Magellan
## Login   <magellan@epitech.eu>
## 
## Started on  Wed Feb  1 18:30:21 2017 Magellan
## Last update Fri Feb 17 16:37:07 2017 Magellan
##

SRC	=	main.c	\
			aff.c	\
			gest_error.c	\
			load_map.c	\
			my_end.c	\
			my_play.c	\
			lib/my_str_to_wordtab.c	\
			lib/my_strncmp.c

NAME	=	navy

all:	$(NAME)

$(NAME):
	gcc -Iinclude -o $(NAME) $(SRC)

clean:
	rm -f

fclean:	clean
	rm -f $(NAME)

re:	fclean	all

.PHONY:	all	clean	fclean	re
