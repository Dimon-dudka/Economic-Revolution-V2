#include"Game.h"

#include<random>

void Game::initGameFieldMatrix()
{
	size_t n = 10;
	this->Field.resize(n);
	for (size_t i = 0; i < n; ++i) {
		this->Field.at(i).resize(n);
	}
	for (size_t i = 0; i < n; ++i) {
		for (size_t j = 0; j < n; ++j) this->Field.at(i).at(j) = '-';
	}
	cout << "INIT GAME - FIELD - OK\n";

	//	test mechanik (filling map river_to_render with number 0, where 0 is a grass)
	//	1-6 = wather sprites number
	//	0 - grass number
	//	10 - mountin number

	for (size_t i = 0; i < n; ++i) {
		for (size_t j = 0; j < n; ++j) {
			river_to_render[{i, j}] = 0;
		}
	}
	
}

void Game::randomRiverSpawn()
{
	srand(time(NULL));
	//Random river spawn

	//river must be spawned as first!!!

	//this is choise between x or y side to start spawn a river
	enum XYposition {
		X,
		Y
	};

	int x,y, //		<--- Watchings x/y var
		sprite_number, tmp, tmpChoise = rand() % 2;


	//spawn of first river sprite, that didnt depense from all another spawn logic
	//	|
	//	V
	if (tmpChoise == X) {
		x = rand() % this->Field.size();
		y = 0;
		sprite_number = (rand() % 3) + 1;
		if (sprite_number == 1) {
			sprite_number = 2;
			cout << "OK\n";
		}
		else if (sprite_number == 2) {
			sprite_number = 4;
			cout << "OK\n";
		}
		else if (sprite_number == 3) {
			sprite_number = 5;
			cout << "OK\n";
		}
	}
	else if (tmpChoise == Y) {
		y = rand() % this->Field.size();
		x = 0;
		sprite_number = (rand() % 3) + 1;
		if (sprite_number == 1) {
			sprite_number = 1;
			cout << "OK\n";
		}
		else if (sprite_number == 2) {
			sprite_number = 2;
			cout << "OK\n";
		}
		else if (sprite_number == 3) {
			sprite_number = 3;
			cout << "OK\n";
		}
	}
	else cout << "ERROR::GAME::FILLINGGAMEFIELD\n";
	//	^
	//	|
	//This logic was checked,all is fine

	//spawn and enter the data into our bank about the first river point
	this->Field.at(x).at(y) = 'r';
	
	this->river_to_render[{x, y}] = sprite_number;
	
	cout << x << " " << y << ": " << sprite_number << endl;

	int x_tmp, y_tmp,random,n=this->Field.size();
	bool flag = true;				//flag 

	//while we are on the field we can spawn a river
	while (x >= 0 && x < n && y >= 0 && y < n&&flag) {

		switch (sprite_number) {

		case 1: {

			x_tmp = x + posible_positions_for_sprite_number[1].first.first;
			y_tmp = y + posible_positions_for_sprite_number[1].first.second;

			if (x_tmp >= 0 && x_tmp < n && y_tmp >= 0 && y_tmp < n && this->Field.at(x_tmp).at(y_tmp) == '-') {

				random = rand() % 5 + 1;
				switch (random) {

				case 1:
					sprite_number = 1;
					break;
				case 2:
					sprite_number = 1;
					break;
				case 3:
					sprite_number = 2;
					break;
				case 4:
					sprite_number = 1;
					break;
				case 5:
					sprite_number = 3;
					break;

				}

			}
			else {
				x_tmp = x + posible_positions_for_sprite_number[1].second.first;
				y_tmp = y + posible_positions_for_sprite_number[1].second.second;

				if (x_tmp >= 0 && x_tmp < n && y_tmp >= 0 && y_tmp < n && this->Field.at(x_tmp).at(y_tmp) == '-') {

					random = rand() % 5 + 1;
					switch (random) {

					case 1:
						sprite_number = 1;
						break;
					case 2:
						sprite_number = 5;
						break;
					case 3:
						sprite_number = 6;
						break;
					case 4:
						sprite_number = 1;
						break;
					case 5:
						sprite_number = 1;
						break;
					}

				}
				else flag = false;
			}
			if (flag != false) {
				x = x_tmp;
				y = y_tmp;
				this->Field.at(x).at(y) = 'r';
				this->river_to_render[{x, y}] = sprite_number;
			}
			break;
			}
		case 2: {

			x_tmp = x + posible_positions_for_sprite_number[2].first.first;
			y_tmp = y + posible_positions_for_sprite_number[2].first.second;

			if (x_tmp >= 0 && x_tmp < n && y_tmp >= 0 && y_tmp < n && this->Field.at(x_tmp).at(y_tmp) == '-') {

				random = rand() % 5 + 1;
				switch (random) {

				case 1:
					sprite_number = 3;
					break;
				case 2:
					sprite_number = 4;
					break;
				case 3:
					sprite_number = 4;
					break;
				case 4:
					sprite_number = 6;
					break;
				case 5:
					sprite_number = 4;
					break;
				}

			}
			else {
				x_tmp = x + posible_positions_for_sprite_number[2].second.first;
				y_tmp = y + posible_positions_for_sprite_number[2].second.second;

				if (x_tmp >= 0 && x_tmp < n && y_tmp >= 0 && y_tmp < n && this->Field.at(x_tmp).at(y_tmp) == '-') {

					random = rand() % 5 + 1;
					switch (random) {

					case 1:
						sprite_number = 1;
						break;
					case 2:
						sprite_number = 1;
						break;
					case 3:
						sprite_number = 5;
						break;
					case 4:
						sprite_number = 6;
						break;
					case 5:
						sprite_number = 1;
						break;
					}

				}
				else flag = false;
			}
			if (flag != false) {
				x = x_tmp;
				y = y_tmp;
				this->Field.at(x).at(y) = 'r';
				this->river_to_render[{x, y}] = sprite_number;
			}

			break;
		}
		case 3: {

			x_tmp = x + posible_positions_for_sprite_number[3].first.first;
			y_tmp = y + posible_positions_for_sprite_number[3].first.second;

			if (x_tmp >= 0 && x_tmp < n && y_tmp >= 0 && y_tmp < n && this->Field.at(x_tmp).at(y_tmp) == '-') {

				random = rand() % 5 + 1;
				switch (random) {

				case 1:
					sprite_number = 2;
					break;
				case 2:
					sprite_number = 4;
					break;
				case 3:
					sprite_number = 5;
					break;
				case 4:
					sprite_number = 4;
					break;
				case 5:
					sprite_number = 4;
					break;

				}

			}
			else {
				x_tmp = x + posible_positions_for_sprite_number[3].second.first;
				y_tmp = y + posible_positions_for_sprite_number[3].second.second;

				if (x_tmp >= 0 && x_tmp < n && y_tmp >= 0 && y_tmp < n && this->Field.at(x_tmp).at(y_tmp) == '-') {

					random = rand() % 5 + 1;
					switch (random) {

					case 1:
						sprite_number = 1;
						break;
					case 2:
						sprite_number = 5;
						break;
					case 3:
						sprite_number = 6;
						break;
					case 4:
						sprite_number = 1;
						break;
					case 5:
						sprite_number = 1;
						break;
					}

				}
				else flag = false;
			}
			if (flag != false) {
				x = x_tmp;
				y = y_tmp;
				this->Field.at(x).at(y) = 'r';
				this->river_to_render[{x, y}] = sprite_number;
			}

			break;
		}
		case 4: {

			x_tmp = x + posible_positions_for_sprite_number[4].first.first;
			y_tmp = y + posible_positions_for_sprite_number[4].first.second;

			if (x_tmp >= 0 && x_tmp < n && y_tmp >= 0 && y_tmp < n && this->Field.at(x_tmp).at(y_tmp) == '-') {

				random = rand() % 5 + 1;
				switch (random) {

				case 1:
					sprite_number = 2;
					break;
				case 2:
					sprite_number = 4;
					break;
				case 3:
					sprite_number = 5;
					break;
				case 4:
					sprite_number = 4;
					break;
				case 5:
					sprite_number = 4;
					break;
				}

			}
			else {
				x_tmp = x + posible_positions_for_sprite_number[4].second.first;
				y_tmp = y + posible_positions_for_sprite_number[4].second.second;

				if (x_tmp >= 0 && x_tmp < n && y_tmp >= 0 && y_tmp < n && this->Field.at(x_tmp).at(y_tmp) == '-') {

					random = rand() % 5 + 1;
					switch (random) {

					case 1:
						sprite_number = 3;
						break;
					case 2:
						sprite_number = 4;
						break;
					case 3:
						sprite_number = 6;
						break;
					case 4:
						sprite_number = 4;
						break;
					case 5:
						sprite_number = 4;
						break;
					}

				}
				else flag = false;
			}
			if (flag != false) {
				x = x_tmp;
				y = y_tmp;
				this->Field.at(x).at(y) = 'r';
				this->river_to_render[{x, y}] = sprite_number;
			}

			break;
		}
		case 5: {

			x_tmp = x + posible_positions_for_sprite_number[5].first.first;
			y_tmp = y + posible_positions_for_sprite_number[5].first.second;

			if (x_tmp >= 0 && x_tmp < n && y_tmp >= 0 && y_tmp < n && this->Field.at(x_tmp).at(y_tmp) == '-') {

				random = rand() % 5 + 1;
				switch (random) {

				case 1:
					sprite_number = 1;
					break;
				case 2:
					sprite_number = 2;
					break;
				case 3:
					sprite_number = 3;
					break;
				case 4:
					sprite_number = 1;
					break;
				case 5:
					sprite_number = 1;
					break;
				}

			}
			else {
				x_tmp = x + posible_positions_for_sprite_number[5].second.first;
				y_tmp = y + posible_positions_for_sprite_number[5].second.second;

				if (x_tmp >= 0 && x_tmp < n && y_tmp >= 0 && y_tmp < n && this->Field.at(x_tmp).at(y_tmp) == '-') {

					random = rand() % 5 + 1;
					switch (random) {

					case 1:
						sprite_number = 3;
						break;
					case 2:
						sprite_number = 4;
						break;
					case 3:
						sprite_number = 6;
						break;
					case 4:
						sprite_number = 4;
						break;
					case 5:
						sprite_number = 4;
						break;
					}

				}
				else flag = false;
			}
			if (flag != false) {
				x = x_tmp;
				y = y_tmp;
				this->Field.at(x).at(y) = 'r';
				this->river_to_render[{x, y}] = sprite_number;
			}

			break;
		}
		case 6: {

			x_tmp = x + posible_positions_for_sprite_number[6].first.first;
			y_tmp = y + posible_positions_for_sprite_number[6].first.second;

			if (x_tmp >= 0 && x_tmp < n && y_tmp >= 0 && y_tmp < n && this->Field.at(x_tmp).at(y_tmp) == '-') {

				random = rand() % 5 + 1;
				switch (random) {

				case 1:
					sprite_number = 1;
					break;
				case 2:
					sprite_number = 2;
					break;
				case 3:
					sprite_number = 3;
					break;
				case 4:
					sprite_number = 1;
					break;
				case 5:
					sprite_number = 1;
					break;
				}

			}
			else {
				x_tmp = x + posible_positions_for_sprite_number[6].second.first;
				y_tmp = y + posible_positions_for_sprite_number[6].second.second;

				if (x_tmp >= 0 && x_tmp < n && y_tmp >= 0 && y_tmp < n && this->Field.at(x_tmp).at(y_tmp) == '-') {

					random = rand() % 5 + 1;
					switch (random) {

					case 1:
						sprite_number = 2;
						break;
					case 2:
						sprite_number = 4;
						break;
					case 3:
						sprite_number = 5;
						break;
					case 4:
						sprite_number = 4;
						break;
					case 5:
						sprite_number = 4;
						break;
					}

				}
				else flag = false;
			}
			if (flag != false) {
				x = x_tmp;
				y = y_tmp;
				this->Field.at(x).at(y) = 'r';
				this->river_to_render[{x, y}] = sprite_number;
			}

			break;
		}

		}
		cout << x << " " << y << ": " << sprite_number << endl;

	}


	for (const auto& w : this->Field) {
		for (const auto& s : w) {
			cout << s << " ";
		}
		cout << endl;
	}
	cout << "****************************************\n";

	//	Testing positions and type of a river
	/*
	for (const auto& w : this->river_to_render) {
		if (w.second != 10) {
			cout << w.first.first << " " << w.first.second << ": " << w.second << endl;
		}
	}
	*/
	
}

