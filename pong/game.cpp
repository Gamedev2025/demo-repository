<<<<<<< HEAD
#include "game.h"
=======
#include "game.hpp"
>>>>>>> c9054ba8344bbf8fd2749b8a04d7902754da456a

#include<SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
<<<<<<< HEAD
// GameEntity* object1;
// GameEntity* object2;
// GameEntity* object3;
// //tile* object4;
// GameEntity* object4;
GameEntity* object5;//For football


    int width = 1920;
    int height = 1080;
=======

#define width 640
#define height 480



>>>>>>> c9054ba8344bbf8fd2749b8a04d7902754da456a
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
     
    
<<<<<<< HEAD
    // object1 = new GameEntity(renderer,"./image/square_barrel.png");
    // object2 = new GameEntity(renderer,"./image/square_barrel.png");
    // object3 = new GameEntity(renderer , "image/walking_cycle.png");
    //object4 = new GameEntity(renderer , "./image/football_field2.png");
     object5 = new GameEntity(renderer , "./image/volley-ball.png");
     tile ;
    texture = SDL_CreateTextureFromSurface(renderer , tile);
=======
 
    //object4 = new GameEntity(renderer , "./image/football_field2.png");

>>>>>>> c9054ba8344bbf8fd2749b8a04d7902754da456a
     loop();
}

Game::~Game()
{
    //Freeing all the allocated part
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
<<<<<<< HEAD
=======
    TTF_CloseFont(font);
>>>>>>> c9054ba8344bbf8fd2749b8a04d7902754da456a
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
<<<<<<< HEAD
   // TexturedRectangle rectangle(renderer , "./image/square_barrel.png");
    
    //object4->GetTexturedRectangle().SetPosition(300 , 300 ,100 , 100);
   
    // object1->GetTexturedRectangle().SetPosition(key_x , key_y , 100 , 100);
    // object2->GetTexturedRectangle().SetPosition(300 , 300 , 100 , 100);
    //object5 -> GetTexturedRectangle().SetPosition(300 , 300, 100 , 100);
    object5 -> GetTexturedRectangle().draw(c_x , c_y , 50 , 50);
    object5 -> GetTexturedRectangle().playFrame(0 , 0 , 1122 , 1122 , 0);
    object5 -> GetTexturedRectangle().updateAnimation(renderer);
    //object5 -> Render();
    // object3->GetTexturedRectangle().draw(c_x , c_y , 125 , 125);
    // object3->GetTexturedRectangle().playFrame(66 , 84 , 154 , 124 , frameNumber);
    // object3->GetTexturedRectangle().updateAnimation(renderer);
    // object1->Render();
    // object2->Render();
    int tile[40][60];



    // for (int x = 0 ; x < 40 ; x++)
    // {
    //     for (int y = 0 ; y < 60 ; y++)
    //     {
    //         Tile_Sets[x][y].x = x*32;
    //         Tile_Sets[x][y].y = y*32;
    //         Tile_Sets[x][y].w = 32;
    //         Tile_Sets[x][y].h = 32;

             
            
    //              SDL_RenderCopy(renderer , texture , &Tile_Sets[x][y] , &Tile_Sets[x][y]);
              

    //     }
    // }
=======

    
    //object4->GetTexturedRectangle().SetPosition(300 , 300 ,100 , 100);




>>>>>>> c9054ba8344bbf8fd2749b8a04d7902754da456a
    //  character.playFrame(66 , 84 , 154 , 124 , frameNumber);
    //  character.updateAnimation(renderer);
   
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
<<<<<<< HEAD
                key_y--;
                c_y--;
=======
                key_y++;
                c_y++;
>>>>>>> c9054ba8344bbf8fd2749b8a04d7902754da456a
                frameNumber++;
                if (frameNumber > 4)
                {
                frameNumber = 0;
                }
             
            }

            //frameNumber = 0;

            if (event.key.keysym.sym == SDLK_s) 
            {
<<<<<<< HEAD
                key_y++;
                c_y++;
=======
                key_y--;
                c_y--;
>>>>>>> c9054ba8344bbf8fd2749b8a04d7902754da456a
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

<<<<<<< HEAD
        // if(event.button.button == SDL_BUTTON_LEFT)
        // {
        //    if(object2->GetTexturedRectangle().IsColliding(object1->GetTexturedRectangle()))
        //    {
        //         std::cout << "Is colliding" << std::endl;
        //    }else
        //    {
        //        std::cout << "Not colliding" << std::endl;
        //    }
        // }
=======
>>>>>>> c9054ba8344bbf8fd2749b8a04d7902754da456a
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

