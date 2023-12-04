#pragma once

//  All SFML libraries are here
//		 |
//		 |
//		 V
//***************************************
#include<SFML/Audio.hpp>
#include<SFML/Graphics.hpp>
#include<SFML/System.hpp>
#include<SFML/Window.hpp>
//***************************************
//	End of include of SFML


//	Include of standart libraries
//		 |
//		 |
//		 V
//****************************************
#include<iostream>    //for tests
#include<ctime>		  //for random events
#include<vector>
#include<utility>
#include<map>
//****************************************

#include"App.h"

using namespace std;
using namespace sf;

class Game:public App {
private:
	
	vector<vector<char>> Field;  //Field of chars to spawn texture on our map
	map<int,pair<pair<int, int>,pair<int, int>>>posible_positions_for_sprite_number; //only for a river
	map<pair<int, int>, int> river_to_render;

	unsigned int gameDifficulty;

	Event ev;

	//Mouse Positions
	Vector2i mousePosWindow;
	Vector2f mousePosView;

	Texture texture_grass, texture_river1, texture_river2, texture_river3, texture_river4,
	texture_river5, texture_river6, texture_mountians, texture_fabric, texture_village, texture_forest;

	Sprite sprite_grass, sprite_river1, sprite_river2, sprite_river3, sprite_river4,
	sprite_river5, sprite_river6, sprite_mountians, sprite_fabric, sprite_village, sprite_forest;

	SoundBuffer bufferGame;
	Sound buttonPressSound;

	struct Industrial {

	};

	struct Village {

	};

public:
	
	void initSpritesVector();    //initialisation of vector with all posible info about sprite
	void initGameFieldMatrix();  //first initialisation of game field
	//*************************   maby next time it will spawn a map using user sizes
	void randomRiverSpawn();
	void randomMountianSpawn();

	void initGameTextures();
	void initGameSprites();
	void initGameClikSound();
	void updateMousePosition(RenderWindow& window);

	void update(RenderWindow& window, Music& music);
	void render(RenderWindow& window);
	void renderSprites(RenderTarget& window);

	void PoolEvents(RenderWindow& window);

	const bool running(RenderWindow& window)const;
	

	Game(RenderWindow* window, unsigned int gameDifficulty);

	Game();

	virtual ~Game();

};