


#include "game.hpp"


#include<SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

#include "TexturedRectangle.hpp"
#include "splashSCreen.hpp"

 TexturedRectangle menu_BackGround;
 SDL_Renderer* renderer;
TTF_Font* font = TTF_OpenFont("./font/liberation.ttf" , 24);

int width = 1200;
 int height = 720;
 Gamestate currState = splashscreen;
//currState = splashscreen;
    // SDL_Surface* tile = IMG_Load("image/football-3.png") ;
    // SDL_Texture* texture ;
Game::Game()
{
    //This where we initialize everything
    if((SDL_Init(SDL_INIT_VIDEO|SDL_INIT_AUDIO | TTF_Init())==-1)) { 
        printf("Could not initialize SDL: %s.\n", SDL_GetError());
        exit(-1);
    }
   
     SDL_CreateWindowAndRenderer( width , height , 0 , &window , &renderer);
     SDL_SetWindowTitle(window , "First game!!");
     isGameRunning = true;
     font ;
    


    

     loadMedia();
     loop();
}

Game::~Game()
{
    //Freeing all the allocated part
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    menu_BackGround.~TexturedRectangle();
   TTF_CloseFont(font);

    //SDL_DestroyTexture(texture);
    SDL_Quit();
}

bool Game::loadMedia()
{
    
    if (!menu_BackGround.textureMedia(renderer , "./image/main_menu.png"))
    {
        cout << "none png" <<endl;
        success = false;
        
    }
    return success;
}


void Game::loop()
{
    while(isGameRunning)
    {
        
        Uint32 button;
        button = SDL_GetMouseState(&m_mouseX,&m_mouseY);
             input();
               update();
            render();
           
          

        
    }
}

void Game::render()
{
    

    SDL_SetRenderDrawColor(renderer , 103, 117, 105, 0.66);
    SDL_Rect rect;
    rect.x = 0;
    rect.y = 0; 
    rect.w = width;
    rect.h = height;

    
    SDL_RenderFillRect(renderer, &rect);

   




    
    
    //SDL_RenderPresent(renderer);

    SDL_Delay(100);
}



void Game::input()
{
    SDL_Event event;
   
    while(SDL_PollEvent(&event))
    {
        
         
        switch (currState)
        {
        case splashscreen: Splash::handleEvent_splashScreen(event); break;
            /* code */
            
        
        default:
            break;
        }
        Splash::handle_splashScreen();
        if (event.type == SDL_QUIT)
        {
            isGameRunning = false;
        }

        if (event.type == SDL_KEYDOWN)
        {
            if (event.key.keysym.sym == SDLK_ESCAPE)
            {
                isGameRunning = false;
            }

            if (event.key.keysym.sym == SDLK_w) 
            {

                key_y--;
                c_y--;

                key_y++;
                c_y++;

                frameNumber++;
                if (frameNumber > 4)
                {
                frameNumber = 0;
                }
             
            }

            //frameNumber = 0;

            if (event.key.keysym.sym == SDLK_s) 
            {

                key_y++;
                c_y++;

                key_y--;
                c_y--;

                frameNumber++;
                if (frameNumber > 4)
                {
                    frameNumber = 0;
                }
               
            }

            //frameNumber = 0;
            if (event.key.keysym.sym == SDLK_a) 
            {
                key_x--;
                c_x--;
                frameNumber++;
                if (frameNumber > 4)
                {
                    frameNumber = 0;
                }
               
            }
            //frameNumber = 0;
            if (event.key.keysym.sym == SDLK_d) 
            {
                key_x++;
                c_x++;

                frameNumber++;
                if (frameNumber > 4)
                {
                    frameNumber = 0;
                }
              
            }
            //frameNumber = 0;
            if (key_x < 0) {
            key_x = 0;
        } else if (key_x > width- 100) {
            key_x = width - 100;
        }

        if (key_y < 0) {
            key_y = 0;
        } else if (key_y > height - 100) {
            key_y = height - 100;
        }
            
        }

    }
}


int Game::GetMouseX()
{
    return m_mouseX;
}

int Game::GetMouseY()
{
    return m_mouseY;
}


void Game::StopAppLoop()
{
   isGameRunning = false; 
};

