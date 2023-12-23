#include "pausemenu.hpp"
#include "TexturedRectangle.hpp"
#include "game.hpp"

extern TexturedRectangle resume;
extern Gamestate currState;
extern SDL_Renderer* renderer;
extern bool isGameRunning ;
extern int width ;
 extern int height;
//DynamicText* object;
 pausemenu::~pausemenu()
    {
        
    }
 

void pausemenu::handleEvent_menu(SDL_Event e)
{
    int x , y;
    SDL_GetMouseState(&x , &y);
    cout << x << " " << y << endl;
    //bool running = true;
    //SDL_Event e;
    
        if(e.type == SDL_MOUSEBUTTONDOWN)
        {
        
            if(x >= 1050 && x <= 1272 && y >= 367  && y <= 437)
            {
                
                cout << "Play Now" << endl;
                currState = Football_Field;
            }


             if(x >= 1050 && x <= 1272 && y >= 453 && y <= 517)
            {
                
                cout << "Exit" << endl;
                currState = main_menu;
                
            }

            if(x >= 1050 && x <= 1272 && y>=530  && y<= 598)
            {
                currState = Exit;
            }

      }
    
    

    
}

void pausemenu::handle_menu()
{
    //object = new DynamicText("./font/RobotoSlab-Bold.ttf" , 24);
    
     resume.SetPosition(0 ,0 , width , height);
     //after_menu.playFrame(0 ,0 , width , height , 0);
    
    resume.Render(renderer);
    //object->DrawText(renderer , "Press w to proceed" , 300 , 500 , 700 , 100);
    SDL_RenderPresent(renderer);
    
}