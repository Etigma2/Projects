/*
** EPITECH PROJECT, 2018
** cpp_indie_studio
** File description:
** CEventReceiver
*/

#include "CEventReceiver.hpp"

CEventReceiver::~CEventReceiver()
{
}

CEventReceiver::CEventReceiver(irr::scene::IAnimatedMeshSceneNode *Nmodele,
Map *map, irr::IrrlichtDevice *device)
{
	m_Nmodele = Nmodele;
	m_isMoving = false;
	m_direction = "b";
	m_Nmodele->setMD2Animation(irr::scene::EMAT_STAND);
	_map = map;
	_device = device;
	X = 7;
	Y = 7;
}

void CEventReceiver::zKeyPressed(const irr::SEvent &event)
{
	if (event.KeyInput.Key == irr::KEY_KEY_Z) {
		m_direction = "y";
		if (m_isMoving == false) {
			m_Nmodele->setRotation(irr::core::vector3df(90, 0, 90));
			m_Nmodele->setMD2Animation(irr::scene::EMAT_RUN);
			m_isMoving = true;
		}
	}
}

void CEventReceiver::sKeyPressed(const irr::SEvent &event)
{
	if (event.KeyInput.Key == irr::KEY_KEY_S) {
		m_direction = "-y";
		if (m_isMoving == false) {
			m_Nmodele->setRotation(
			irr::core::vector3df(90, 0, 270));
			m_Nmodele->setMD2Animation(irr::scene::EMAT_RUN);
			m_isMoving = true;
		}
	}
}

void CEventReceiver::qKeyPressed(const irr::SEvent &event)
{

	if (event.KeyInput.Key == irr::KEY_KEY_Q) {
		m_direction = "-x";
		if (m_isMoving == false) {
			m_Nmodele->setRotation(irr::core::vector3df(90, 0, 0));
			m_Nmodele->setMD2Animation(irr::scene::EMAT_RUN);
			m_isMoving = true;
		}
	}
}
void CEventReceiver::dKeyPressed(const irr::SEvent &event)
{
	if (event.KeyInput.Key == irr::KEY_KEY_D) {
		m_direction = "x";
		if (m_isMoving == false) {
			m_Nmodele->setRotation(
			irr::core::vector3df(90, 0, 180));
			m_Nmodele->setMD2Animation(irr::scene::EMAT_RUN);
			m_isMoving = true;
		}
	}
}

bool CEventReceiver::OnEvent(const irr::SEvent &event)
{
	if (m_Nmodele != 0 && event.EventType == irr::EET_KEY_INPUT_EVENT) {
		if (event.KeyInput.PressedDown) {
			if (event.KeyInput.Key == irr::KEY_SPACE) {
				if (m_isMoving == false)
					_map->receiveInput(_device, 0, DROP);
				return true;
			}
			zKeyPressed(event);
			sKeyPressed(event);
			qKeyPressed(event);
			dKeyPressed(event);
			return true;
		}
		defaultPos();
	}
	return false;
}

bool CEventReceiver::defaultPos()
{
	m_Nmodele->setMD2Animation(irr::scene::EMAT_STAND);
	m_isMoving = false;
	m_direction = "b";
	return 0;
}

void CEventReceiver::yDirection()
{
	irr::core::vector3df v = m_Nmodele->getPosition();

	if (m_direction.compare("y") == 0) {
		Y++;
		if (Y > 18) {
			Y = 0;
			if (!_map->receiveInput(_device, 0, UP)) {
				Y = 18;
			} else
				v.Y += 1.0f;
		} else
			v.Y += 1.0f;
	}
	m_Nmodele->setPosition(v);
}

void CEventReceiver::yNegDirection()
{
	irr::core::vector3df v = m_Nmodele->getPosition();

	if (m_direction.compare("-y") == 0) {
		Y--;
		if (Y < 0) {
			Y = 18;
			if (!_map->receiveInput(_device, 0, DOWN)) {
				Y = 0;
			} else
				v.Y -= 1.0f;
		} else
			v.Y -= 1.0f;
	}
	m_Nmodele->setPosition(v);
}

void CEventReceiver::xDirection()
{
	irr::core::vector3df v = m_Nmodele->getPosition();

	if (m_direction.compare("x") == 0) {
		X++;
		if (X > 18) {
			X = 0;
			if (!_map->receiveInput(_device, 0, RIGHT)) {
				X = 18;
			} else
				v.X -= 1.0f;
		} else
			v.X -= 1.0f;
	}
	m_Nmodele->setPosition(v);
}

void CEventReceiver::xNegDirection()
{
	irr::core::vector3df v = m_Nmodele->getPosition();

	if (m_direction.compare("-x") == 0) {
		X--;
		if (X < 0) {
			X = 18;
			if (!_map->receiveInput(_device, 0, LEFT)) {
				X = 0;
			} else
				v.X += 1.0f;
		} else
			v.X += 1.0f;
	}
	m_Nmodele->setPosition(v);
}

bool CEventReceiver::majPosMesh()
{
	if (m_Nmodele != 0) {
		if (m_isMoving == true) {
			yDirection();
			yNegDirection();
			xDirection();
			xNegDirection();
			return true;
		}
	}
	return false;
}
