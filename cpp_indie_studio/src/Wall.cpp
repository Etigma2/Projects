/*
** EPITECH PROJECT, 2018
** cpp_indie_studio
** File description:
** Wall
*/

#include "Wall.hpp"

Wall::Wall(irr::f32 x, irr::f32 y, irr::scene::ISceneManager *&sceneManager,
	irr::video::ITexture *&wall)
{	
	_type = WALL;
	_objPtr = sceneManager->addCubeSceneNode(20.0f, 0, -1,
	irr::core::vector3df(x, y, 0.0f));
	if (_objPtr) {
		static_cast<irr::scene::IMeshSceneNode *>(_objPtr)
		->setMaterialFlag(irr::video::EMF_LIGHTING, false);
		static_cast<irr::scene::IMeshSceneNode *>(_objPtr)
		->setMaterialTexture(0, wall);
	}
}

Wall::~Wall()
{
}