void Game::randomMountianSpawn()
{

	int map_square = this->Field.size() * this->Field.size();

	int ten_prozent_of_square = map_square / 10;// 10%	must be selected by using some balance tests

	int count_of_mountian= rand() % ten_prozent_of_square;

	if (count_of_mountian != 0) {

		int random_corner_selection = rand() % 4 + 1; //	where 1 - top left
													  //	2 - top right
													  //	3 - bottom left
													  //	4 - bottom right

		switch (random_corner_selection)
		{
		case 1:

			while (count_of_mountian != 0) {



				--count_of_mountian;
			}

			break;
		case 2:



			break;
		case 3:



			break;
		case 4:



			break;


		default:
			break;
		}


	}

}

void Game::initGameTextures()
{
	//initialisation of all textures in the game
	//Was checked on 24.01.2023
	if (!this->texture_grass.loadFromFile("grass.png") && !this->texture_river1.loadFromFile("river_1")&&
		!this->texture_river2.loadFromFile("river_2")&& !this->texture_river3.loadFromFile("river_3")
		&&!this->texture_river4.loadFromFile("river_4")&& !this->texture_river5.loadFromFile("river_5")&&
		!this->texture_river6.loadFromFile("river_6")) {
		cout << "ERROR::GAME::INITTEXTURE::Failed to load texture!\n";
	}
	else {
		cout << "INIT GAME - TEXTURE - OK\n";
	}
}

