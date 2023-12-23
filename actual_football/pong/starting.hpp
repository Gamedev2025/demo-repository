#ifndef STARTING_HPP
#define STARTING_HPP


#include <string>

#include <SDL2/SDL.h> 
#include <SDL2/SDL_ttf.h>
#include <bits/stdc++.h>
#include "DynamicText.hpp"

using namespace std;


    
class starting
{

    public:
     
    starting()
    {

    }
     static void handleEvent_gameScreen(SDL_Event e);
    ~starting();
    
    static void handle_gameScreen();
    
    private:
   
    
    SDL_Renderer* m_renderer ;


}
;

#endif