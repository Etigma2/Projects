/*
** EPITECH PROJECT, 2018
** cpp_indie_studio
** File description:
** Bonus
*/

#ifndef BONUS_HPP_
	#define BONUS_HPP_

#include "Object.hpp"

class Bonus : public Object
{
	public:
		Bonus(irr::f32 x, irr::f32 y, irr::scene::ISceneManager *&sceneManager,
	irr::scene::IAnimatedMesh *&mesh_bonus,
	irr::video::ITexture *&bonus);
		~Bonus();

	protected:
	private:
};

#endif /* !BONUS_HPP_ */
