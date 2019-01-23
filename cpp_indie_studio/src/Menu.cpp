/*
** EPITECH PROJECT, 2018
** cpp_indie_studio
** File description:
** Menu
*/

#include "Menu.hpp"
#include "MyEventReceiver.hpp"

Menu::Menu(Map &_map)
{
	(void)_map;
	device = irr::createDevice(irr::video::EDT_OPENGL,
	irr::core::dimension2d<irr::u32>(800,600), 32, false, true, false, 0);
	driver = device->getVideoDriver();
	sceneManager = device->getSceneManager();
	guienv = device->getGUIEnvironment();
	initBkg();
	for (int i = 0; device->run() && i < 200 && driver; i++) {
		driver->beginScene (true, true,
		irr::video::SColor(255,100,101,140));
		driver->draw2DImage(splash, irr::core::position2d<irr::s32>
		(0,0), irr::core::rect<irr::s32>(0, 0, 800, 600), 0,
		irr::video::SColor(255,255,255,255), false);
		sceneManager->drawAll();
		driver->endScene();
	}
	initImgs();
	p4 = guienv->addButton(irr::core::rect<irr::s32>(560, 200, 700,
	200 + 150), 0, GUI_ID_P4_BUTTON, L"", L"Choose the players");
	initBtn(p4, "assets/none.png");	
	initContext();
	display_menu();
}

Menu::~Menu()
{
}

void	Menu::initBtn(irr::gui::IGUIButton *btn, std::string asset)
{
	btn->setImage(driver->getTexture(
		static_cast<irr::io::path>(asset.c_str())));	
	btn->setUseAlphaChannel(true);
	btn->setDrawBorder(0);
}

void	Menu::initBkg()
{
	back = driver->getTexture("assets/background.png");
	driver->makeColorKeyTexture(back,
	irr::core::position2d<irr::s32>(0,0));
	label = driver->getTexture("assets/label_back.png");
	driver->makeColorKeyTexture(label,
	irr::core::position2d<irr::s32>(0,0));
	character = driver->getTexture("assets/bomb_back.png");
	driver->makeColorKeyTexture(character,
	irr::core::position2d<irr::s32>(0,0));
	splash = driver->getTexture("assets/splashScreen.jpg");
	driver->makeColorKeyTexture(splash,
	irr::core::position2d<irr::s32>(0,0));
}

void	Menu::initImgs()
{
	quit = guienv->addButton(irr::core::rect<irr::s32>
	(10,400,200,400 + 70), 0, GUI_ID_QUIT_BUTTON, L"", L"Exits the game");
	initBtn(quit, "assets/quit.png");
	play = guienv->addButton(irr::core::rect<irr::s32>(510,400,
	800,400 + 70), 0, GUI_ID_PLAY_BUTTON, L"", L"Start a new game");
	initBtn(play, "assets/play.png");
	_continue = guienv->addButton(irr::core::rect<irr::s32>(220,500,
	540,500 + 70), 0, GUI_ID_CONT_BUTTON, L"", L"Continue a game");
	initBtn(_continue, "assets/continue.png");
	p1 = guienv->addButton(irr::core::rect<irr::s32>(100, 200, 240, 200
	+ 150), 0, GUI_ID_P1_BUTTON, L"", L"Choose the players");
	initBtn(p1, "assets/none.png");	
	p2 = guienv->addButton(irr::core::rect<irr::s32>(260,200,
	380,200 + 150), 0, GUI_ID_P2_BUTTON, L"", L"Choose the players");
	initBtn(p2, "assets/none.png");	
	p3 = guienv->addButton(irr::core::rect<irr::s32>(400,200, 540,
	200 + 150), 0, GUI_ID_P3_BUTTON, L"", L"Choose the players");
	initBtn(p3, "assets/none.png");	
}

void	Menu::initContext()
{
	context.device = device;
	context.driver = driver;
	context.p1 = p1;
	context.p2 = p2;
	context.p3 = p3;
	context.p4 = p4;
}

void	Menu::elems()
{
	if (device->isWindowActive()) {
		driver->beginScene (true, true,
		irr::video::SColor(255,100,101,140));
		new_frame(driver, back);
		driver->draw2DImage(label, irr::core::position2d<irr::s32>
		(90,20), irr::core::rect<irr::s32>(0,0,600,210), 0,
                irr::video::SColor(255,255,255,255), true);
		driver->draw2DImage(character, irr::core::position2d<irr::s32>
		(300,400), irr::core::rect<irr::s32>(0,0,160,185), 0,
                irr::video::SColor(255,255,255,255), true);
		sceneManager->drawAll();
		guienv->drawAll();
		driver->endScene();
	}
}

void	Menu::display_menu()
{
	MyEventReceiver	receiver(context);
	device->setEventReceiver(&receiver);

	Mix_Music *_Music = Mix_LoadMUS("sounds/bomberman.wav");
	Mix_PlayMusic(_Music, -1);
	while(device->run() && driver)
		elems();
	if (Mix_PlayingMusic()) {
		Mix_FreeMusic(_Music);
		_Music = NULL;
	}
	device->drop();
}

void	Menu::new_frame(irr::video::IVideoDriver* driver,
irr::video::ITexture *back)
{
	static	float i = 0;
	
	driver->draw2DImage(back, irr::core::position2d<irr::s32>
	(0,-600 * floor(i)), irr::core::rect<irr::s32>(0,0,800,4800), 0,
	irr::video::SColor(255,255,255,255), false);
	if (i < 7)
		i += 0.15;
	else
		i = 0;
}

