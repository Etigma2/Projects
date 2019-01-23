/*
** EPITECH PROJECT, 2018
** cpp_indie_studio
** File description:
** graph
*/

#include "Graph.hpp"

Graph::Graph(Map &M)
	:	_map(M),
	_dispElem(
	{{WALL,
	[this](size_t x, size_t y,
	std::vector<std::vector<Object>> &Objects) {
		irr::f32 nx = x * 20;
		irr::f32 ny = y * 20;
		(void)Objects;
	       /*irr::scene::IMeshSceneNode *cube =
	       _sceneManager->addCubeSceneNode(
	       20.0f, 0, -1, irr::core::vector3df(-nx, -ny, 0.0f));
	       (void)_map_buffer;
	       if (cube) {
		       cube->setMaterialFlag(irr::video::EMF_LIGHTING, false);
		       cube->setMaterialTexture(0, _wall);
	       }*/
		Wall	wall(-nx, -ny, _sceneManager, _wall);
	}},
	{CRATE,
	[this](size_t x, size_t y,
	std::vector<std::vector<Object>> &Objects) {
		irr::f32 nx = x * 20;
		irr::f32 ny = y * 20;
		if (Objects[y][x].getPtr() != nullptr &&
		Objects[y][x].getType() == CRATE)
			return;
		_dispElem[PATH](x, y, Objects);
		Crate crate(-nx, -ny, _sceneManager, _crate);
		/*irr::scene::IMeshSceneNode *cube =
		_sceneManager->addCubeSceneNode(
		20.0f, 0, -1, irr::core::vector3df(-nx, -ny, 0.0f));*/
		if (Objects[y][x].getPtr() != nullptr &&
		Objects[y][x].getType() != CRATE)
			deletenode(Objects[y][x]);
	     /* if (cube) {
		      cube->setMaterialFlag(irr::video::EMF_LIGHTING, false);
		      cube->setMaterialTexture(0, _crate);
	      }
	      _map_buffer[y][x].second = CRATE;
	      _map_buffer[y][x].first = cube;*/
	      Objects[y][x] = crate;
	}},
	{PATH,
	[this](size_t x, size_t y,
	std::vector<std::vector<Object>> &Objects) {
	      	Path	path;
		if (Objects[y][x].getPtr() != nullptr &&
		Objects[y][x].getType() != PATH)
			deletenode(Objects[y][x]);
		Objects[y][x] = path;
	}},
	{BONUS,
	[this](size_t x, size_t y,
	std::vector<std::vector<Object>> &Objects) {
		irr::f32 nx = x * 20;
		irr::f32 ny = y * 20;
		if (Objects[y][x].getPtr() != nullptr &&
		Objects[y][x].getType() == BONUS)
		      return;
		Bonus	bonus(-nx, -ny, _sceneManager, _mesh_bonus, _bonus);
		/*irr::scene::IAnimatedMeshSceneNode *node =
		_sceneManager->addAnimatedMeshSceneNode(_mesh_bonus, 0, -1,
		irr::core::vector3df(-nx, -ny, 0.0f),
		irr::core::vector3df(0.0f, 0.0f, 0.0f),
		irr::core::vector3df(3.0f, 3.0f, 3.0f));*/
		if (Objects[y][x].getPtr() != nullptr &&
		Objects[y][x].getType() != BONUS)
			deletenode(Objects[y][x]);
		/*if (node) {
			node->setMaterialFlag(irr::video::EMF_LIGHTING, false);
			node->setMaterialTexture(0, _bonus);
		}
		_map_buffer[y][x].second = BONUS;
		_map_buffer[y][x].first = node;*/
		Objects[y][x] = bonus;
		Mix_PlayChannel(-1, _gift, 0);
		}},
		{BOMB,
		[this](size_t x, size_t y,
		std::vector<std::vector<Object>> &Objects) {
		irr::f32 nx = x * 20;
		irr::f32 ny = y * 20;
		if (Objects[y][x].getPtr() != nullptr &&
		Objects[y][x].getType() == BOMB)
			return;
		Bomb	bomb(-nx, -ny, _sceneManager, _mesh_bomb, _bomb);
		/*irr::scene::IAnimatedMeshSceneNode *node =
		_sceneManager->addAnimatedMeshSceneNode(_mesh_bomb, 0, -1,
		irr::core::vector3df(-nx, -ny, 0.0f),
		irr::core::vector3df(0.0f, 0.0f, 0.0f),
		irr::core::vector3df(20.0f, 20.0f, 20.0f));*/
		if (Objects[y][x].getPtr() != nullptr &&
		Objects[y][x].getType() != BOMB)
		      deletenode(Objects[y][x]);
	      /*if (node) {
		      node->setMaterialFlag(irr::video::EMF_LIGHTING, false);
		      node->setMaterialTexture(0, _bomb);
	      }
	      _map_buffer[y][x].second = BOMB;
	      _map_buffer[y][x].first = node;*/
		Objects[y][x] = bomb;
		Mix_PlayChannel(-1, _dropping, 0);
	}},
	{BLAST,
	[this](size_t x, size_t y,
	std::vector<std::vector<Object>> &Objects) {
		irr::f32 nx = x * 20;
		irr::f32 ny = y * 20;
		if (Objects[y][x].getPtr() != nullptr &&
		Objects[y][x].getType() == BLAST)
			return;
		Blast	blast(-nx, -ny, _sceneManager, _blast);
		/*irr::scene::IMeshSceneNode *cube =
		_sceneManager->addCubeSceneNode(
		20.0f, 0, -1, irr::core::vector3df(-nx, -ny, 0.0f));*/
		if (Objects[y][x].getPtr() != nullptr &&
		Objects[y][x].getType() != BLAST)
			deletenode(Objects[y][x]);
	      /*if (cube) {
		      cube->setMaterialFlag(irr::video::EMF_LIGHTING, false);
		      cube->setMaterialTexture(0, _blast);
		}
	      _map_buffer[y][x].second = BLAST;
	      _map_buffer[y][x].first = cube;*/
		Objects[y][x] = blast;
		Mix_PlayChannel(-1, _explosion, 0);
      }}})
      /*_dispElem(
      {{WALL,
       [this](size_t x, size_t y,
	std::vector<std::vector<std::pair<void *, int>>> &_map_buffer) {
	       irr::f32 nx = x * 20;
	       irr::f32 ny = y * 20;
	       irr::scene::IMeshSceneNode *cube =
	       _sceneManager->addCubeSceneNode(
	       20.0f, 0, -1, irr::core::vector3df(-nx, -ny, 0.0f));
	       (void)_map_buffer;
	       if (cube) {
		       cube->setMaterialFlag(irr::video::EMF_LIGHTING, false);
		       cube->setMaterialTexture(0, _wall);
	       }
       }},
      {CRATE,
      [this](size_t x, size_t y,
      std::vector<std::vector<std::pair<void *, int>>> &_map_buffer) {
	      irr::f32 nx = x * 20;
	      irr::f32 ny = y * 20;
	      if (_map_buffer[y][x].first != nullptr &&
	      _map_buffer[y][x].second == CRATE)
		      return;
	      _dispElem[PATH](x, y, _map_buffer);
	      irr::scene::IMeshSceneNode *cube =
	      _sceneManager->addCubeSceneNode(
	      20.0f, 0, -1, irr::core::vector3df(-nx, -ny, 0.0f));
	      if (_map_buffer[y][x].first != nullptr &&
	      _map_buffer[y][x].second != CRATE)
		      deletenode(_map_buffer[y][x]);
	      if (cube) {
		      cube->setMaterialFlag(irr::video::EMF_LIGHTING, false);
		      cube->setMaterialTexture(0, _crate);
	      }
	      _map_buffer[y][x].second = CRATE;
	      _map_buffer[y][x].first = cube;
      }},
      {PATH,
      [this](size_t x, size_t y,
      std::vector<std::vector<std::pair<void *, int>>> &_map_buffer) {
		if (_map_buffer[y][x].first != nullptr &&
	      _map_buffer[y][x].second != PATH)
		      deletenode(_map_buffer[y][x]);
	      _map_buffer[y][x].second = PATH;
	      _map_buffer[y][x].first = nullptr;
      }},
      {BONUS,
      [this](size_t x, size_t y,
      std::vector<std::vector<std::pair<void *, int>>> &_map_buffer) {
		irr::f32 nx = x * 20;
		irr::f32 ny = y * 20;
		if (_map_buffer[y][x].first != nullptr &&
		_map_buffer[y][x].second == BONUS)
		      return;
		irr::scene::IAnimatedMeshSceneNode *node =
		_sceneManager->addAnimatedMeshSceneNode(_mesh_bonus, 0, -1,
		irr::core::vector3df(-nx, -ny, 0.0f),
		irr::core::vector3df(0.0f, 0.0f, 0.0f),
		irr::core::vector3df(3.0f, 3.0f, 3.0f));
		if (_map_buffer[y][x].first != nullptr &&
		_map_buffer[y][x].second != BONUS)
			deletenode(_map_buffer[y][x]);
		if (node) {
			node->setMaterialFlag(irr::video::EMF_LIGHTING, false);
			node->setMaterialTexture(0, _bonus);
		}
		_map_buffer[y][x].second = BONUS;
		_map_buffer[y][x].first = node;
		Mix_PlayChannel(-1, _gift, 0);
      }},
      {BOMB,
      [this](size_t x, size_t y,
      std::vector<std::vector<std::pair<void *, int>>> &_map_buffer) {
	      irr::f32 nx = x * 20;
	      irr::f32 ny = y * 20;
	      if (_map_buffer[y][x].first != nullptr &&
	      _map_buffer[y][x].second == BOMB)
		      return;
	      irr::scene::IAnimatedMeshSceneNode *node =
	      _sceneManager->addAnimatedMeshSceneNode(_mesh_bomb, 0, -1,
	      irr::core::vector3df(-nx, -ny, 0.0f),
	      irr::core::vector3df(0.0f, 0.0f, 0.0f),
	      irr::core::vector3df(20.0f, 20.0f, 20.0f));
	      if (_map_buffer[y][x].first != nullptr &&
	      _map_buffer[y][x].second != BOMB)
		      deletenode(_map_buffer[y][x]);
	      if (node) {
		      node->setMaterialFlag(irr::video::EMF_LIGHTING, false);
		      node->setMaterialTexture(0, _bomb);
	      }
	      _map_buffer[y][x].second = BOMB;
	      _map_buffer[y][x].first = node;
	      Mix_PlayChannel(-1, _dropping, 0);
      }},
      {BLAST,
      [this](size_t x, size_t y,
      std::vector<std::vector<std::pair<void *, int>>> &_map_buffer) {
	      irr::f32 nx = x * 20;
	      irr::f32 ny = y * 20;
	      if (_map_buffer[y][x].first != nullptr &&
	      _map_buffer[y][x].second == BLAST)
		      return;
	      irr::scene::IMeshSceneNode *cube =
	      _sceneManager->addCubeSceneNode(
	      20.0f, 0, -1, irr::core::vector3df(-nx, -ny, 0.0f));
	      if (_map_buffer[y][x].first != nullptr &&
	      _map_buffer[y][x].second != BLAST)
		      deletenode(_map_buffer[y][x]);
	      if (cube) {
		      cube->setMaterialFlag(irr::video::EMF_LIGHTING, false);
		      cube->setMaterialTexture(0, _blast);
		}
	      _map_buffer[y][x].second = BLAST;
	      _map_buffer[y][x].first = cube;
	      Mix_PlayChannel(-1, _explosion, 0);
      }}})*/
{
	_device = irr::createDevice(irr::video::EDT_OPENGL,
	irr::core::dimension2d<irr::u32>(800, 600), 32, false, true, false, 0);
	_device->setWindowCaption(L"BOMBERMAN");
	_guienv = _device->getGUIEnvironment();
	_driver = _device->getVideoDriver();
	_sceneManager = _device->getSceneManager();
	charge_textures();
	showPlyInfo();
	_driver->makeColorKeyTexture(
	_back, irr::core::position2d<irr::s32>(0, 0));
	_sceneManager->addCameraSceneNode(0,
	irr::core::vector3df(-100, -100, 200),
	irr::core::vector3df(-100, -100, 100));
}

