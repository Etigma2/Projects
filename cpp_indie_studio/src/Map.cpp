/*
** EPITECH PROJECT, 2018
** cpp_indie_studio
** File description:
** Map
*/

#include "Map.hpp"

void Map::checkBombs(irr::IrrlichtDevice *device)
{
	for (size_t i = 0; i < _bombs.size(); i++) {
		if (_bombs[i].isValid() == false)
			_bombs.erase(_bombs.begin() + i);
		if (_bombs[i].gonnaBlow()) {
			blowBomb(device, _bombs[i]);
			_bombs.erase(_bombs.begin() + i);
		}
	}
	for (size_t i = 0; i < _blasts.size(); i++) {
		if (_blasts[i].isValid() == false)
			_blasts.erase(_blasts.begin() + i);
		if (_blasts[i].gonnaGo()) {
			_map[_blasts[i]._y][_blasts[i]._x] =
			_blasts[i]._bonus == true ? BONUS : PATH;
			_blasts.erase(_blasts.begin() + i);
		}
	}
	for (size_t i = 0; i < _players.size(); i++)
		_players[i].checkBombs(_bombs);
}

bool Map::receiveInput(irr::IrrlichtDevice *device, int nbPlayer, int input)
{
	checkBombs(device);
	if (_players[nbPlayer].isDead())
		return (false);
	for (size_t i = 0; i < _players.size(); i++) {
		_players[i].checkBombs(getBombs());
	}
	if (input == DROP && _players[nbPlayer].canDrop()) {
		Bomb bomb = plopBomb(device, _players[nbPlayer]);
		if (bomb.isValid()) {
			_players[nbPlayer].addBomb(bomb);
		}
	}
	if (input >= UP && input <= LEFT) {
		if (movePlayer(_players[nbPlayer], input))
			return (true);
	}
	return (false);
}

static bool crateLoot()
{
	if (size_t(rand() % 100) < BONUS_DROP_PERCENTAGE)
		return (true);
	return (false);
}

Bomb Map::findBomb(size_t y, size_t x)
{
	for (size_t i = 0; i < _bombs.size(); i++) {
		if (_bombs[i]._y == y && _bombs[i]._x == x)
			return (_bombs[i]);
	}
	return (nullptr);
}

bool Map::kaboom(irr::IrrlichtDevice *device, Bomb b, size_t y, size_t x)
{
	if (_map[b._y + y][b._x + x] == CRATE) {
		makeBlast(device, b._y + y, b._x + x, crateLoot());
		return (true);
	} else if (_map[b._y + y][b._x + x] == WALL ||
	_map[b._y + y][b._x + x] == BLAST)
		return (true);
	else if (_map[b._y + y][b._x + x] == BOMB) {
		blowBomb(device, findBomb(b._y + y, b._x + x));
	}
	makeBlast(device, b._y + y, b._x + x, false);
	return (false);
}

void Map::isSomeoneDead(size_t y, size_t x)
{
	for (size_t i = 0; i < _players.size(); i++) {
		if (_players[i].isDead() ||
		(_players[i]._x == x && _players[i]._y == y))
			_players[i].kill();
	}
}

void Map::blowBomb(irr::IrrlichtDevice *device, Bomb b)
{
	if (!b.isValid())
		return;
	bool blocku = false;
	bool blockd = false;
	bool blockr = false;
	bool blockl = false;
	_map[b._y][b._x] = PATH;
	isSomeoneDead(b._y, b._x);
	makeBlast(device, b._y, b._x, false);
	for (size_t i = 1; i < b._power + 1; i++) {
		blocku = blocku ? true : kaboom(device, b, -i, 0);
		blockd = blockd ? true : kaboom(device, b, i, 0);
		blockr = blockr ? true : kaboom(device, b, 0, i);
		blockl = blockl ? true : kaboom(device, b, 0, -i);
	}
}

void Map::makeBlast(irr::IrrlichtDevice *device, size_t y, size_t x, bool bo)
{
	Blast bl(device);
	bl._x = x;
	bl._y = y;
	bl._bonus = bo;
	if (!bl.isValid())
		return;
	_map[y][x] = BLAST;
	_blasts.push_back(bl);
	for (size_t i = 0; i < _players.size(); i++) {
		if (_players[i]._x == x && _players[i]._y == y)
			_players[i].kill();
	}
}

Bomb Map::plopBomb(irr::IrrlichtDevice *device, Player &p)
{
	Bomb B(device);
	if (p.isDead())
		return (B);
	if (_map[p._y][p._x] != PATH)
		return (B);
	_map[p._y][p._x] = BOMB;
	B._y = p._y;
	B._x = p._x;
	B._power = p.getPower();
	_bombs.push_back(B);
	return (B);
}

bool Map::movePlayer(Player &player, int dir)
{
	bool moved = moveUp(player, dir);
	moved = moved == true ? true : moveDown(player, dir);
	moved = moved == true ? true : moveLeft(player, dir);
	moved = moved == true ? true : moveRight(player, dir);
	return (moved);
}

bool Map::moveUp(Player &p, int direction)
{
	int x = p._x;
	int y = p._y;
	if (direction != UP || x < 1 || y < 1)
		return (false);
	if (_map[y - 1][x] == PATH) {
		p._y--;
		return (true);
	}
	if (_map[y - 1][x] == BONUS) {
		p._y--;
		p.upPow();
		_map[y - 1][x] = PATH;
		return (true);
	}
	return (false);
}

