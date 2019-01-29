##
## PERSONAL PROJECT, 2018
## GGJ_2019
## File description:
## 	Makefile of the GGJ_2019 project
##

SRC	=	src/main.cpp	\
		src/GameHandler.cpp	\
		src/map.cpp	\
		src/Entity.cpp	\
		src/Player.cpp	\
		src/Enemy.cpp	\
		src/Weapon.cpp	\
		src/Bullet.cpp

OBJ = $(SRC:.cpp=.o)

CXXFLAGS = -Iinclude -W -Wall -Wextra -g -std=c++17

NAME = TA-426

SFMLFLAGS = -lsfml-graphics -lsfml-window -lsfml-system

$(NAME): $(OBJ)
	g++ -o $(NAME) $(CXXFLAGS) $(OBJ) $(SFMLFLAGS)

all:    $(NAME)

clean:
	rm -f $(OBJ)

fclean:    clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
