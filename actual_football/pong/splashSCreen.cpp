#include "splashSCreen.hpp"
#include "TexturedRectangle.hpp"
#include "game.hpp"

extern TexturedRectangle menu_BackGround;
extern Gamestate currState;
extern SDL_Renderer* renderer;
extern bool isGameRunning ;
extern int width ;
 extern int height;
DynamicText* object;
 Splash::~Splash()
    {
        
    }
 

void Splash::handleEvent_splashScreen(SDL_Event e)
{
    int x , y;
    bool running = true;
    //SDL_Event e;
    
        if(e.type == SDL_KEYDOWN)
        {
        
            if(e.key.keysym.sym == SDLK_KP_ENTER || e.key.keysym.sym == SDLK_w)
            {
                
                cout << "main menu" << endl;
                currState = main_menu;
            }

      }
    
    

    
}

void Splash::handle_splashScreen()
{
    object = new DynamicText("./font/RobotoSlab-Bold.ttf" , 24);
    
     menu_BackGround.SetPosition(0 ,0 , width , height);
     menu_BackGround.playFrame(0 ,0 , width , height , 0);
    
    menu_BackGround.Render(renderer);
    object->DrawText(renderer , "Press w to proceed" , 300 , 500 , 700 , 100);
    SDL_RenderPresent(renderer);
    
}