Graph::~Graph()
{
	Mix_FreeChunk(_gift);
	Mix_FreeChunk(_explosion);
	Mix_FreeChunk(_dropping);
	_gift = NULL;
	_explosion = NULL;
	_dropping = NULL;
}
/*
void Graph::deletenode(std::pair<void *, int> &node)
{
	if (node.second == PATH)
		return;
	if (node.second == BOMB) {
		irr::scene::IAnimatedMeshSceneNode *buffer =
		static_cast<irr::scene::IAnimatedMeshSceneNode *>(node.first);
		buffer->setVisible(false);
		buffer = nullptr;
	} else {
		irr::scene::IMeshSceneNode *buffer =
		static_cast<irr::scene::IMeshSceneNode *>(node.first);
		buffer->setVisible(false);
		buffer = nullptr;
	}
}*/

void Graph::deletenode(Object &node)
{
	if (node.getType() == PATH)
		return;
	if (node.getType() == BOMB) {
		irr::scene::IAnimatedMeshSceneNode *buffer =
		static_cast<irr::scene::IAnimatedMeshSceneNode *>(node.getPtr());
		buffer->setVisible(false);
		buffer = nullptr;
	} else {
		irr::scene::IMeshSceneNode *buffer =
		static_cast<irr::scene::IMeshSceneNode *>(node.getPtr());
		buffer->setVisible(false);
		buffer = nullptr;
	}
}

