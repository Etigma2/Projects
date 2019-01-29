/*
** PERSONAL PROJECT, 2018
** GGJ_2019
** File description:
** 	main file of the GGJ_2019 project
*/

#include	<SFML/Graphics.hpp>
#include	"GameHandler.hpp"

int main()
{
	sf::RenderWindow window;
	GameHandler gameHandler(window);

	gameHandler.start();
	return (0);
}
