/*
** EPITECH PROJECT, 2018
** cpp_indie_studio
** File description:
** CEventReceiver
*/

#ifndef CEVENTRECEIVER_HPP_
#define CEVENTRECEIVER_HPP_

#include "Map.hpp"
#include <iostream>
#include <irr/irrlicht.h>
#include <string>

class CEventReceiver : public irr::IEventReceiver
{
public:
	CEventReceiver(irr::scene::IAnimatedMeshSceneNode *nModele, Map *map,
	irr::IrrlichtDevice *device);
	virtual bool OnEvent(const irr::SEvent &event);
	bool majPosMesh();
	bool defaultPos();
	~CEventReceiver();

private:
	void xNegDirection();
	void xDirection();
	void yDirection();
	void yNegDirection();
	void zKeyPressed(const irr::SEvent &event);
	void sKeyPressed(const irr::SEvent &event);
	void qKeyPressed(const irr::SEvent &event);
	void dKeyPressed(const irr::SEvent &event);
	irr::scene::IAnimatedMeshSceneNode *m_Nmodele;
	irr::IrrlichtDevice *_device;
	Map *_map;
	int X;
	int Y;
	bool m_isMoving;
	std::string m_direction;

protected:
};

#endif /* !CEVENTRECEIVER_HPP_ */
