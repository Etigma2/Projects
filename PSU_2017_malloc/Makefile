##
## EPITECH PROJECT, 2018
## 
## File description:
## 
##

NAME = libmy_malloc.so

LNAME = libmy_malloc.so

SRCS =	main.c	\
	malloc.c

OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME):	$(OBJS)
		gcc -ggdb3 -W -Wall -Wextra -fPIC -lpthread -c  $(SRCS)
		gcc -ggdb3 -shared -o $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	rm -f $(NAME)
	rm -f $(LNAME)

re:	fclean all

.PHONY : all clean fclean re
