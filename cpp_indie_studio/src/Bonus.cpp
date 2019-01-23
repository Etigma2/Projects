/*
** EPITECH PROJECT, 2018
** cpp_indie_studio
** File description:
** Bonus
*/

#include "Bonus.hpp"

Bonus::Bonus(irr::f32 x, irr::f32 y, irr::scene::ISceneManager *&sceneManager,
	irr::scene::IAnimatedMesh *&mesh_bonus, irr::video::ITexture *&bonus)
{
	_type = BONUS;
	_objPtr = sceneManager->addAnimatedMeshSceneNode(mesh_bonus, 0, -1,
	irr::core::vector3df(x, y, 0.0f),
	irr::core::vector3df(0.0f, 0.0f, 0.0f),
	irr::core::vector3df(3.0f, 3.0f, 3.0f));
	if (_objPtr) {
		static_cast<irr::scene::IAnimatedMeshSceneNode *>(_objPtr)
		->setMaterialFlag(irr::video::EMF_LIGHTING, false);
		static_cast<irr::scene::IAnimatedMeshSceneNode *>(_objPtr)
		->setMaterialTexture(0, bonus);
	}
}

Bonus::~Bonus()
{
}
