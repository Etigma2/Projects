/*
** EPITECH PROJECT, 2018
** cpp_indie_studio
** File description:
** Bomb
*/

#ifndef BOMB_HPP_
#define BOMB_HPP_

#include "Enums.hpp"
#include <irr/irrlicht.h>
#include "Object.hpp"

class Bomb : public Object
{
public:
	Bomb(irr::IrrlichtDevice *device);
	Bomb(irr::f32 x, irr::f32 y, irr::scene::ISceneManager *&sceneManager,
	irr::scene::IAnimatedMesh *&mesh_bonus,
	irr::video::ITexture *&bonus);
	~Bomb();
	bool gonnaBlow();
	bool isValid();
	size_t _x;
	size_t _y;
	size_t _power;

private:
	irr::ITimer *_timer;
};

#endif /* !BOMB_HPP_ */
