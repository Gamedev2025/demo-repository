#include "goal1.hpp"
#include "TexturedRectangle.hpp"
#include "game.hpp"

extern TexturedRectangle point1;
extern Gamestate currState;
extern SDL_Renderer* renderer;
extern bool isGameRunning ;
extern int width ;
extern int height;

 goal1::~goal1()
    {
        
    }
 

void goal1::handleEvent_goal1Screen(SDL_Event e)
{
    int x , y;
    bool running = true;
    //SDL_Event e;
    
        if(e.type == SDL_KEYDOWN)
        {
        
            if(e.key.keysym.sym == SDLK_KP_ENTER || e.key.keysym.sym == SDLK_w)
            {
                
                cout << "main menu" << endl;
                currState = Football_Field;
            }

      }
    
    

    
}

void goal1::handle_goal1Screen()
{
    //object = new DynamicText("./font/RobotoSlab-Bold.ttf" , 24);
    
     point1.SetPosition(0 ,0 , width , height);
    point1.playFrame(0 ,0 , width , height , 0);
    
    point1.Render(renderer);
    //object->DrawText(renderer , "Press w to proceed" , 300 , 500 , 700 , 100);
    SDL_RenderPresent(renderer);
    
}