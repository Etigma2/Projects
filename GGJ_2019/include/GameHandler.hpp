/*
** EPITECH  PROJECT , 2017
** GameHandler
** File  description:
** 	Class declarations for class GameHandler
*/

#ifndef GAMEHANDLER_HPP_
# define GAMEHANDLER_HPP_

#include	"map.hpp"
#include	"Player.hpp"
#include	"Weapon.hpp"
#include	"Enemy.hpp"
#include	<chrono>
#include	<unistd.h>

class GameHandler
{
public:

	// Constructors
	GameHandler(sf::RenderWindow &window);

	// Destructor
	~GameHandler();

	// Members Functions
	void	start();
	void	displayLoop(Player &player);
	void	eventHandle(Player &player);
	void	applyMovement(Player &player);
	sf::RenderWindow	&getWindow();
	bool	isOutOfBound(sf::Vector2f bulletPos);

	// Bullet Thingy
	void	drawBullet(sf::Vector2f playerMom);
	bool	isBulletEmpty();
	void	deleteBullet();
	std::vector<Bullet*>	&getBulletVector();

	// Enemy Thingy
	void	drawEnemy();
	bool	isEnemyEmpty();
	void	deleteEnemy();
	std::vector<Enemy*>	&getEnemyVector();


private:

	Map _map;
	sf::Vector2f _Cam;
	sf::Vector2f _AccCam;
	sf::Event _event;
	sf::RenderWindow &_window;

	std::vector<Bullet*>	_bulletPos;
	std::vector<Enemy*>	_enemyList;
};

#endif
