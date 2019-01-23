/*
** EPITECH PROJECT, 2018
** cpp_indie_studio
** File description:
** MyEventReceiver
*/

#ifndef MYEVENTRECEIVER_HPP_
	#define MYEVENTRECEIVER_HPP_

#include <unordered_map>
#include <utility>
#include <irr/irrlicht.h>
#include <functional>
#include "Menu.hpp"

class MyEventReceiver : public irr::IEventReceiver
{
public:
	MyEventReceiver(SAppContext &context);

	virtual bool OnEvent(const irr::SEvent& event);

	private:
		void	setBtnStatus(int &i, irr::gui::IGUIButton *btn);
		bool	handleEvt(irr::s32 id);
		void	free_sounds();
		SAppContext &Context;
		std::unordered_map<int, std::function<void()>> _btnhdl;
		Mix_Chunk			*_btn_player;
		Mix_Chunk			*_btn_game;
		Mix_Chunk			*_btn_quit;		
};

#endif /* !MYEVENTRECEIVER_HPP_ */
