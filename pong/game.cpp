


#include "game.hpp"


#include<SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include "GameEntity.hpp"




#define width 640
#define height 480


    SDL_Surface* tile = IMG_Load("image/football-3.png") ;
    SDL_Texture* texture ;
Game::Game()
{
    //This where we initialize everything
    if((SDL_Init(SDL_INIT_VIDEO|SDL_INIT_AUDIO)==-1)) { 
        printf("Could not initialize SDL: %s.\n", SDL_GetError());
        exit(-1);
    }
   
     SDL_CreateWindowAndRenderer( width , height , 0 , &window , &renderer);
     SDL_SetWindowTitle(window , "First game!!");
     isGameRunning = true;
     
    


    texture = SDL_CreateTextureFromSurface(renderer , tile);

 
     loop();
}

Game::~Game()
{
    //Freeing all the allocated part
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);

   // TTF_CloseFont(font);

    SDL_FreeSurface(tile);
    SDL_DestroyTexture(texture);
    SDL_Quit();
}
void Game::loop()
{
    while(isGameRunning)
    {
        
        Uint32 button;
        button = SDL_GetMouseState(&m_mouseX,&m_mouseY);
        
            render();
            input();
            update();

        
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






   
    SDL_RenderPresent(renderer);

    SDL_Delay(100);
}



void Game::input()
{
    SDL_Event event;

    while(SDL_PollEvent(&event))
    {
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

