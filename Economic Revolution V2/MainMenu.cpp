#include"MainMenu.h"

void MainMenu::initText(Font& font)
{

	//*****************************************************
	//  Buttons settings
	//        |
	//        V
	//*****************************************************

	//New game text settings
	this->newGameText.setFont(font);
	this->newGameText.setCharacterSize(28);
	this->newGameText.setFillColor({ 255,55,50 });

	//Load game text settings
	this->loadGameText.setFont(font);
	this->loadGameText.setCharacterSize(28);
	this->loadGameText.setFillColor({ 255,55,50 });

	//Rules text settings
	this->rulesText.setFont(font);
	this->rulesText.setCharacterSize(28);
	this->rulesText.setFillColor({ 255,55,50 });

	//exit game text settings
	this->exitText.setFont(font);
	this->exitText.setCharacterSize(28);
	this->exitText.setFillColor({ 255,55,50 });

	//back text button settings
	this->backButtonText.setFont(font);
	this->backButtonText.setCharacterSize(30);
	this->backButtonText.setFillColor({ 255,55,50 });

	//easy text button settings
	this->easyButtonText.setFont(font);
	this->easyButtonText.setCharacterSize(40);
	this->easyButtonText.setFillColor({ 255,55,50 });

	//medium text button settings
	this->normalButtonText.setFont(font);
	this->normalButtonText.setCharacterSize(40);
	this->normalButtonText.setFillColor({ 255,55,50 });

	//hard text button settings
	this->hardButtonText.setFont(font);
	this->hardButtonText.setCharacterSize(40);
	this->hardButtonText.setFillColor({ 255,55,50 });

	//Music less button
	this->musicButtonTextLess.setFont(font);
	this->musicButtonTextLess.setCharacterSize(30);
	this->musicButtonTextLess.setFillColor(Color::Yellow);

	//Music more button
	this->musicButtonTextMore.setFont(font);
	this->musicButtonTextMore.setCharacterSize(30);
	this->musicButtonTextMore.setFillColor(Color::Yellow);

	this->musicProzentNumber.setFont(font);
	this->musicProzentNumber.setCharacterSize(30);
	this->musicProzentNumber.setFillColor(Color::Yellow);

	//*****************************************************
	//  Just Text, no buttons
	//        |
	//        V
	//*****************************************************

	//Dimas Dudka text settings
	this->dimasDudkaText.setFont(font);
	this->dimasDudkaText.setCharacterSize(16);
	this->dimasDudkaText.setFillColor({ 255,55,50 });

	//Text of rules in another menu
	this->rulesMenuText.setFont(font);
	this->rulesMenuText.setCharacterSize(20);
	this->rulesMenuText.setFillColor({ 255,55,50 });

	//Text of choise menu
	this->choiseMenuText.setFont(font);
	this->choiseMenuText.setCharacterSize(40);
	this->choiseMenuText.setFillColor({ 255,55,50 });

	//Music Show Prozent text
	this->musicTextShowProzent.setFont(font);
	this->musicTextShowProzent.setCharacterSize(30);
	this->musicTextShowProzent.setFillColor(Color::Yellow);


	cout << "INIT MAIN MENU - TEXT - OK\n";
}

void MainMenu::initMusic()    
{
	//Must be background soundtrack
	//and music to mouse click on button

	if (!this->bufferMenu.loadFromFile("sound/BUTTON.wav")) {
		cout << "ERROR MAIN MENU - INIT BUTTON SOUND\n";
	}
	else {
		cout<< "INIT MAIN MENU - BUTTON SOUND - OK\n";
		this->buttonPressSound.setBuffer(this->bufferMenu);
	}

	//Background music settings
	//this->mainMenuMusic.setVolume(this->music_volume);
	//this->mainMenuMusic.setLoop(true);
	//this->mainMenuMusic.play();

	//Button sound settings
	this->buttonPressSound.setVolume(15);
}

void MainMenu::updateMusic(Music &music)
{
	//set music volume to our music
	music.setVolume(this->music_volume);
}

void MainMenu::initTexture()
{
	//Background texture

	if (!this->menu_back_texture.loadFromFile("textures/TEST_MENU.jpg")) {
		cout << "ERROR::MAINMENU::INITTEXTURE::Failed to load texture!\n";
	}
	else cout << "INIT MAIN MENU - BACKGROUNG TEXTURE - OK\n";
	
}

void MainMenu::initSprite()
{
	//Spreite for main menu baackground
	this->menu_back_sprite.setTexture(this->menu_back_texture);
	cout << "INIT MAIN MENU - SPRITE - OK\n";
}

