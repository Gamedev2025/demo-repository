#ifndef SPLASHSCRENN_HPP
#define SPLASHSCRENN_HPP


#include <string>

#include <SDL2/SDL.h> 
#include <SDL2/SDL_ttf.h>
#include <bits/stdc++.h>
#include "DynamicText.hpp"

using namespace std;


    
class Splash
{

    public:
     
    Splash()
    {

    }
     static void handleEvent_splashScreen(SDL_Event e);
    ~Splash();
    
    static void handle_splashScreen();
    
    private:
   
    
    SDL_Renderer* m_renderer ;


}
;

#endif