#include "splashSCreen.hpp"
#include "TexturedRectangle.hpp"
#include "game.hpp"

extern TexturedRectangle menu_BackGround;
extern Gamestate currState;
extern SDL_Renderer* renderer;
extern int width ;
 extern int height;
DynamicText* object;
 Splash::~Splash()
    {
        
    }
 

void Splash::handleEvent_splashScreen(SDL_Event e)
{
    int x , y;


    
}

void Splash::handle_splashScreen()
{
    object = new DynamicText("./font/liberation.ttf" , 24);
    
     menu_BackGround.SetPosition(0 ,0 , width , height);
     menu_BackGround.playFrame(0 ,0 , width , height , 0);
    
    menu_BackGround.Render(renderer);
    object->DrawText(renderer , "Press Enter to proceed" , 500 , 800 , 500 , 200);
    SDL_RenderPresent(renderer);
    
}