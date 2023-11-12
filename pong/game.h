#ifndef GAME_H
#define GAME_H

#include <SDL2/SDL.h>
#include <iostream>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include "animated_sprite.h"
#include "TexturedRectangle.h"
#include "GameEntity.h"
#include"tile.h"
using namespace std;
class Game
{
    public:
    //constructor
    Game();
    //destructor
    ~Game();

    void render();
    void input();
    void update() {};
    void loop();
    
    int GetMouseX();
    int GetMouseY();
    void StopAppLoop();

    private:
    SDL_Renderer* renderer;
    SDL_Window* window; 
    bool isGameRunning;
    animatedSprite character;
    int m_mouseX;
    int m_mouseY;
    int key_x = 50;
    int key_y = 50;
    int c_x = 200;
    int c_y = 300;
    int frameNumber = 0;
    SDL_Rect Tile_Sets[40][60];
    SDL_Rect Select_tile[40][60];
    
}


;







#endif