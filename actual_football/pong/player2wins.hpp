#ifndef PLAYER2WINS_HPP
#define PLAYER2WINS_HPP


#include <string>

#include <SDL2/SDL.h> 
#include <SDL2/SDL_ttf.h>
#include <bits/stdc++.h>
#include "DynamicText.hpp"

using namespace std;


    
class player2wins
{

    public:
     
    player2wins()
    {

    }
    static void handleEvent_menu(SDL_Event e);
    ~player2wins();
    
    static void handle_menu();
    
    private:
   
    
    SDL_Renderer* m_renderer ;


}
;

#endif