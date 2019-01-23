/*
** EPITECH PROJECT, 2018
** cpp_indie_studio
** File description:
** Menu
*/

#ifndef MENU_HPP_
	#define MENU_HPP_

#include <iostream>
#include <irr/irrlicht.h>
#include <vector>
#include <unistd.h>
#include <SDL/SDL.h>
#include <SDL/SDL_mixer.h>
#include "Map.hpp"

typedef struct	SAppContext
{
	irr::IrrlichtDevice		*device;
	irr::video::IVideoDriver	*driver;
	irr::gui::IGUIButton		*p1;
	irr::gui::IGUIButton		*p2;
	irr::gui::IGUIButton		*p3;
	irr::gui::IGUIButton		*p4;

}	SAppContext_t;

enum	IDs
{
	GUI_ID_QUIT_BUTTON = 0,
	GUI_ID_PLAY_BUTTON = 1,
	GUI_ID_CONT_BUTTON = 2,
	GUI_ID_P1_BUTTON = 3,
	GUI_ID_P2_BUTTON = 4,
	GUI_ID_P3_BUTTON = 5,
	GUI_ID_P4_BUTTON = 6	
};



class Menu {
	public:
		Menu(Map &_map);
		~Menu();

	protected:
	private:
		void	new_frame(irr::video::IVideoDriver* driver, irr::video::ITexture *back);
		void	display_menu();
		void	initImgs();
		void	initBkg();
		void	initBtn(irr::gui::IGUIButton *btn, std::string asset);
		void	initContext();
		void	elems();
		irr::IrrlichtDevice		*device;
		irr::video::IVideoDriver	*driver;
		irr::gui::IGUIEnvironment	*guienv;
		irr::scene::ISceneManager	*sceneManager;
		irr::gui::IGUIButton		*p1;
		irr::gui::IGUIButton		*p2;
		irr::gui::IGUIButton		*p3;
		irr::gui::IGUIButton		*p4;
		irr::gui::IGUIButton		*play;
		irr::gui::IGUIButton		*quit;
		irr::gui::IGUIButton		*_continue;		
		irr::video::ITexture		*label;
		irr::video::ITexture		*character;
		irr::video::ITexture		*back;
		irr::video::ITexture		*splash;
		SAppContext			context;
};

#endif /* !MENU_HPP_ */
