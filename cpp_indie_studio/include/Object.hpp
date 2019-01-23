/*
** EPITECH PROJECT, 2018
** cpp_indie_studio
** File description:
** Object
*/

#ifndef OBJECT_HPP_
	#define OBJECT_HPP_

#include <irr/irrlicht.h>
#include "Enums.hpp"

class Object {
	public:
		Object();
		~Object();
		void	setType(int type);
		int	getType() const;
		void	*getPtr() const;
	protected:
		void	*_objPtr;
		int	_type;

};

#endif /* !OBJECT_HPP_ */