void MainMenu::initVar()
{
	//this->window = nullptr;

	//Default Settings for a game and the start of the game
	this->menu_choise = this->mainmenu;
	this->music_volume = 20;


	//Buttons Text info
	this->NewGame << "New Game";
	this->Loadgame << "Load Game";
	this->Rules << "Rules";
	this->Exit << "Exit";
	this->BackButton << "Back";
	this->EasyChoise << "Easy";
	this->NormalChoise << "Medium";
	this->HardChoise << "Hard";

	//Music Settings
	this->MusicButtonMore << "More";
	this->MusicButtonLess << "Less";

	//Just text info
	this->Dimas_dudka << "Economic Revolution 2     v 0.1 power by Dimas_Dudka";
	this->RulesMenu << "There are rules of a Economoc Revolutin 2\n";
	this->RulesMenu << "But rules will be after making all game logic";
	this->ChoiseMenu << "Choose the difficulty of the game:";

	//Enter into text Varibales stringstream
	this->newGameText.setString( this->NewGame.str());
	this->loadGameText.setString(this->Loadgame.str());
	this->rulesText.setString(this->Rules.str());
	this->exitText.setString(this->Exit.str());
	this->backButtonText.setString(this->BackButton.str());
	this->easyButtonText.setString(this->EasyChoise.str());
	this->normalButtonText.setString(this->NormalChoise.str());
	this->hardButtonText.setString(this->HardChoise.str());
	this->musicButtonTextLess.setString(this->MusicButtonLess.str());
	this->musicButtonTextMore.setString(this->MusicButtonMore.str());

	//Just text
	this->rulesMenuText.setString(this->RulesMenu.str());
	this->dimasDudkaText.setString(this->Dimas_dudka.str());
	this->choiseMenuText.setString(this->ChoiseMenu.str());
	this->musicTextShowProzent.setString(this->MusicShowProzent.str());

	cout << "INIT MAIN MENU - VARIBALS - OK\n";
}

void MainMenu::initWindow() {

	//Test variant for V0.1
	//this->videoMode.width = 1280;
	//this->videoMode.height = 720;
	//In Future it will be resizefull
	//this->window = new RenderWindow(this->videoMode, "ECONOMIC REVOLUTION 2",
	//	Style::Titlebar | Style::Close);

	//Seting icon and title
	//this->window->setTitle("ECONOMIC REVOLUTION 2");
	//this->window->setIcon(100, 100, this->icon_texture.getPixelsPtr());

	//Default setting, but it can be changefull in settings menu
	//this->window->setFramerateLimit(60);
	cout << "INIT MAIN MENU - WINDOW - OK\n";
}

void MainMenu::renderSprites(RenderWindow& window)
{
	//render menu background like a sprite
	window.draw(this->menu_back_sprite);
}

void MainMenu::render(RenderWindow& window) {

	window.clear();

	//render section
	//  |
	//  |
	//  V
	this->renderSprites(window);  //Now it is only for menu background
	if (this->menu_choise == this->mainmenu) {
		this->renderTextMainMenu(window);
		//end of render section
	}
	else if (this->menu_choise == this->rules) {
		this->renderTextRules(window);
	}
	else if (this->menu_choise == this->newgame) {
		this->renderTextChoise(window);
	}
	window.display();

}

void MainMenu::renderTextMainMenu(RenderTarget& target)
{
	//render all buttons and textes on main menu
	target.draw(this->newGameText);
	target.draw(this->loadGameText);
	target.draw(this->rulesText);
	target.draw(this->exitText);
	target.draw(this->dimasDudkaText);
	target.draw(this->musicButtonTextLess);
	target.draw(this->musicTextShowProzent);
	target.draw(this->musicButtonTextMore);
}

void MainMenu::renderTextRules(RenderTarget& target) {
	//render all for a rules menu
	target.draw(this->dimasDudkaText);
	target.draw(this->backButtonText);
	target.draw(this->rulesMenuText);
}

void MainMenu::renderTextChoise(RenderTarget& target)
{
	//render all for a difficulty choise menu
	target.draw(this->choiseMenuText);
	target.draw(this->easyButtonText);
	target.draw(this->normalButtonText);
	target.draw(this->hardButtonText);
	target.draw(this->backButtonText);
	target.draw(this->dimasDudkaText);
}

void MainMenu::updateMousePos(RenderWindow& window)
{
	//updating mouse position
	this->mousePosWindow = Mouse::getPosition(window);
	this->mousePosView = window.mapPixelToCoords(this->mousePosWindow);

	//only for debuging
	//  |
	//  V
	//cout << "x = " << this->mousePosWindow.x << "   y = " << this->mousePosWindow.y << endl;
}

