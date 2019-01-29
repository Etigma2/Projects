/*
** EPITECH  PROJECT , 2017
** Map
** File  description:
** 	Class functions for class Map
*/

#include "map.hpp"

Map::Map()
{
	std::cout << "Created Map" << '\n';
}

Map::~Map()
{
	std::cout << "Destroyed Map" << '\n';
}

int Map::getDecors(sf::Vector2f pos)
{
	return (decors[pos.y][pos.x]);
}

int Map::getVision(sf::Vector2f pos)
{
	return (vision[pos.y][pos.x]);
}

void Map::setDecors(sf::Vector2f pos, int value)
{
	decors[pos.y][pos.x] = value;
}

void Map::setVision(sf::Vector2f pos, int value)
{
	vision[pos.y][pos.x] = value;
}

std::vector<int> Map::constructTile(std::string str)
{
	std::vector<int> retur;
	int i = -1;

	while (str[++i]) {
		if (str[i] == 'O') {
			retur.push_back(0);
		}
		else {
			retur.push_back(1);
		}
	}
	return (retur);
}

bool Map::checkValid(sf::Vector2f pos, sf::Vector2f box, sf::Vector2f cam)
{
	std::vector<std::vector<int>> tile;
	int myCase;

	pos.x -= cam.x;
	pos.y -= cam.y;
	if (int(pos.y / (this->caseSize * 15)) >= 0 && int(pos.x / (this->caseSize * 15)) >= 0 && int(pos.x / (this->caseSize * 15)) < 5 && int(pos.y / (this->caseSize * 15)) < 5) {
		tile = this->tiles[tilePlacement[int(pos.y / (this->caseSize * 15))][int(pos.x / (this->caseSize * 15))]];
		if ((int(pos.y) % int((caseSize * 15))) / caseSize >= 0 && (int(pos.x) % int((caseSize * 15))) / caseSize >= 0 && (int(pos.y) % int((caseSize * 15))) / caseSize < 16 && (int(pos.x) % int((caseSize * 15))) / caseSize < 16) {
			myCase = tile[(int(pos.y) % int((caseSize * 15))) / caseSize][(int(pos.x) % int((caseSize * 15))) / caseSize];
		}
		else {
			return (false);
		}
	}
	else  {
		return (false);
	}
	if (myCase == 1) {
		return (false);
	}
	return (true);
}

void Map::load()
{
	int i = -1;

	caseSize = 50;
	while (++i < 5) {
		std::ifstream file;
		std::string temp;
		std::string tileName("./tiles/");
		std::vector<std::vector<int>> tile;

		tileName.append(std::to_string(i + 1));
		file.open(tileName, std::ios::in);
		if (file) {
			while (file >> temp) {
				tile.push_back(constructTile(temp));
			}
			tiles.push_back(tile);
		}
		else {
			std::cout << "Can't open file" << std::endl;
		}
	}
	this->makePlacement(i);
}

void	Map::drawMap(sf::RenderWindow &window, sf::Vector2f cam)
{
	for (int i = 0; i < 5; i++) {
		for (int n = 0; n < 5; n++) {
			this->drawTile(window, sf::Vector2f(i + cam.y / (caseSize * 15), n + cam.x / (caseSize * 15)), this->tilePlacement[i][n]);
		}
	}
}

void	Map::drawTile(sf::RenderWindow &window, sf::Vector2f pos, int tile) {
	int i = -1;
	int n = -1;
	sf::Color color;
	sf::RectangleShape rect(sf::Vector2f(caseSize, caseSize));

	for (std::vector<std::vector<int>>::iterator itiless = tiles[tile].begin(); itiless != tiles[tile].end(); itiless++) {
		++i;
		for (std::vector<int>::iterator itilesss = itiless->begin(); itilesss != itiless->end(); itilesss++) {
			++n;
			if (*(itilesss) == 0) {
				color = sf::Color(0, 0, 0);
			}
			else {
				color = sf::Color(255, 255, 255);
			}
			rect.setFillColor(color);
			rect.setPosition(sf::Vector2f(pos.y * this->caseSize * 15 + n * this->caseSize, pos.x * this->caseSize * 15 + i * this->caseSize));
			window.draw(rect);
		}
		n = -1;
	}
}

std::vector<std::vector<int>>	Map::makePlacement(int nbTiles) {
	int	n = -1;
	int x;

	while (++n < 5) {
		std::vector<int>	toFill;

		x = -1;
		while (++x < 5) {
			toFill.push_back(std::experimental::randint(0, nbTiles - 1));
		}
		tilePlacement.push_back(toFill);
	}
}