void	Graph::showPlyInfo()
{
	wchar_t	buffer[100];
	
	swprintf(buffer, 100, L"Player:%*c%i", 11, ' ', _map.getPlayers()[0]
	.getOwnBombs().size());
	_font = _guienv->getFont("font/zorque.png");
	_txt = _guienv->addStaticText(buffer,
	irr::core::rect<irr::s32>(30,21,230,50), false, false, 0, -1, false);
	_txt->setOverrideFont(_font);
	_txt->setOverrideColor(irr::video::SColor(255, 255, 255, 255));
}

void	Graph::updatePlyInfo()
{
	wchar_t	buffer[100];
	
	swprintf(buffer, 100, L"Player:%*c%i", 11, ' ', _map.getPlayers()[0]
	.getOwnBombs().size());
	_txt->setText(buffer);
}

void	Graph::charge_textures()
{
	_back = _driver->getTexture("assets/lava.jpg");
	_wall = _driver->getTexture("assets/wall.jpg");
	_crate = _driver->getTexture("assets/box.jpg");
	_ground = _driver->getTexture("assets/ground.jpg");
	_bomb = _driver->getTexture("assets/bomb/Albedo.png");
	_bonus = _driver->getTexture("assets/heart.jpg");
	_blast = _driver->getTexture("assets/blast.png");
	_mesh_bomb = _sceneManager->getMesh("assets/bomb/Bomb.dae");
	_mesh_bonus = _sceneManager->getMesh("assets/sphere.obj");
	_playerModele = (irr::scene::IAnimatedMeshMD2 *)_sceneManager->getMesh(
	"assets/sydney.md2");
	_nModele = _sceneManager->addAnimatedMeshSceneNode(_playerModele);
	_nModele->setMaterialFlag(irr::video::EMF_LIGHTING, false);
	_nModele->setFrameLoop(0, 0);
	_nModele->setPosition(irr::core::vector3df(-24, -25, 15));
	_nModele->setRotation(irr::core::vector3df(90, 0, 90));
	_nModele->setScale(irr::core::vector3df(0.5, 0.5, 0.5));
	_nModele->setMaterialTexture(
	0, _driver->getTexture("assets/sydney.bmp"));
}
/*
void Graph::display_map(
std::vector<std::vector<std::pair<void *, int>>> &_map_buffer)
{
	static bool disp = false;

	for (size_t i = 0; i < _map.getMap().size(); i++)
		for (size_t j = 0; j < _map.getMap().size(); j++)
			if ((disp && _map.getMap()[i][j] != WALL) || !disp)
				_dispElem[_map.getMap()[i][j]](
				j, i, _map_buffer);
	disp = true;
}*/

