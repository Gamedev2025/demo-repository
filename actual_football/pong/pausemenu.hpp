#ifndef PAUSEMENU_HPP
#define PAUSEMENU_HPP


#include <string>

#include <SDL2/SDL.h> 
#include <SDL2/SDL_ttf.h>
#include <bits/stdc++.h>
#include "DynamicText.hpp"

using namespace std;


    
class pausemenu
{

    public:
     
    pausemenu()
    {

    }
    static void handleEvent_menu(SDL_Event e);
    ~pausemenu();
    
    static void handle_menu();
    
    private:
   
    
    SDL_Renderer* m_renderer ;


}
;

#endif