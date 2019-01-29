/*
** EPITECH  PROJECT , 2017
** Entitie
** File  description:
** 	Class functions for class Entitie
*/

#include	"Entity.hpp"

Entity::Entity() : _hp(1), _armor(0), _speed(1), _entityShape(), _color(sf::Color(255, 255, 255)), _momentum(sf::Vector2f(0.f, 0.f)), _shouldBeDeleted(false)
{

}

Entity::Entity(int hp, int armor, int speed) : _hp(hp), _armor(armor), _speed(speed), _entityShape(), _color(sf::Color(255, 255, 255)), _momentum(sf::Vector2f(0.f, 0.f)), _shouldBeDeleted(false)
{

}

Entity::~Entity()
{
	std::cout << "Destroyed entity" << '\n';
}

void	Entity::setHp(int hp)
{
	this->_hp = hp;
}

int	Entity::getHp()
{
	return this->_hp;
}

void	Entity::setArmor(int armor)
{
	this->_armor = armor;
}

int	Entity::getArmor()
{
	return this->_armor;
}

void	Entity::setSpeed(int speed)
{
	this->_speed = speed;
}

int	Entity::getSpeed()
{
	return this->_speed;
}

void	Entity::setShape(sf::CircleShape *shape)
{
	this->_entityShape = shape;
}

sf::CircleShape	*Entity::getShape()
{
	return this->_entityShape;
}

void	Entity::setColor(sf::Color color)
{
	this->_color = color;
}

sf::Color	Entity::getColor()
{
	return this->_color;
}

void	Entity::setMomentum(sf::Vector2f momentum)
{
	this->_momentum = momentum;
}

void	Entity::addToMomentum(sf::Vector2f addedMom)
{
	this->_momentum.x = this->_momentum.x + addedMom.x;
	this->_momentum.y = this->_momentum.y + addedMom.y;
}

sf::Vector2f	Entity::getMomentum()
{
	return this->_momentum;
}

void	Entity::setShouldBeDeleted(bool deleted)
{
	this->_shouldBeDeleted = deleted;
}

bool	Entity::getShouldBeDeleted()
{
	return this->_shouldBeDeleted;
}

sf::Vector2f	Entity::calculVector(sf::Vector2f mousePos, float speed) {
	sf::Vector2f calculatedVector(0, 0);
	int dist;

	calculatedVector.x = this->getShape()->getPosition().x + this->getShape()->getRadius() - mousePos.x;
	calculatedVector.y = this->getShape()->getPosition().y + this->getShape()->getRadius() - mousePos.y;
	dist = std::sqrt(calculatedVector.x * calculatedVector.x + calculatedVector.y * calculatedVector.y);
	calculatedVector.x = -calculatedVector.x * (speed / dist);
	calculatedVector.y = -calculatedVector.y * (speed / dist);
	return calculatedVector;
}
