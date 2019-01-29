/*
** EPITECH  PROJECT , 2017
** Bullet
** File  description:
** 	Class functions for class Bullet
*/

#include	"Bullet.hpp"

Bullet::Bullet() : Entity(), _damage(1), _pierce(0), _shouldBounce(false)
{
	sf::CircleShape *shape = new sf::CircleShape(5.f);
	shape->setFillColor(sf::Color::White);
	this->_entityShape = shape;
	std::cout << "Created an Bullet with " << this->_hp << " HP, "
	<< this->_armor << " Armor, " << this->_speed << " Speed."
	<< " He deal " << this->_damage << " damage and pierce " << this->_pierce
	<< " targets. The bullet can't bounce !" << '\n';
}

Bullet::Bullet(int damage, int pierce, int shouldBounce) : Entity(), _damage(damage), _pierce(pierce), _shouldBounce(shouldBounce)
{
	sf::CircleShape *shape = new sf::CircleShape(5.f);
	shape->setFillColor(sf::Color::White);
	this->_entityShape = shape;
	std::cout << "Created an Bullet with " << this->_hp << " HP, "
	<< this->_armor << " Armor, " << this->_speed << " Speed." <<
	" He deal " << this->_damage << " damage and pierce " << this->_pierce << " targets." << '\n';
	if (this->_shouldBounce)
		std::cout << "The bullet can bounce !" << '\n';
	else
		std::cout << "The bullet can't bounce !" << '\n';
}

Bullet::~Bullet()
{
	delete this->_entityShape;
	std::cout << "Destroyed Bullet" << '\n';
}

void	Bullet::setDamage(int damage)
{
	this->_damage = damage;
}

void	Bullet::setPierce(int pierce)
{
	this->_pierce = pierce;
}

void	Bullet::setShouldBouce(bool bounce)
{
	this->_shouldBounce = bounce;
}

int	Bullet::getDamage()
{
	return this->_damage;
}

int	Bullet::getPierce()
{
	return this->_pierce;
}

bool	Bullet::getShouldBounce()
{
	return this->_shouldBounce;
}