void Game::initGameSprites()
{

	//initialisation sprites

	this->sprite_grass.setTexture(this->texture_grass);
	this->sprite_river1.setTexture(this->texture_river1);
	this->sprite_river2.setTexture(this->texture_river2);
	this->sprite_river3.setTexture(this->texture_river3);
	this->sprite_river4.setTexture(this->texture_river4);
	this->sprite_river5.setTexture(this->texture_river5);
	this->sprite_river6.setTexture(this->texture_river6);
	
	cout << "INIT GAME - SPRITES - OK\n";
}

void Game::initGameClikSound()
{
	//init of all !GAME! Sounds and music
	if (!this->bufferGame.loadFromFile("BUTTON.wav")) {
		cout << "ERROR MAIN MENU - INIT BUTTON SOUND\n";
	}
	else {
		cout << "INIT MAIN MENU - BUTTON SOUND - OK\n";
		this->buttonPressSound.setBuffer(this->bufferGame);
	}
}

void Game::updateMousePosition(RenderWindow& window)
{
	//updating mouse position
	this->mousePosWindow = Mouse::getPosition(window);
	this->mousePosView = window.mapPixelToCoords(this->mousePosWindow);
}

void Game::update(RenderWindow& window, Music& music)
{
	//updating window 
	window.clear();
	//this->pollEvents(window);
	cout << "UPDATE SPRITES - OK\n";
}