void Graph::display_map(
std::vector<std::vector<Object>> &Objects)
{
	static bool disp = false;

	for (size_t i = 0; i < _map.getMap().size(); i++)
		for (size_t j = 0; j < _map.getMap().size(); j++)
			if ((disp && _map.getMap()[i][j] != WALL) || !disp)
				_dispElem[_map.getMap()[i][j]](
				j, i, Objects);
	disp = true;
}

void	Graph::loadMusic()
{
	if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) {
		std::cerr << "SDL_mixer could not initialize!"
			  << " SDL_mixer Error: " << Mix_GetError()
			  << std::endl;
		exit(84);
	}
	_Music = Mix_LoadMUS("sounds/inGame.mp3");
	Mix_PlayMusic(_Music, -1);
	_gift = Mix_LoadWAV("sounds/bonus.wav");
	_explosion = Mix_LoadWAV("sounds/bomb.wav");
	_dropping = Mix_LoadWAV("sounds/drop_bomb.wav");
}

void Graph::load_Mapbuf(
std::vector<std::vector<std::pair<void *, int>>> &_map_buffer)
{
	for (size_t i = 0; i < _map.getMap().size(); i++) {
		std::vector<std::pair<void *, int>> buf;
		for (size_t j = 0; j < _map.getMap().size(); j++)
			buf.push_back(std::make_pair(nullptr, 100));
		_map_buffer.push_back(buf);
	}
}

