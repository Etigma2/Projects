/*
** EPITECH PROJECT, 2018
** cpp_indie_studio
** File description:
** Crate
*/

#include "Crate.hpp"

Crate::Crate(irr::f32 x, irr::f32 y, irr::scene::ISceneManager *&sceneManager,
	irr::video::ITexture *&crate)
{	
	_type = CRATE;
	_objPtr = sceneManager->addCubeSceneNode(20.0f, 0, -1,
	irr::core::vector3df(x, y, 0.0f));
	if (_objPtr) {
		static_cast<irr::scene::IMeshSceneNode *>(_objPtr)
		->setMaterialFlag(irr::video::EMF_LIGHTING, false);
		static_cast<irr::scene::IMeshSceneNode *>(_objPtr)
		->setMaterialTexture(0, crate);
	}
}

Crate::~Crate()
{
}
