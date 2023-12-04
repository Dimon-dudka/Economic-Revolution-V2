#pragma once

#include"App.h"
#include"Game.h"
#include"MainMenu.h"

#include<SFML/Audio.hpp>
#include<SFML/Graphics.hpp>
#include<SFML/System.hpp>
#include<SFML/Window.hpp>



int main()
{
    srand(static_cast <unsigned>(time(NULL)));
    
    //MainMenu menu;
    
    /*
    while (menu.running()  && menu.getExit()) {
       
            //menu.update();

            //menu.render();

            //menu.updateAndDrawWindow();
      
    }
    */

    //New realisation of architekturs of a game
    //      |
    //      V
    
    // Starting parameters without them can not work
    Music backgroundMusic;
    Image iconApp;
    RenderWindow *windowMain;
    VideoMode videoMode;
    Font fontMain;

    enum AppStep {
        MENU,
        GAME,
        EXIT
    };
    windowMain = nullptr;

    videoMode.height = 720;
    videoMode.width = 1280;
   
    windowMain = new RenderWindow(videoMode, "ECONOMIC REVOLUTION 2",
        Style::Titlebar | Style::Close);

    unsigned int whatStep = MENU;
    //unsigned int whatStep = GAME;
    

    App app(*windowMain,backgroundMusic,fontMain);
    MainMenu menu(*windowMain, backgroundMusic, fontMain);

    Game game;

   


    while (app.isAppRunning(*windowMain)&&whatStep!=EXIT) {

        if (whatStep == MENU) {
            while (menu.running(*windowMain) ) {
                if (menu.getAppNumberStep() != EXIT) {
                    if (menu.return_menu_choise() == 5) {
                        whatStep = GAME;
                    }
                    else {
                        menu.update(*windowMain, backgroundMusic);

                        menu.render(*windowMain);
                    }
                }
                else if(menu.getAppNumberStep() == EXIT) {
                    windowMain->close();
                }
                
            }

        }
        else {
            //else if (whatStep == GAME) {

            while (game.running(*windowMain)) {
                game.update(*windowMain, backgroundMusic);

                game.render(*windowMain);
            }

        }
       // }
       
    }

    windowMain->close();
    cout << "MAIN APP - WINDOW - CLOSE - OK\n";
    return 0;
}