/*
** EPITECH  PROJECT , 2017
** Entity
** File  description:
** 	Class declarations for class Entity
*/

#ifndef ENTITY_HPP_
# define ENTITY_HPP_

#include	<SFML/Graphics.hpp>
#include	<iostream>
#include	<cmath>

class Entity
{

public :

	// Constructor
	Entity();
	Entity(int hp, int armor, int speed);

	// Destructor
	~Entity();

	// Members Functions

	// Movements

	// Setters
	void	setHp(int hp);
	void	setArmor(int armor);
	void	setSpeed(int speed);
	void	setShouldBeDeleted(bool deleted);

	void	setShape(sf::CircleShape *shape);
	void	setColor(sf::Color color);
	void	setMomentum(sf::Vector2f momentum);
	void	addToMomentum(sf::Vector2f addedMom);

	// Getters
	int	getHp();
	int	getArmor();
	int	getSpeed();
	bool	getShouldBeDeleted();

	sf::CircleShape	*getShape();
	sf::Color	getColor();
	sf::Vector2f	getMomentum();


	// Calcul of the Vector to Fire
	sf::Vector2f	calculVector(sf::Vector2f mousePos, float speed);


protected :

	// Statistics
	int	_hp;
	int	_armor;
	int	_speed;

	// SFML Handle and Movement
	sf::CircleShape	*_entityShape;
	sf::Color	_color;
	sf::Vector2f	_momentum;
	bool	_shouldBeDeleted;
};

#endif /* ENTITY_HPP_ */