void Game::render(RenderWindow& window)
{
	window.clear();

	//render section
	//  |
	//  |
	//  V
	this->renderSprites(window);  //Now it is only for menu background
	
	window.display();
	cout << "RENDER WINDOW - OK\n";
}

void Game::renderSprites(RenderTarget& window)
{
	size_t field_size = this->Field.size();

	for (size_t i = 0; i < field_size; ++i) {
		for (size_t j = 0; j < field_size; ++j) {

			switch (river_to_render[{i, j}]) {
			case 0:
				this->sprite_grass.setPosition(i * 100, j * 100);
				window.draw(this->sprite_grass);
				break;
			case 1:
				this->sprite_river1.setPosition(i * 100, j * 100);
				window.draw(this->sprite_river1);
				break;
			case 2:
				this->sprite_river2.setPosition(i * 100, j * 100);
				window.draw(this->sprite_river2);
				break;
			case 3:
				this->sprite_river3.setPosition(i * 100, j * 100);
				window.draw(this->sprite_river3);
				break;
			case 4:
				this->sprite_river4.setPosition(i * 100, j * 100);
				window.draw(this->sprite_river4);
				break;
			case 5:
				this->sprite_river5.setPosition(i * 100, j * 100);
				window.draw(this->sprite_river5);
				break;
			case 6:
				this->sprite_river6.setPosition(i * 100, j * 100);
				window.draw(this->sprite_river6);
				break;
			}
			

		}
	}
	cout << "RENDER SPRITES - OK\n";
}

