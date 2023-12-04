#include"App.h"


void App::initAppIcon(RenderWindow& window)
{
	Image iconApp;
	if (!iconApp.loadFromFile("ICON_TEST.png"))cout << "ERROR::APP::INITTICON::Failed to load icon texture!\n";
	else cout << "INIT APP - ICON TEXTURE - OK\n";
	window.setIcon(100,100,iconApp.getPixelsPtr());
}

void App::initMusicAppBackground(Music& musicApp)
{
	if (!musicApp.openFromFile("ARMEE.flac")) {  //"Armee der Tristen" is a test soundtrack
		cout << "ERROR APP - INIT MUSIC\n";						//becouse i have not another beatiful track
	}														//on my laptop
	else cout << "INIT APP - MUSIC - OK\n";
	musicApp.setVolume(20);
	musicApp.setLoop(true);
	musicApp.play();
}

void App::initMainFont(Font& font)
{
	if (!font.loadFromFile("Deutsch_Gothic.ttf")) {
		cout << "ERROR::APP::INITFONTS::Failed to load font! " << "\n";
	}
	else cout << "INIT APP - FONT - OK\n";
}

const bool App::isAppRunning(RenderWindow& window) const
{
	return window.isOpen();
}

App::App(RenderWindow& window,Music &musicApp, Font& font)
{
	
	initAppIcon(window);
	initMainFont(font);
	initMusicAppBackground(musicApp);
	cout << "INIT APP - APP CLASS - OK\n";
}

App::App(){}

App::~App() {

	cout << "DELETING APP - APP CLASS - OK\n";
}

