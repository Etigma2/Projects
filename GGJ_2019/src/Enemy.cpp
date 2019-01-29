/*
** EPITECH  PROJECT , 2017
** Enemy
** File  description:
** 	Class functions for class Enemy
*/

#include	"Enemy.hpp"

Enemy::Enemy() : Entity(), _weapon(NULL)
{
	sf::CircleShape *shape = new sf::CircleShape(30.f);
	shape->setFillColor(sf::Color::Blue);
	this->_entityShape = shape;
	Weapon	*weapon = new Weapon();
	this->_weapon = weapon;
	std::cout << "Created an Enemy with " << this->_hp << " HP, "
	<< this->_armor << " Armor, " << this->_speed << " Speed." << '\n';
}

Enemy::Enemy(int hp, int armor, int speed) : Entity(hp, armor, speed), _weapon(NULL)
{
	sf::CircleShape *shape = new sf::CircleShape(30.f);
	shape->setFillColor(sf::Color::Blue);
	this->_entityShape = shape;
	Weapon	*weapon = new Weapon();
	this->_weapon = weapon;
	std::cout << "Created an Enemy with " << this->_hp << " HP, "
	<< this->_armor << " Armor, " << this->_speed << " Speed." << '\n';
}

Enemy::~Enemy()
{
	delete this->_entityShape;
	delete this->_weapon;
	std::cout << "Destroyed Enemy" << '\n';
}

sf::Vector2f	Enemy::getNextMovement(sf::Vector2f playerMom)
{
	// IA A DEV
	return (sf::Vector2f(0.f, 0.f));
}
