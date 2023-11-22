#ifndef FIELD_HPP
#define FIELD_HPP


#include <string>

#include <SDL2/SDL.h> 
#include <SDL2/SDL_ttf.h>
#include <bits/stdc++.h>
#include "DynamicText.hpp"
//Gamestate currState;

using namespace std;


    
class field
{

    public:
     
    field()
    {

    }
    static void handleEvent_field(SDL_Event e);
    ~field();
    
    static void handle_field();
    
    private:
   
    
    SDL_Renderer* m_renderer ;


}
;

#endif