#ifndef ANIMATED_SPRITE_H
#define ANIMATED_SPRITE_H

#include <SDL2/SDL.h>
#include <iostream>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
using namespace std;

class animatedSprite
{
    public:
     
     
     void animated(SDL_Renderer* renderer , string filename); // constructor

    //destructor
    ~animatedSprite();

    void draw(int x , int y , int w , int h);
    void playFrame(int x , int  y , int  w , int h , int frameNumber);

    void updateAnimation(SDL_Renderer* renderer);

    private:
    SDL_Rect src;
    SDL_Rect dest;
    SDL_Texture* texture;
    int frameNumber = 0;
}





;




#endif