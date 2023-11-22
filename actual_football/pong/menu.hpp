#ifndef MENU_HPP
#define MENU_HPP


#include <string>

#include <SDL2/SDL.h> 
#include <SDL2/SDL_ttf.h>
#include <bits/stdc++.h>
#include "DynamicText.hpp"

using namespace std;


    
class menu
{

    public:
     
    menu()
    {

    }
    static void handleEvent_menu(SDL_Event e);
    ~menu();
    
    static void handle_menu();
    
    private:
   
    
    SDL_Renderer* m_renderer ;


}
;

#endif