void Graph::load_Mapbuf(
std::vector<std::vector<Object>> &Objects)
{
	for (size_t i = 0; i < _map.getMap().size(); i++) {
		std::vector<Object> buf;
		for (size_t j = 0; j < _map.getMap().size(); j++)
			buf.push_back(Path());
		Objects.push_back(buf);
	}
}

void	Graph::looseAnim()
{
	if (_map.getPlayers()[0].isDead()) {
		_guienv->clear();
		_sceneManager->clear();
		_Music = Mix_LoadMUS("sounds/GameOver.mp3");
		Mix_PlayMusic(_Music, -1);
		_driver->draw2DImage(_driver->getTexture(
			"assets/GameOver.jpg"),
			irr::core::position2d<irr::s32>
			(0,0), irr::core::rect<irr::s32>(0,0,800,600), 0,
        	        irr::video::SColor(255,255,255,255), true);
		_guienv->drawAll();
		_sceneManager->drawAll();
		_driver->endScene();
		std::this_thread::sleep_for(std::chrono::seconds(11));
		freeGraph();
		exit(0);
	}
}

void Graph::freeGraph()
{
	if (Mix_PlayingMusic()) {
		Mix_FreeMusic(_Music);
		_Music = NULL;
	}
	Mix_CloseAudio();
	_device->drop();
}

void	Graph::drawImgs()
{
	_driver->draw2DImage(_back, irr::core::position2d<irr::s32>
	(0,0), irr::core::rect<irr::s32>(0,0,800,600), 0,
        irr::video::SColor(255,255,255,255), true);
	_driver->draw2DImage(_ground, irr::core::position2d<irr::s32>
	(200,100), irr::core::rect<irr::s32>(0,0,400,400), 0,
        irr::video::SColor(255,255,255,255), true);
	_driver->draw2DImage(_driver->getTexture("assets/states.png"),
	irr::core::position2d<irr::s32>
	(20,10), irr::core::rect<irr::s32>(0,0,265,42), 0,
        irr::video::SColor(255,255,255,255), true);
}

void Graph::graphical_loop()
{
	CEventReceiver receiver(_nModele, &_map, _device);
	_device->setEventReceiver(&receiver);
	// load_Mapbuf(_map_buffer);
	load_Mapbuf(_Objects);
	loadMusic();
	while (_device->run()) {
		_driver->beginScene (true, true,
		irr::video::SColor(255,100,101,140));
		looseAnim();
		drawImgs();
		updatePlyInfo();		
		_map.checkBombs(_device);
		receiver.majPosMesh();
		// display_map(_map_buffer);
		display_map(_Objects);
		_guienv->drawAll();
		_sceneManager->drawAll();
		_driver->endScene();
	}
	freeGraph();
}
