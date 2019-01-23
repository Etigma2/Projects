/*
** EPITECH PROJECT, 2018
** cpp_indie_studio
** File description:
** Map
*/

#ifndef MAP_HPP_
#define MAP_HPP_

#include <algorithm>
#include <chrono>
#include <cstdio>
#include <ctime>
#include <iostream>
#include <thread>
#include <vector>

#include "Blast.hpp"
#include "Bomb.hpp"
#include "Enums.hpp"
#include "Player.hpp"

class Map
{
public:
	Map();
	~Map();
	bool receiveInput(irr::IrrlichtDevice *device, int nbPlayer, int input);
	void checkBombs(irr::IrrlichtDevice *device);
	void showAscii();
	std::vector<std::vector<int>> getMap();
	std::vector<Player> getPlayers();
	std::vector<Bomb> getBombs();
	std::vector<Blast> getBlasts();

private:
	Bomb plopBomb(irr::IrrlichtDevice *device, Player &p);
	void blowBomb(irr::IrrlichtDevice *device, Bomb b);
	void makeBlast(
	irr::IrrlichtDevice *device, size_t y, size_t x, bool bonus);
	void generateMap();
	void setCorners();
	void setPlayers();
	void setRestPlayers(Player p);
	bool kaboom(irr::IrrlichtDevice *device, Bomb b, size_t y, size_t x);
	void isSomeoneDead(size_t y, size_t x);
	Bomb findBomb(size_t y, size_t x);
	bool movePlayer(Player &player, int direction);
	bool moveUp(Player &player, int direction);
	bool moveDown(Player &player, int direction);
	bool moveRight(Player &player, int direction);
	bool moveLeft(Player &player, int direction);
	std::vector<std::vector<int>> _map;
	std::vector<Player> _players;
	std::vector<Bomb> _bombs;
	std::vector<Blast> _blasts;
};

#endif /* !MAP_HPP_ */