bool Map::moveDown(Player &p, int direction)
{
	int x = p._x;
	int y = p._y;
	if (direction != DOWN || x < 1 || y < 1)
		return (false);
	if (_map[y + 1][x] == PATH) {
		p._y++;
		return (true);
	}
	if (_map[y + 1][x] == BONUS) {
		p._y++;
		p.upPow();
		_map[y + 1][x] = PATH;
		return (true);
	}
	return (false);
}

bool Map::moveRight(Player &p, int direction)
{
	size_t x = p._x;
	size_t y = p._y;
	if (direction != RIGHT || x < 1 || y < 1)
		return (false);
	if (_map[y][x + 1] == PATH) {
		p._x++;
		return (true);
	}
	if (_map[y][x + 1] == BONUS) {
		p._x++;
		p.upPow();
		_map[y][x + 1] = PATH;
		return (true);
	}
	return (false);
}

bool Map::moveLeft(Player &p, int direction)
{
	int x = p._x;
	int y = p._y;
	if (direction != LEFT || x < 1 || y < 1)
		return (false);
	if (_map[y][x - 1] == PATH) {
		p._x--;
		return (true);
	}
	if (_map[y][x - 1] == BONUS) {
		p._x--;
		p.upPow();
		_map[y][x - 1] = PATH;
		return (true);
	}
	return (false);
}

Map::Map()
{
	srand(time(NULL));
	generateMap();
}

static int randomCrate()
{

	if (size_t(rand() % 100) < FILL_PERCENTAGE)
		return (CRATE);
	if (size_t(rand() % 100) < BONUS_DROP_PERCENTAGE)
		return (BONUS);
	return (PATH);
}

static std::vector<int> generateWallRow(bool end)
{
	std::vector<int> wa;

	if (end) {
		for (size_t e = 0; e < MAP_SIZE; e++)
			wa.push_back(WALL);
	} else {
		for (size_t e = 0; e < MAP_SIZE; e++)
			e % 2 == 0 ? wa.push_back(WALL)
				   : wa.push_back(randomCrate());
	}
	return (wa);
}

static std::vector<int> generateEmptyRow()
{
	std::vector<int> em;

	em.push_back(WALL);
	for (size_t e = 0; e < MAP_SIZE - 2; e++) {
		em.push_back(randomCrate());
	}
	em.push_back(WALL);
	return (em);
}

void Map::setCorners()
{
	_map[1][1] = PATH;
	_map[1][2] = PATH;
	_map[2][1] = PATH;
	_map[1][MAP_SIZE - 2] = PATH;
	_map[1][MAP_SIZE - 3] = PATH;
	_map[2][MAP_SIZE - 2] = PATH;
	_map[MAP_SIZE - 2][1] = PATH;
	_map[MAP_SIZE - 3][1] = PATH;
	_map[MAP_SIZE - 2][2] = PATH;
	_map[MAP_SIZE - 2][MAP_SIZE - 2] = PATH;
	_map[MAP_SIZE - 2][MAP_SIZE - 3] = PATH;
	_map[MAP_SIZE - 3][MAP_SIZE - 2] = PATH;
}

void Map::setPlayers()
{
	Player p;
	p._y = 1;
	p._x = 1;
	p.setNb(0);
	_players.push_back(p);
	if (NB_PLAYERS >= 1)
		return;
	p._x = MAP_SIZE - 2;
	p.setNb(1);
	_players.push_back(p);
	setRestPlayers(p);
}

void Map::setRestPlayers(Player p)
{
	if (NB_PLAYERS >= 2)
		return;
	p._y = MAP_SIZE - 2;
	p._x = 1;
	p.setNb(2);
	_players.push_back(p);
	if (NB_PLAYERS >= 3)
		return;
	p._x = MAP_SIZE - 2;
	p.setNb(3);
	_players.push_back(p);
}

void Map::generateMap()
{
	_map.push_back(generateWallRow(true));
	for (size_t e = 0; e < MAP_SIZE - 2; e++) {
		e % 2 == 1 ? _map.push_back(generateWallRow(false))
			   : _map.push_back(generateEmptyRow());
	}
	_map.push_back(generateWallRow(true));
	setCorners();
	setPlayers();
}

Map::~Map()
{
}

static bool isPlayer(size_t y, size_t x, std::vector<Player> _players)
{

	for (size_t i = 1; i < _players.size(); i++) {
		if (_players[i]._y == y && _players[i]._x == x)
			return (true);
	}
	return (false);
}

void Map::showAscii()
{
	for (size_t i = 0; i < _map.size(); i++) {
		for (size_t e = 0; e < _map[i].size(); e++) {
			int a = _map[i][e];
			if (isPlayer(i, e, _players))
				printf("0");
			else if (a == WALL)
				printf("#");
			else if (a == PATH)
				printf(" ");
			else if (a == CRATE)
				printf("+");
			else if (a == BOMB)
				printf("¤");
			else
				printf("$");
		}
		printf("\n");
	}
	printf("\n");
}

std::vector<std::vector<int>> Map::getMap()
{
	return (_map);
}

std::vector<Player> Map::getPlayers()
{
	return (_players);
}

std::vector<Bomb> Map::getBombs()
{
	return (_bombs);
}

std::vector<Blast> Map::getBlasts()
{
	return (_blasts);
}
