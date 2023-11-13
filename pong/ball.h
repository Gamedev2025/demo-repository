#pragma once

#include<SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include "math.h"
#include "GameEntity.h"
#include "TexturedRectangle.h"
using namespace std;

class ball:public GameEntity
{
    public:
    //constructor
    ball(SDL_Renderer* renderer , string path);
    //destructor
    ~ball();


    


    private:
    
}