const bool Game::running(RenderWindow& window) const
{
	return window.isOpen();
}

/*
Game::Game(RenderWindow* window, unsigned int gameDifficulty)
{
	//Map of all posible position dx,dy for everyone river sprite
	this->posible_positions_for_sprite_number[1] = make_pair(make_pair(-1, 0), make_pair(1, 0));
	this->posible_positions_for_sprite_number[2] = make_pair(make_pair(-1, 0), make_pair(0, -1));
	this->posible_positions_for_sprite_number[3] = make_pair(make_pair(-1, 0), make_pair(0, 1));
	this->posible_positions_for_sprite_number[4] = make_pair(make_pair(0, -1), make_pair(0, 1));
	this->posible_positions_for_sprite_number[5] = make_pair(make_pair(0, -1), make_pair(1, 0));
	this->posible_positions_for_sprite_number[6] = make_pair(make_pair(1, 0), make_pair(0, 1));

	for (const auto& w : posible_positions_for_sprite_number) {
		cout << w.first << ": " << w.second.first.second << ", " << w.second.first.first << "; " << w.second.second.second << ", " << w.second.second.first << endl;
	}

	this->initGameFieldMatrix();
	this->randomFillingGameField();

}
*/

Game::Game()
{
	//		Checked on 24.01.2023
	//				|
	//				V
	//																   x   y             x  y
	this->posible_positions_for_sprite_number[1] = make_pair(make_pair(1, 0), make_pair(-1, 0));
	this->posible_positions_for_sprite_number[2] = make_pair(make_pair(0, -1), make_pair(-1, 0));
	this->posible_positions_for_sprite_number[3] = make_pair(make_pair(0, 1), make_pair(-1, 0));
	this->posible_positions_for_sprite_number[4] = make_pair(make_pair(0, 1), make_pair(0, -1));
	this->posible_positions_for_sprite_number[5] = make_pair(make_pair(1, 0), make_pair(0, -1));
	this->posible_positions_for_sprite_number[6] = make_pair(make_pair(1, 0), make_pair(0, 1));

	this->initGameFieldMatrix();
	this->randomRiverSpawn();

	//this->randomMountianSpawn();
	
}

Game::~Game()
{
	this->posible_positions_for_sprite_number.clear();
	cout << "DELETE GAME - FIELDS - OK\n";
}
