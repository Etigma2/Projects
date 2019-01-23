/*
** EPITECH PROJECT, 2018
** cpp_indie_studio
** File description:
** main
*/
#include "Map.hpp"
#include "Menu.hpp"
#include "Graph.hpp"

int main()
{
	Map	M;
	Menu	menu(M);
	Graph	G(M);
	G.graphical_loop();
	return 0;
}
