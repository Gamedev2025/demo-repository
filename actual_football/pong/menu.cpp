#include "menu.hpp"
#include "TexturedRectangle.hpp"
#include "game.hpp"

extern TexturedRectangle after_menu;
extern Gamestate currState;
extern SDL_Renderer* renderer;
extern bool isGameRunning ;
extern int width ;
 extern int height;
//DynamicText* object;
 menu::~menu()
    {
        
    }
 

void menu::handleEvent_menu(SDL_Event e)
{
    int x , y;
    SDL_GetMouseState(&x , &y);
    cout << x << " " << y << endl;
    //bool running = true;
    //SDL_Event e;
    
        if(e.type == SDL_MOUSEBUTTONDOWN)
        {
        
            if(x >= 900 && x <= 1096 && y >= 396 && y <= 455)
            {
                
                cout << "Play Now" << endl;
                currState = Football_Field;
            }


             if(x >= 900 && x <= 1096 && y >= 501 && y <= 555)
            {
                
                cout << "Exit" << endl;
                currState = Exit;
                
            }

      }
    
    

    
}

void menu::handle_menu()
{
    //object = new DynamicText("./font/RobotoSlab-Bold.ttf" , 24);
    
     after_menu.SetPosition(0 ,0 , width , height);
     //after_menu.playFrame(0 ,0 , width , height , 0);
    
    after_menu.Render(renderer);
    //object->DrawText(renderer , "Press w to proceed" , 300 , 500 , 700 , 100);
    SDL_RenderPresent(renderer);
    
}