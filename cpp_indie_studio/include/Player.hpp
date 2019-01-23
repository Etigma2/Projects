/*
** EPITECH PROJECT, 2018
** cpp_indie_studio
** File description:
** Player
*/

#ifndef PLAYER_HPP_
#define PLAYER_HPP_

#include "Bomb.hpp"
#include "Enums.hpp"

class Player
{
public:
	Player();
	~Player();
	bool isDead();
	size_t getMaxBombs();
	size_t getPower();
	float getSpeed();
	void kill();
	size_t getBombCount();
	std::vector<Bomb> getOwnBombs();
	void addBomb(Bomb b);
	bool canDrop();
	void setNb(size_t nb);
	void upPow();
	size_t _x;
	size_t _y;
	void checkBombs(std::vector<Bomb> _bombs);

private:
	bool _dead;
	size_t _nbBomb;
	float _speed;
	size_t _power;
	int _player;
	std::vector<Bomb> _activeBombs;
};

#endif /* !PLAYER_HPP_ */
