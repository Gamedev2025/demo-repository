#ifndef GAME_HPP
#define GAME_HPP

#include <SDL2/SDL.h>
#include <iostream>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>



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
    TTF_Font* font;
    int m_mouseX;
    int m_mouseY;
    int key_x = 50;
    int key_y = 50;
    int c_x = 200;
    int c_y = 300;
    int frameNumber = 0;
    
    
}


;







#endif