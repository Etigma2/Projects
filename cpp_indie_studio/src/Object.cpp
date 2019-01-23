/*
** EPITECH PROJECT, 2018
** cpp_indie_studio
** File description:
** Object
*/

#include "Object.hpp"

Object::Object()
{
}

Object::~Object()
{
}

void	Object::setType(int type)
{
	_type = type;
}

int	Object::getType() const
{
	return (_type);
}

void	*Object::getPtr() const
{
	return (_objPtr);
}