/*
** EPITECH PROJECT, 2018
** cpp_indie_studio
** File description:
** MyEventReceiver
*/

#include "Menu.hpp"
#include "MyEventReceiver.hpp"
#include <iostream>
#include <fstream>
#include <string>

MyEventReceiver::MyEventReceiver(SAppContext &context)
			: Context(context),
			_btnhdl({{GUI_ID_QUIT_BUTTON,
			[this](void) {
				Mix_PlayChannel(-1, _btn_player, 0);				
				free_sounds();
				Context.device->closeDevice();
				exit(0);				
			}},
			{GUI_ID_P1_BUTTON,
			[this](void) {
				static int i = 0;
				setBtnStatus(i, Context.p1);
			}},
			{GUI_ID_P2_BUTTON,
			[this](void) {
				static int i = 0;
				setBtnStatus(i, Context.p2);
			}},
			{GUI_ID_P3_BUTTON,
			[this](void) {
				static int i = 0;
				setBtnStatus(i, Context.p3);
			}},
			{GUI_ID_P4_BUTTON,
			[this](void) {
				static int i = 0;
				setBtnStatus(i, Context.p4);
			}},
			{GUI_ID_CONT_BUTTON,
			[this](void) {
				free_sounds();	
				Context.device->closeDevice();				
			}},
			{GUI_ID_PLAY_BUTTON,
			[this](void) {
				Mix_PlayChannel(-1, _btn_player, 0);				
				free_sounds();				
				Context.device->closeDevice();
			}}})
{
	if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) {
		std::cerr << "SDL_mixer could not initialize!"
			  << " SDL_mixer Error: " << Mix_GetError()
			  << std::endl;
		exit(84);
	}
	_btn_player = Mix_LoadWAV("sounds/click.wav");
}
bool	MyEventReceiver::OnEvent(const irr::SEvent& event)
{
	if (event.EventType == irr::EET_GUI_EVENT) {
		irr::s32 id = event.GUIEvent.Caller->getID();

		switch (event.GUIEvent.EventType) {
			case irr::gui::EGET_BUTTON_CLICKED:
				_btnhdl[id]();
				break ;
			default:;
		}
	}
	return false;
}

void	MyEventReceiver::free_sounds()
{
	Mix_FreeChunk(_btn_player);	
	_btn_player = NULL;
}

void	MyEventReceiver::setBtnStatus(int &i, irr::gui::IGUIButton *btn)
{	
	if (i == 0)
		btn->setImage(Context.driver->getTexture("assets/player.png"));
	else if (i == 1)
		btn->setImage(Context.driver->getTexture("assets/ai.png"));
	else {
		btn->setImage(Context.driver->getTexture("assets/none.png"));
		i = 0;
		return ;
	}
	i++;
	Mix_PlayChannel(-1, _btn_player, 0);
}