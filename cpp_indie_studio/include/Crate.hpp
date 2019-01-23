/*
** EPITECH PROJECT, 2018
** cpp_indie_studio
** File description:
** Crate
*/

#ifndef CRATE_HPP_
	#define CRATE_HPP_

#include "Object.hpp"

class Crate : public Object
{
	public:
		Crate(irr::f32 x, irr::f32 y, irr::scene::ISceneManager *&sceneManager,
	irr::video::ITexture *&crate);
		~Crate();

	protected:
	private:
};

#endif /* !CRATE_HPP_ */
