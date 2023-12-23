#ifndef PLAYER1WINS_HPP
#define PLAYER1WINS_HPP


#include <string>

#include <SDL2/SDL.h> 
#include <SDL2/SDL_ttf.h>
#include <bits/stdc++.h>
#include "DynamicText.hpp"

using namespace std;


    
class player1wins
{

    public:
     
    player1wins()
    {

    }
    static void handleEvent_menu(SDL_Event e);
    ~player1wins();
    
    static void handle_menu();
    
    private:
   
    
    SDL_Renderer* m_renderer ;


}
;

#endif