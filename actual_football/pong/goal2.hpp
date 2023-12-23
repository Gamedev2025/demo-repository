#ifndef GOAL2_HPP
#define GOAL2_HPP


#include <string>

#include <SDL2/SDL.h> 
#include <SDL2/SDL_ttf.h>
#include <bits/stdc++.h>
#include "DynamicText.hpp"

using namespace std;


    
class goal2
{

    public:
     
    goal2()
    {

    }
     static void handleEvent_goal2Screen(SDL_Event e);
    ~goal2();
    
    static void handle_goal2Screen();
    
    private:
   
    
    SDL_Renderer* m_renderer ;


}
;

#endif