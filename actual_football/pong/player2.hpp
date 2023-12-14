#ifndef PLAYER2_HPP
#define PLAYER2_HPP


#include <string>

#include <SDL2/SDL.h> 
#include <SDL2/SDL_ttf.h>
#include <bits/stdc++.h>
#include "DynamicText.hpp"

using namespace std;


    
class shift
{

    public:
     
    shift()
    {

    }
    static int handleEvent_menu(SDL_Event e);
    ~shift();
    
    static void handle_menu();
    
    private:
   
    
    SDL_Renderer* m_renderer ;
    //static int count;


}
;

#endif