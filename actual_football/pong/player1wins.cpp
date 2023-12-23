#include "player1wins.hpp"
#include "TexturedRectangle.hpp"
#include "game.hpp"

extern TexturedRectangle wins1;
extern Gamestate currState;
extern SDL_Renderer* renderer;
extern bool isGameRunning ;
extern int width ;
 extern int height;
//DynamicText* object;
 player1wins::~player1wins()
    {
        
    }
 

void player1wins::handleEvent_menu(SDL_Event e)
{
    int x , y;
    SDL_GetMouseState(&x , &y);
    cout << x << " " << y << endl;
    //bool running = true;
    //SDL_Event e;
    
        if(e.type == SDL_MOUSEBUTTONDOWN)
        {
        
            if(x >= 840 && x <= 1160 && y >= 384  && y <= 474)
            {
                
                cout << "Play Now" << endl;
                currState = main_menu;
            }


            //  if(x >= 1030 && x <= 1258 && y >= 500 && y <= 562)
            // {
                
            //     cout << "Exit" << endl;
            //     currState = Exit;
                
            // }

           

      }
    
    

    
}

void player1wins::handle_menu()
{
    //object = new DynamicText("./font/RobotoSlab-Bold.ttf" , 24);
    
     wins1.SetPosition(0 ,0 , width , height);
     //after_menu.playFrame(0 ,0 , width , height , 0);
    
    wins1.Render(renderer);
    //object->DrawText(renderer , "Press w to proceed" , 300 , 500 , 700 , 100);
    SDL_RenderPresent(renderer);
    
}