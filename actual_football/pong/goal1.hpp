#ifndef GOAL1_HPP
#define GOAL1_HPP


#include <string>

#include <SDL2/SDL.h> 
#include <SDL2/SDL_ttf.h>
#include <bits/stdc++.h>
#include "DynamicText.hpp"

using namespace std;


    
class goal1
{

    public:
     
    goal1()
    {

    }
     static void handleEvent_goal1Screen(SDL_Event e);
    ~goal1();
    
    static void handle_goal1Screen();
    
    private:
   
    
    SDL_Renderer* m_renderer ;


}
;

#endif