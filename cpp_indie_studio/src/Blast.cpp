/*
** EPITECH PROJECT, 2018
** cpp_indie_studio
** File description:
** Blast
*/

#include "Blast.hpp"
#include "Enums.hpp"

Blast::~Blast()
{
}

Blast::Blast(irr::IrrlichtDevice *device)
    : _x(5555555555), _y(5555555555), _bonus(false), _timer(device->getTimer())
{
	_timer->start();
}

Blast::Blast(irr::f32 x, irr::f32 y, irr::scene::ISceneManager *&sceneManager,
	irr::video::ITexture *&blast)
{
	_type = BLAST;
	_objPtr = sceneManager->addCubeSceneNode(20.0f, 0, -1,
	irr::core::vector3df(x, y, 0.0f));
	if (_objPtr) {
		static_cast<irr::scene::IMeshSceneNode *>(_objPtr)
		->setMaterialFlag(irr::video::EMF_LIGHTING, false);
		static_cast<irr::scene::IMeshSceneNode *>(_objPtr)
		->setMaterialTexture(0, blast);
	}
}

bool Blast::gonnaGo()
{
	size_t t = static_cast<size_t>(_timer->getTime());
	return (t > 500);
}

bool Blast::isValid()
{
	if (_x > 0 && _x < MAP_SIZE && _y > 0 && _y < MAP_SIZE)
		return (true);
	return (!true);
}