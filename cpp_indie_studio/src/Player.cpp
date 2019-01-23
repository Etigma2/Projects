/*
** EPITECH PROJECT, 2018
** cpp_indie_studio
** File description:
** Player
*/

#include "Player.hpp"

Player::Player()
    : _x(55555), _y(55555), _dead(false), _nbBomb(3), _speed(1.0), _power(1),
      _player(-1)
{
}

Player::~Player()
{
}

void Player::setNb(size_t nb)
{
	_player = nb;
	if (nb > 4) {
		_dead = true;
	}
}

void Player::upPow()
{
	_power++;
}

void Player::addBomb(Bomb b)
{
	_activeBombs.push_back(b);
}

bool Player::isDead()
{
	if (_dead || _x < 1 || _x > MAP_SIZE || _y < 1 || _y > MAP_SIZE) {

		_dead = true;
		return (true);
	}
	return (false);
}

void Player::kill()
{
	_dead = true;
}

bool Player::canDrop()
{
	bool ans = getBombCount() < getMaxBombs();
	return (ans);
}

void Player::checkBombs(std::vector<Bomb> _bombs)
{
	if (_dead)
		return;
	for (size_t i = 0; i < _activeBombs.size(); i++) {
		int keep = false;
		for (size_t e = 0; e < _bombs.size(); e++) {
			if (_activeBombs[i]._y == _bombs[e]._y &&
			_activeBombs[i]._x == _bombs[e]._x)
				keep = true;
		}
		if (!keep)
			_activeBombs.erase(_activeBombs.begin() + i);
	}
}

size_t Player::getMaxBombs()
{
	return (_nbBomb);
}

size_t Player::getPower()
{
	return (_power);
}

float Player::getSpeed()
{
	return (_speed);
}

std::vector<Bomb> Player::getOwnBombs()
{
	return (_activeBombs);
}

size_t Player::getBombCount()
{
	return (_activeBombs.size());
}
