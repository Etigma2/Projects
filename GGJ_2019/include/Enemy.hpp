/*
** EPITECH  PROJECT , 2017
** Enemy
** File  description:
** 	Class declarations for class Enemy
*/

#include	"Entity.hpp"
#include	"Weapon.hpp"

class Enemy : public Entity
{

public :

	// Constructor
	Enemy();
	Enemy(int hp, int armor, int speed);

	// Destructor
	~Enemy();

	// Members Functions
	sf::Vector2f	getNextMovement(sf::Vector2f playerMom);

private :

	Weapon	*_weapon;

};
