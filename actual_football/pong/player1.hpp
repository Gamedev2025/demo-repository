#ifndef PLAYER1_HPP
#define PLAYER1_HPP


#include <string>

#include <SDL2/SDL.h> 
#include <SDL2/SDL_ttf.h>
#include <bits/stdc++.h>
#include "DynamicText.hpp"

using namespace std;


    
class play1
{

    public:
     
    play1()
    {

    }
    static int handleEvent_menu(SDL_Event e);
    ~play1();
    
    static void handle_menu();
    
    private:
   
    
    SDL_Renderer* m_renderer ;
    //static int count;


}
;

#endif