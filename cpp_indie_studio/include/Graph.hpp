/*
** EPITECH PROJECT, 2018
** cpp_indie_studio
** File description:
** Graph
*/

#ifndef GRAPH_HPP_
#define GRAPH_HPP_

#include "Map.hpp"
#include "CEventReceiver.hpp"

#include <SDL/SDL.h>
#include <SDL/SDL_mixer.h>
#include <cmath>
#include <functional>
#include <irr/irrlicht.h>
#include <unordered_map>
#include <utility>
#include <vector>
#include <stdio.h>
#include <unistd.h>
#include <wchar.h>
#include <chrono>
#include <thread>
#include "Object.hpp"
#include "Path.hpp"
#include "Wall.hpp"
#include "Crate.hpp"
#include "Bonus.hpp"

class Graph
{
public:
	Graph(Map &M);
	~Graph();
	void graphical_loop();

private:
	void display();
	void display_map(
	std::vector<std::vector<std::pair<void *, int>>> &_map_buffer);
	void deletenode(std::pair<void *, int> &node);
	void deletenode(Object &node);
	void display_objs();
	void loadMusic();
	void charge_textures();
	void	drawImgs();
	void load_Mapbuf(
	std::vector<std::vector<std::pair<void *, int>>> &_map_buffer);
	void	load_Mapbuf(std::vector<std::vector<Object>> &Objects);
	void	display_map(std::vector<std::vector<Object>> &Objects);
	void	freeGraph();
	void	showPlyInfo();
	void	updatePlyInfo();
	void	looseAnim();
	irr::IrrlichtDevice *_device;
	irr::video::IVideoDriver *_driver;
	irr::video::ITexture *_back;
	irr::video::ITexture *_crate;
	irr::video::ITexture *_blast;
	irr::video::ITexture *_wall;
	irr::video::ITexture *_ground;
	irr::video::ITexture *_bomb;
	irr::video::ITexture *_bonus;
	irr::scene::ISceneManager *_sceneManager;
	irr::scene::IAnimatedMesh *_mesh_bomb;
	irr::scene::IAnimatedMeshMD2 *_playerModele;
	irr::scene::IAnimatedMeshSceneNode *_nModele;
	irr::scene::IAnimatedMesh *_mesh_bonus;
	Mix_Music *_Music;
	Mix_Chunk *_gift;
	Mix_Chunk *_explosion;
	Mix_Chunk *_dropping;

	irr::gui::IGUIEnvironment	*_guienv;
	irr::gui::IGUIFont		*_font;

	Map _map;
	/*std::unordered_map<int,
	std::function<void(size_t x, size_t y,
	std::vector<std::vector<std::pair<void *, int>>> &_map_buffer)>>
	_dispElem;*/
	std::unordered_map<int, std::function<void(size_t x, size_t y, std::vector<std::vector<Object>> &Objects)>>_dispElem;
	std::vector<std::vector<std::pair<void *, int>>> _map_buffer;
	std::vector<std::vector<Object>> _Objects;
	irr::gui::IGUIStaticText	*_txt;
};

#endif /* !GRAPH_HPP_ */
