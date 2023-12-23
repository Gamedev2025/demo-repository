#include "goal2.hpp"
#include "TexturedRectangle.hpp"
#include "game.hpp"

extern TexturedRectangle point2;
extern Gamestate currState;
extern SDL_Renderer* renderer;
extern bool isGameRunning ;
extern int width ;
extern int height;

 goal2::~goal2()
    {
        
    }
 

void goal2::handleEvent_goal2Screen(SDL_Event e)
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

void goal2::handle_goal2Screen()
{
    //object = new DynamicText("./font/RobotoSlab-Bold.ttf" , 24);
    
     point2.SetPosition(0 ,0 , width , height);
    point2.playFrame(0 ,0 , width , height , 0);
    
    point2.Render(renderer);
    //object->DrawText(renderer , "Press w to proceed" , 300 , 500 , 700 , 100);
    SDL_RenderPresent(renderer);
    
}