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
//****************************************

using namespace sf;
using namespace std;

class App {
private:

	//void initAppWindow(RenderWindow &window, VideoMode& videomode);

	void initAppIcon(RenderWindow& window);
	void initMusicAppBackground(Music& musicApp);
	void initMainFont(Font& font);
	
public:

	const bool isAppRunning(RenderWindow& window)const;

	App(RenderWindow &window,Music &musicApp,Font &font);
	App();
	virtual ~App();
	
};