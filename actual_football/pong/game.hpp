#ifndef GAME_HPP
#define GAME_HPP

#include <SDL2/SDL.h>
#include <iostream>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include "splashSCreen.hpp"


enum Gamestate{
    splashscreen,
    main_menu,
    Play_now,
    Football_Field,
    Player1,
    Player2,
    Pausemenu,
    GameScreen,
    Goal1,
    Goal2,
    Player1Wins,
    Player2Wins,
    Exit
};
 


using namespace std;
class Game
{
    public:
    //constructor
    Game();
    //destructor
    ~Game();
    bool loadMedia();
    void render();
    void input();
    void update() {};
    void loop();
    
    int GetMouseX();
    int GetMouseY();
    void StopAppLoop();

    private:
     
    SDL_Window* window; 
    bool isGameRunning;
    // TTF_Font* font = TTF_OpenFont("./font/liberation.ttf" , 24);
    int m_mouseX;
    int m_mouseY;
    int key_x = 50;
    int key_y = 50;
    int c_x = 200;
    int c_y = 300;
    int frameNumber = 0;
    bool success = true;

    int count;
    
}


;







#endif