/*
** EPITECH  PROJECT , 2017
** Weapon
** File  description:
** 	Class declarations for class Weapon
*/

#ifndef WEAPON_HPP_
# define WEAPON_HPP_

#include	<iostream>
#include	<new>
#include	"Bullet.hpp"

class Weapon
{

public :

	// Constructor
	Weapon();
	Weapon(float spd, int frate, int rload);

	// Destructor
	~Weapon();

	// Getter
	float	getBulletSpeed();
	int	getFireRate();
	int	getReload();

	// Setters
	void	setBulletSpeed(float bulSpd);
	void	setFireRate(int fireRate);
	void	setReload(int reload);

	// Fire a Bullet (On click)
	void	fire(sf::Vector2f direction, sf::Vector2f position, std::vector<Bullet*> &bulletPos);
	void	checkReload();

private :

	float	_bulletSpeed;
	int	_fireRate;
	int	_reload;
	Bullet	*_bullet;

};

#endif /* WEAPON_HPP_ */
