#include "starting.hpp"
#include "TexturedRectangle.hpp"
#include "game.hpp"

extern TexturedRectangle gamescreen;
extern Gamestate currState;
extern SDL_Renderer* renderer;
extern bool isGameRunning ;
extern int width ;
extern int height;
//DynamicText* object;
 starting::~starting()
    {
        
    }
 

void starting::handleEvent_gameScreen(SDL_Event e)
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

void starting::handle_gameScreen()
{
    //object = new DynamicText("./font/RobotoSlab-Bold.ttf" , 24);
    
        gamescreen.SetPosition(0 , 0 , width , height);
     gamescreen.playFrame(0 ,0 , width , height , 0);
    gamescreen.Render(renderer);
    // menu_BackGround.Render(renderer);
    // object->DrawText(renderer , "Press w to proceed" , 300 , 500 , 700 , 100);
    SDL_RenderPresent(renderer);
    
}