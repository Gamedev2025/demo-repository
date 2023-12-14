


#include "game.hpp"


#include<SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

#include "TexturedRectangle.hpp"
#include "splashSCreen.hpp"
#include "menu.hpp"
#include "player1.hpp"
#include "player2.hpp"
#include "field.hpp"

 TexturedRectangle menu_BackGround;
 TexturedRectangle after_menu;
 TexturedRectangle football;
 TexturedRectangle player1;
 TexturedRectangle player2;
 SDL_Renderer* renderer;
 int count = 0;
TTF_Font* font = TTF_OpenFont("./font/liberation.ttf" , 24);

int width = 1380;
 int height = 720;
 Gamestate currState = splashscreen;
 string filename;
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

    if(!after_menu.textureMedia(renderer , "./image/main.png"))
    {
        cout << "main not found" << endl;
    }

    if(!football.textureMedia(renderer , "./image/football_field_final.png"))
    {
        cout<< "footbatll field is not loaded" << endl;
        success = false;
    }

    if(!player1.textureMedia(renderer , "./image/player1.png"))
    {
        cout << "Player 1 is not loaded!" << endl;
        success = false;
    }

    if (!player2.textureMedia(renderer , "./image/player2.png"))
    {
        cout << "Player 2 is not loaded!" << endl;
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
   
    while(SDL_PollEvent(&event) != 0)
    {
        if (event.type == SDL_QUIT)
        {
            isGameRunning = false;
        }

        // if (event.type == SDL_KEYDOWN)
        // {
        //     if (event.key.keysym.sym == SDLK_ESCAPE)
        //     {
        //         isGameRunning = false;
        //     }

        //     //frameNumber = 0;

            
        // }
         
        switch (currState)
        {
        case main_menu : menu::handleEvent_menu(event); break;
        case splashscreen: Splash::handleEvent_splashScreen(event); break;
        case Football_Field: field::handleEvent_field(event); break;
        case Player1 : play1::handleEvent_menu(event);break;
       case Player2 : shift :: handleEvent_menu(event);break;
        
        }
        
        //Splash::handle_splashScreen();
        

        

    }

    switch (currState)
        {
        case main_menu : menu::handle_menu(); break;
        case splashscreen: Splash::handle_splashScreen(); break;
        case Football_Field: field::handle_field();break;
        case Player1 : play1::handle_menu();break;
        case Player2 : shift:: handle_menu();break;
         
        case Exit: isGameRunning = false;
            
        
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

