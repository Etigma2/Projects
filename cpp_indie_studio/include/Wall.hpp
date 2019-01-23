/*
** EPITECH PROJECT, 2018
** cpp_indie_studio
** File description:
** Wall
*/

#ifndef WALL_HPP_
	#define WALL_HPP_

#include "Object.hpp"

class Wall : public Object
{
	public:
		Wall(irr::f32, irr::f32, irr::scene::ISceneManager *&,
		irr::video::ITexture *&wall);
		~Wall();
	private:
		irr::video::ITexture *_wall;
};

#endif /* !WALL_HPP_ */
