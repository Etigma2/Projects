/*
** EPITECH  PROJECT , 2017
** Player
** File  description:
** 	Class functions for class Player
*/

#include	"Player.hpp"

Player::Player() : Entity(3, 0, 1), _weapon(NULL)
{
	sf::CircleShape	*shape = new sf::CircleShape(20.f);
	shape->setFillColor(this->_color);
	shape->setPosition(600.f, 400.f);
	this->_entityShape = shape;
	Weapon	*weapon = new Weapon();
	this->_weapon = weapon;
	std::cout << "Created Player" << '\n';
}

Player::~Player()
{
	delete this->_entityShape;
	delete this->_weapon;
	std::cout << "Destroyed Player" << '\n';
}

void	Player::getMovement(sf::RenderWindow& window, std::vector<Bullet*> &bulletPos)
{
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
		sf::Vector2i mousePos = sf::Mouse::getPosition(window);
		std::cout << "Clicked Left in position ["
		<< mousePos.x << ";" << mousePos.y << "]" << '\n';
		this->_weapon->fire(this->calculVector(sf::Vector2f(mousePos.x, mousePos.y), this->_weapon->getBulletSpeed()), sf::Vector2f(this->getShape()->getPosition().x + 10, this->getShape()->getPosition().y + 10), bulletPos);
	}
}

void	Player::setWeapon(Weapon *weapon)
{
	this->_weapon = weapon;
}

Weapon	*Player::getWeapon()
{
	return this->_weapon;
}
