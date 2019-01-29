/*
** EPITECH  PROJECT , 2017
** GameHandler
** File  description:
** 	Class functions for class GameHandler
*/

#include "GameHandler.hpp"

GameHandler::GameHandler(sf::RenderWindow &window) : _Cam(0, 0), _AccCam(0, 0), _window(window)
{
	this->_window.create(sf::VideoMode(1200, 800), "TA-426");
	std::cout << "Created GameHandler" << '\n';
}

GameHandler::~GameHandler()
{
	std::cout << "Destroyed GameHandler" << '\n';
}

bool	GameHandler::isBulletEmpty()
{
	return this->_bulletPos.empty();
}

bool	GameHandler::isOutOfBound(sf::Vector2f bulletPos)
{
	if ((bulletPos.x > 1500) | (bulletPos.x < -20))
		return true;
	if ((bulletPos.y > 1500) | (bulletPos.y < -20))
		return true;
	return false;
}

void	GameHandler::drawBullet(sf::Vector2f playerMom)
{
	if (this->isBulletEmpty()) {
		std::cout << "No bullet to draw" << '\n';
		return ;
	}
	for (std::vector<Bullet*>::iterator it = this->_bulletPos.begin(); it != this->_bulletPos.end(); it++) {
		sf::Vector2f	realMom((*it)->getMomentum().x + playerMom.x, (*it)->getMomentum().y + playerMom.y);
		(*it)->getShape()->move(realMom);
		if (this->_map.checkValid((*it)->getShape()->getPosition(), sf::Vector2f((*it)->getShape()->getRadius(), (*it)->getShape()->getRadius()), this->_Cam) == false) {
			if ((*it)->getShouldBounce() == false) {
				(*it)->setShouldBeDeleted(true);
			}
		}

		this->_window.draw((*(*it)->getShape()));

		//std::cout << (*it)->getShape()->getPosition().x << ";" << (*it)->getShape()->getPosition().y << '\n';
		if (this->isOutOfBound((*(*it)->getShape()).getPosition())) {
			(*it)->setShouldBeDeleted(true);
		}
	}
}

void	GameHandler::deleteBullet()
{
	if (this->isBulletEmpty()) {
		//std::cout << "No bullets to delete" << '\n';
		return ;
	}
	for (unsigned int i = 0; i < this->_bulletPos.size(); i++) {
		if (this->_bulletPos[i]->getShouldBeDeleted()) {
			delete this->_bulletPos[i];
			this->_bulletPos.erase(this->_bulletPos.begin() + i);
			i--;
		}
	}
}

std::vector<Bullet*>	&GameHandler::getBulletVector()
{
	return this->_bulletPos;
}

bool	GameHandler::isEnemyEmpty()
{
	return this->_enemyList.empty();
}

void	GameHandler::drawEnemy()
{
	if (this->isEnemyEmpty()) {
		std::cout << "No enemy to draw" << '\n';
		return ;
	}
	for (std::vector<Enemy*>::iterator it = this->_enemyList.begin(); it != this->_enemyList.end(); it++) {
		this->_window.draw((*(*it)->getShape()));
		//(*it)->aiEnemy();
		/*if ((*it)->getShape()->getPosition().x < -50) {
			(*it)->setDeleted(true);
		}*/
	}
}

void	GameHandler::deleteEnemy()
{
	if (this->isEnemyEmpty()) {
		//std::cout << "No enemy to delete" << '\n';
		return ;
	}
	for (unsigned int i = 0; i < this->_enemyList.size(); i++) {
		if ((this->_enemyList[i])->getShouldBeDeleted()) {
			delete this->_enemyList[i];
			this->_enemyList.erase(this->_enemyList.begin() + i);
			i--;
		}
	}
}

std::vector<Enemy*>	&GameHandler::getEnemyVector()
{
	return this->_enemyList;
}

void	GameHandler::applyMovement(Player &player)
{
	this->drawBullet(player.getMomentum()); // Bullet Move + Draw
	//this->drawEnemy(); // Enemy Move + Draw
	// Player Move
}

void GameHandler::eventHandle(Player &player)
{
	player.getMovement(this->_window, this->getBulletVector());
	player.getWeapon()->checkReload();
	player.setMomentum(sf::Vector2f(0.f, 0.f));
	while (this->_window.pollEvent(this->_event)) {
		if (this->_event.type == sf::Event::Closed) {
			this->_window.close();
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) {
		this->_Cam.x += 10;
		player.addToMomentum(sf::Vector2f(10.f, 0.f));
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		this->_Cam.x -= 10;
		player.addToMomentum(sf::Vector2f(-10.f, 0.f));
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
		this->_Cam.y -= 10;
		player.addToMomentum(sf::Vector2f(0, -10.f));
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z)) {
		this->_Cam.y += 10;
		player.addToMomentum(sf::Vector2f(0.f, 10.f));
	}
}

void	GameHandler::displayLoop(Player &player)
{
	this->_window.clear(sf::Color::Black);
	this->_map.drawMap(this->getWindow(), this->_Cam);
	this->_window.draw((*player.getShape()));
	this->applyMovement(player);
	this->_window.display();
}

void	GameHandler::start()
{
	Player	player;
	int	frameNbr = 0;

	this->_window.setFramerateLimit(60);

	this->_map.load();
	while (this->_window.isOpen()) {
//		std::cout << "Frame N°[" << frameNbr << "]\n";
		this->eventHandle(player);
		this->displayLoop(player);
		this->deleteBullet();
		frameNbr++;
	}
}

sf::RenderWindow	&GameHandler::getWindow()
{
	return this->_window;
}
