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
#include<sstream>
//****************************************



using namespace std;
using namespace sf;

class MainMenu
{
private:

	//This two will be for user chose for anothers functions
	//   |
	//   V
	unsigned int menu_choise, difficult_choise, music_volume;

	stringstream NewGame, Exit, Rules, Loadgame, Dimas_dudka,RulesMenu,BackButton,
		EasyChoise,NormalChoise,HardChoise,ChoiseMenu,MusicButtonMore,MusicButtonLess,
		MusicShowProzent;

	enum difficultChoise {
		easy,
		normal,
		hard
	};

	enum menuChoise {
		mainmenu,
		difficchoise,
		newgame,
		rules,
		loadgame,
		game, //test for link of menu and the game
		exit
	};

	//RenderWindow* window;
	//VideoMode videoMode;
	Event ev;

	//Mouse Positions
	Vector2i mousePosWindow;
	Vector2f mousePosView;

	//Resources

	//Font font;

	//Text

	Text uiText, newGameText, exitText, loadGameText, rulesText, dimasDudkaText, settingsText,
		rulesMenuText, backButtonText, choiseMenuText, easyButtonText, normalButtonText, hardButtonText,
		musicButtonTextMore, musicButtonTextLess, musicTextShowProzent,musicProzentNumber;

	Texture menu_back_texture;
	//Image icon_texture;
	Sprite menu_back_sprite;
	//Music mainMenuMusic;
	SoundBuffer bufferMenu;
	Sound buttonPressSound;

	float test = 0;

	void initVar();
	void initWindow();

public:

	MainMenu(RenderWindow& window, Music& music,Font& font);

	virtual ~MainMenu();

	//void initFont();
	void initText(Font& font);

	void initMusic();
	void updateMusic(Music &music);

	void initTexture();
	void initSprite();
	void renderSprites(RenderWindow& window);

	void updateMousePos(RenderWindow& window);
	void render(RenderWindow& window);
	void pollEvents(RenderWindow& window);
	void renderTextMainMenu(RenderTarget& target);
	void renderTextRules(RenderTarget& target);
	void renderTextChoise(RenderTarget& target);
	void update(RenderWindow& window,Music &music);
	void updateText(RenderWindow& window);

	unsigned int getDifficulty();

	const bool running(RenderWindow& window)const;
	const bool getExit()const;

	unsigned int getAppNumberStep();

	//void updateAndDrawWindow();

	unsigned int getDificultyChoise();
	unsigned int getAppStatement();

	unsigned int return_menu_choise();

};