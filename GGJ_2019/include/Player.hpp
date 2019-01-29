/*
** EPITECH  PROJECT , 2017
** Player
** File  description:
** 	Class declarations for class Player
*/

#ifndef PLAYER_HPP_
# define PLAYER_HPP_

#include	"Entity.hpp"
#include	"Weapon.hpp"

class Player : public Entity
{

public :

	// Constructor
	Player();

	// Destructor
	~Player();

	// Members Functions
	void	getMovement(sf::RenderWindow& window, std::vector<Bullet*> &bulletPos);

	// Setters
	void	setWeapon(Weapon *weapon);

	// Getters
	Weapon	*getWeapon();

private :

	Weapon	*_weapon;

};

#endif /* PLAYER_HPP_ */