void MainMenu::pollEvents(RenderWindow& window)
{
	//This function proff all events that can be happend in main menu 
	//and in all not game windows
	while (window.pollEvent(this->ev)) {
		switch (this->ev.type){
		//***********************
		//Exit proof
		//	 |
		//	 V
		//***********************
		case Event::Closed: {
			window.close();
			break;
		}
		case Event::KeyPressed: {
			if (this->ev.key.code == Keyboard::Escape) {
				window.close();break;
			}
			break;
		}

		//***********************************
		//Buttons updating
		//		|
		//		V
		//***********************************
		case Event::MouseButtonPressed: {

			//Exit Button choise
			if (this->ev.mouseButton.button == Mouse::Left&&
				this->exitText.getGlobalBounds().contains(this->mousePosView.x, this->mousePosView.y)) {
					this->buttonPressSound.play();
					this->menu_choise = this->exit;
			}

			//New game button choise
			else if (this->ev.mouseButton.button == Mouse::Left &&
				this->newGameText.getGlobalBounds().contains(this->mousePosView.x, this->mousePosView.y)) {
				this->buttonPressSound.play();
				this->menu_choise = this->newgame;
			}

			//Rules button choise
			else if (this->ev.mouseButton.button == Mouse::Left &&
				this->rulesText.getGlobalBounds().contains(this->mousePosView.x, this->mousePosView.y)) {
				this->buttonPressSound.play();
				this->menu_choise = this->rules;
			}

			//Back button choise
			else if (this->ev.mouseButton.button == Mouse::Left &&
				this->backButtonText.getGlobalBounds().contains(this->mousePosView.x, this->mousePosView.y)) {
				this->buttonPressSound.play();
				this->menu_choise = this->mainmenu;
			}
			//More Music button
			else if (this->ev.mouseButton.button == Mouse::Left &&
				this->musicButtonTextMore.getGlobalBounds().contains(this->mousePosView.x, this->mousePosView.y)&&
				this->music_volume<100) {
				this->buttonPressSound.play();
				this->music_volume += 10;
			}

			//Less Music button
			else if (this->ev.mouseButton.button == Mouse::Left &&
				this->musicButtonTextLess.getGlobalBounds().contains(this->mousePosView.x, this->mousePosView.y) &&
				this->music_volume > 0) {
				this->buttonPressSound.play();
				this->music_volume -= 10;
				
			}

			//*****************************************************
			//Dificulty choises buttons
			//			|
			//			V
			//*****************************************************

			//Easy button choise
			else if (this->ev.mouseButton.button == Mouse::Left &&
				this->easyButtonText.getGlobalBounds().contains(this->mousePosView.x, this->mousePosView.y)) {
				this->buttonPressSound.play();
				this->difficult_choise = this->easy;
				this->menu_choise = game;
			}

			//Normal button choise
			else if (this->ev.mouseButton.button == Mouse::Left &&
				this->normalButtonText.getGlobalBounds().contains(this->mousePosView.x, this->mousePosView.y)) {
				this->buttonPressSound.play();
				this->difficult_choise = this->normal;
				this->menu_choise = game;
			}

			//Hard button choise
			else if (this->ev.mouseButton.button == Mouse::Left &&
				this->hardButtonText.getGlobalBounds().contains(this->mousePosView.x, this->mousePosView.y)) {
				this->buttonPressSound.play();
				this->difficult_choise = this->hard;
				this->menu_choise = game;
			}

			break;
		}
	  }
	}
}

void MainMenu::update(RenderWindow &window, Music &music)
{
	//updating window 
	window.clear();
	this->pollEvents(window);
	if (this->menu_choise != this->exit) {
		this->updateMousePos(window);
		this->updateText(window);
		this->updateMusic(music);
	}
}

