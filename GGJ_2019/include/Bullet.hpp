/*
** EPITECH  PROJECT , 2017
** Bullet
** File  description:
** 	Class declarations for class Bullet
*/

#ifndef BULLET_HPP_
# define BULLET_HPP_

#include	"Entity.hpp"

class Bullet : public Entity
{

public :

	// Constructor
	Bullet();
	Bullet(int damage, int pierce, int shouldBounce);

	// Destructor
	~Bullet();

	// Members Functions

	// Setters
	void	setDamage(int damage);
	void	setPierce(int pierce);
	void	setShouldBouce(bool shouldBounce);

	// Getters
	int	getDamage();
	int	getPierce();
	bool	getShouldBounce();


private :

	int	_damage;
	int	_pierce;
	bool	_shouldBounce;

};

#endif /* BULLET_HPP_ */
