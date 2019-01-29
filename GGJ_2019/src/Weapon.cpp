/*
** EPITECH  PROJECT , 2017
** Weapon
** File  description:
** 	Class functions for class Weapon
*/

#include	"Weapon.hpp"

Weapon::Weapon() : _bulletSpeed(4), _fireRate(1), _reload(0), _bullet(NULL)
{
	Bullet	*bullet = new Bullet();
	this->_bullet = bullet;
	std::cout << "Created Weapon" << '\n';
}

Weapon::Weapon(float spd, int frate, int rload) : _bulletSpeed(spd), _fireRate(frate), _reload(rload), _bullet(NULL)
{
	Bullet	*bullet = new Bullet();
	this->_bullet = bullet;
}

Weapon::~Weapon()
{
	delete this->_bullet;
	std::cout << "Destroyed Weapon" << '\n';
}

float	Weapon::getBulletSpeed()
{
	return this->_bulletSpeed;
}

int	Weapon::getFireRate()
{
	return this->_fireRate;
}

int	Weapon::getReload()
{
	return this->_reload;
}

void	Weapon::setBulletSpeed(float bulSpd)
{
	this->_bulletSpeed = bulSpd;
}

void	Weapon::setFireRate(int fireRate)
{
	this->_fireRate = fireRate;
}

void	Weapon::setReload(int reload)
{
	this->_reload = reload;
}

void	Weapon::fire(sf::Vector2f direction, sf::Vector2f position, std::vector<Bullet*> &bulletPos)
{
	if (this->_reload <= 0) {
		this->_reload = this->_fireRate;
		std::cout << "Pan" << std::endl;
		Bullet *bullet = new Bullet(_bullet->getDamage(), _bullet->getPierce(), _bullet->getShouldBounce());
		bullet->getShape()->setPosition(position);
		bullet->setMomentum(direction);
		bulletPos.push_back(bullet);
	}
}

void	Weapon::checkReload()
{
	if (this->_reload > 0)
		this->_reload--;
}