void MainMenu::updateText(RenderWindow& window)
{
	//window sizes
	float WINDOW_X = window.getSize().x;
	float WINDOW_Y = window.getSize().y;

	//Menu Text Positions
	this->newGameText.setPosition(WINDOW_X - 300, WINDOW_Y - 450);
	this->loadGameText.setPosition(WINDOW_X - 300, WINDOW_Y - 400);
	this->rulesText.setPosition(WINDOW_X - 300, WINDOW_Y - 350);
	this->exitText.setPosition(WINDOW_X - 300, WINDOW_Y - 300);

	this->dimasDudkaText.setPosition((WINDOW_X*35)/100, WINDOW_Y-50);

	//Rules Menu Text Positions
	this->rulesMenuText.setPosition(WINDOW_X - 600, WINDOW_Y - ((WINDOW_Y *3)/ 4));
	if(this->menu_choise==this->rules)
		this->backButtonText.setPosition(WINDOW_X-((WINDOW_X)/4),WINDOW_Y - 90);
	else if (this->menu_choise == this->newgame) {
		this->backButtonText.setPosition((WINDOW_X * 45) / 100, (WINDOW_Y * 75) / 100);
	}
	
	//Choise Menu Text Positions
	this->choiseMenuText.setPosition((WINDOW_X*25)/100,(WINDOW_Y*25)/100);
	this->easyButtonText.setPosition((WINDOW_X * 45) / 100, (WINDOW_Y * 35) / 100);
	this->normalButtonText.setPosition((WINDOW_X * 45) / 100, (WINDOW_Y * 45) / 100);
	this->hardButtonText.setPosition((WINDOW_X * 45) / 100, (WINDOW_Y * 55) / 100);

	//Music Settings Position
	this->musicButtonTextLess.setPosition((WINDOW_X * 75) / 100, (WINDOW_Y * 90) / 100);
	this->musicTextShowProzent.setPosition((WINDOW_X * 81) / 100, (WINDOW_Y * 90) / 100);
	this->musicButtonTextMore.setPosition((WINDOW_X * 88) / 100, (WINDOW_Y * 90) / 100);

	//Text updating if mouse is on the text
	//Setting another color for a text
	if (this->newGameText.getGlobalBounds().contains(this->mousePosView.x,this->mousePosView.y)) {
		this->newGameText.setFillColor({ 255,150,50 });
	}
	else this->newGameText.setFillColor({ 255,55,50 });
	
	if (this->loadGameText.getGlobalBounds().contains(this->mousePosView.x, this->mousePosView.y)) {
		this->loadGameText.setFillColor({ 255,150,50 });
	}
	else this->loadGameText.setFillColor({ 255,55,50 });

	if (this->rulesText.getGlobalBounds().contains(this->mousePosView.x, this->mousePosView.y)) {
		this->rulesText.setFillColor({ 255,150,50 });
	}
	else this->rulesText.setFillColor({ 255,55,50 });

	if (this->exitText.getGlobalBounds().contains(this->mousePosView.x, this->mousePosView.y)) {
		this->exitText.setFillColor({ 255,150,50 });
	}
	else this->exitText.setFillColor({ 255,55,50 });

	if (this->backButtonText.getGlobalBounds().contains(this->mousePosView.x, this->mousePosView.y)) {
		this->backButtonText.setFillColor({ 255,150,50 });
	}
	else this->backButtonText.setFillColor({ 255,55,50 });

	if (this->easyButtonText.getGlobalBounds().contains(this->mousePosView.x, this->mousePosView.y)) {
		this->easyButtonText.setFillColor({ 255,150,50 });
	}
	else this->easyButtonText.setFillColor({ 255,55,50 });

	if (this->normalButtonText.getGlobalBounds().contains(this->mousePosView.x, this->mousePosView.y)) {
		this->normalButtonText.setFillColor({ 255,150,50 });
	}
	else this->normalButtonText.setFillColor({ 255,55,50 });

	if (this->hardButtonText.getGlobalBounds().contains(this->mousePosView.x, this->mousePosView.y)) {
		this->hardButtonText.setFillColor({ 255,150,50 });
	}
	else this->hardButtonText.setFillColor({ 255,55,50 });

	//Music Buttons Position
	//Button Less
	if (this->musicButtonTextLess.getGlobalBounds().contains(this->mousePosView.x, this->mousePosView.y)) {
		this->musicButtonTextLess.setFillColor({ 255,255,204 });
	}
	else this->musicButtonTextLess.setFillColor(Color::Yellow);

	//Button More
	if (this->musicButtonTextMore.getGlobalBounds().contains(this->mousePosView.x, this->mousePosView.y)) {
		this->musicButtonTextMore.setFillColor({ 255,255,204 });
	}
	else this->musicButtonTextMore.setFillColor(Color::Yellow);

	//Show the Prozent of Music power
	stringstream ss;
	ss << " " << this->music_volume << " % ";
	this->musicTextShowProzent.setString(ss.str());

}

unsigned int MainMenu::getDifficulty()
{
	return this->difficult_choise;
}

const bool MainMenu::running(RenderWindow &window) const
{
	return window.isOpen();
}

const bool MainMenu::getExit() const
{
	return this->menu_choise!=this->exit? true:false;
}

unsigned int MainMenu::getAppNumberStep()
{
	if (this->menu_choise == this->exit)
		return 2;
	else return 0;
}

unsigned int MainMenu::getDificultyChoise()
{
	//for set difficulty choise in class Game
	return this->difficult_choise;
}

unsigned int MainMenu::getAppStatement()
{
	return this->menu_choise;
}

unsigned int MainMenu::return_menu_choise()
{
	return this->menu_choise;
}

MainMenu::MainMenu(RenderWindow &window,Music &music,Font& font) {

	//Initialisation of all parameters that needs to start the game(main menu)

	this->initVar();
	this->initTexture();
	this->initWindow();
	//this->initFont();
	this->initText(font);
	this->initSprite();
	this->initMusic();
}

MainMenu::~MainMenu()
{
	//all anothers parameters will be deleted when there are out from functions

	//delete this->window;
	cout << "DELETE MAIN MENU - WINDOW - OK\n";
}