/*
** EPITECH  PROJECT , 2017
** map
** File  description:
** 	Class declarations for class map
*/

#ifndef MAP_HPP_
# define MAP_HPP_

#include	<SFML/Graphics.hpp>
#include	<iostream>
#include	<fstream>
#include	<vector>
#include	<experimental/random>

class Map
{

public:

	// Constructors
	Map();

	// Destructor
	~Map();



	// Members Functions

	// Setters
	void	setDecors(sf::Vector2f pos, int value);
	void	setVision(sf::Vector2f pos, int value);

	// Getters
	int	getDecors(sf::Vector2f pos);
	int	getVision(sf::Vector2f pos);

	bool	checkValid(sf::Vector2f pos, sf::Vector2f box, sf::Vector2f cam);
	void	load();
	void	drawMap(sf::RenderWindow &window, sf::Vector2f cam);
	void	drawTile(sf::RenderWindow &window, sf::Vector2f pos, int tile);

private:

	std::vector<std::vector<int>> makePlacement(int nbTiles);

	std::vector<std::vector<int>> tilePlacement;
	std::vector<std::vector<int>> decors;
	std::vector<std::vector<int>> vision;
	std::vector<std::vector<std::vector<int>>> tiles;
	std::vector<int> constructTile(std::string str);
	int caseSize;
	sf::Texture flat;
	sf::Texture wall;
	sf::Texture empty;
};

#endif
