/*
** EPITECH PROJECT, 2018
** cpp_indie_studio
** File description:
** Blast
*/

#ifndef BLAST_HPP_
#define BLAST_HPP_

#include <irr/irrlicht.h>
#include "Object.hpp"

class Blast : public Object
{
public:
	Blast(irr::IrrlichtDevice *device);
	Blast(irr::f32, irr::f32, irr::scene::ISceneManager *&,
	irr::video::ITexture *&);
	~Blast();
	bool gonnaGo();
	bool isValid();
	size_t _x;
	size_t _y;
	bool _bonus;

private:
	irr::ITimer *_timer;
};

#endif /* !BLAST_HPP_ */
