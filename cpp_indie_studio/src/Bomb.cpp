/*
** EPITECH PROJECT, 2018
** cpp_indie_studio
** File description:
** Bomb
*/

#include "Bomb.hpp"

Bomb::~Bomb()
{
}

Bomb::Bomb(irr::IrrlichtDevice *device)
    : _x(5555555555), _y(5555555555), _power(5555555555),
      _timer(device->getTimer())
{
	_timer->start();
}

Bomb::Bomb(irr::f32 x, irr::f32 y, irr::scene::ISceneManager *&sceneManager,
	irr::scene::IAnimatedMesh *&mesh_bomb, irr::video::ITexture *&bomb)
{
	_type = BOMB;
	_objPtr = sceneManager->addAnimatedMeshSceneNode(mesh_bomb, 0, -1,
	irr::core::vector3df(x, y, 0.0f),
	irr::core::vector3df(0.0f, 0.0f, 0.0f),
	irr::core::vector3df(20.0f, 20.0f, 20.0f));
	if (_objPtr) {
		static_cast<irr::scene::IAnimatedMeshSceneNode *>(_objPtr)
		->setMaterialFlag(irr::video::EMF_LIGHTING, false);
		static_cast<irr::scene::IAnimatedMeshSceneNode *>(_objPtr)
		->setMaterialTexture(0, bomb);
	}
}

bool Bomb::gonnaBlow()
{
	size_t t = static_cast<size_t>(_timer->getTime());
	return (t > BOMB_TIMER_MS);
}

bool Bomb::isValid()
{
	if (_x > 0 && _x < MAP_SIZE && _y > 0 && _y < MAP_SIZE && _power > 0)
		return (true);

	return (!true);
}